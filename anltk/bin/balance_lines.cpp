#include <argparse/argparse.hpp>

#include <anltk/anltk.hpp>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <ostream>

#include <stack>
#include <taskflow/taskflow.hpp>

namespace fs = std::filesystem;

struct Options
{
	int min_words_per_line         = 5;
	int max_words_per_line         = 10;
	int n_threads                  = std::round(std::thread::hardware_concurrency() * 0.7);
	std::string output_directory   = "out";
	std::string output_file_prefix = "batch_";
	std::string output_file_suffix = ".txt";

	std::vector<std::string> files;

	friend std::ostream& operator<<(std::ostream& os, const Options& opts)
	{
		os << "Options: \n";
		os << "\tmin_words_per_line = " << opts.min_words_per_line << '\n';
		os << "\tmax_words_per_line = " << opts.max_words_per_line << '\n';
		os << "\tn_threads = " << opts.n_threads << '\n';
		os << "\toutput_directory = " << opts.output_directory << '\n';
		os << "\toutput_file_prefix = " << opts.output_file_prefix << '\n';
		os << "\toutput_file_suffix = " << opts.output_file_suffix << '\n';
		os << "    " << opts.files.size() << " files provided" << std::endl;
		os << '\t';
		for (auto& file : opts.files)
			os << file << ", ";
		os << std::endl;
		return os;
	}
};
static Options opts;

void parse_args(int argc, char* argv[])
{
	argparse::ArgumentParser program("balance_lines");

	program.add_argument("--min_words_per_line")
	    .default_value(opts.min_words_per_line)
	    .scan<'i', int>();
	program.add_argument("--max_words_per_line")
	    .default_value(opts.max_words_per_line)
	    .scan<'i', int>();
	program.add_argument("--n_threads").default_value(opts.n_threads).scan<'i', int>();
	program.add_argument("--output_directory").default_value(opts.output_directory);
	program.add_argument("--output_file_prefix").default_value(opts.output_file_prefix);
	program.add_argument("--output_file_suffix").default_value(opts.output_file_suffix);

	program.add_argument("files").remaining().default_value<std::vector<std::string>>({});

	try
	{
		program.parse_args(argc, argv);
		opts.min_words_per_line = program.get<int>("--min_words_per_line");
		opts.max_words_per_line = program.get<int>("--max_words_per_line");
		opts.n_threads          = program.get<int>("--n_threads");
		opts.files              = program.get<std::vector<std::string>>("files");
		opts.output_directory   = program.get<std::string>("--output_directory");
		opts.output_file_prefix = program.get<std::string>("--output_file_prefix");
		opts.output_file_suffix = program.get<std::string>("--output_file_suffix");

		std::cout << opts << std::endl;
	}
	catch (const std::runtime_error& err)
	{
		std::cerr << err.what() << std::endl;
		std::cerr << program;
		std::exit(1);
	}
}

void flush_lines(std::ostream& os, std::stack<std::string>& lines)
{

	while (!lines.empty())
	{
		os << lines.top() << '\n';
		lines.pop();
	}
}

void process_file(const std::string& filepath_)
{
	fs::path filepath(filepath_);

	std::ifstream ifs(filepath.c_str());
	fs::path outdir_path = fs::path(opts.output_directory);

	if (!ifs.is_open())
	{
		std::cerr << "Unable to open file " << filepath << ". Skipping.\n";
	}
	std::stack<std::string> lines;
	std::string line;

	fs::path outfile_path = outdir_path
	    / (opts.output_file_prefix + filepath.stem().string() + opts.output_file_suffix);
	std::ofstream ofs(outfile_path.c_str());

	while (std::getline(ifs, line))
	{
		for (auto&& l : anltk::split_on(line, ",.\"،؟?:", opts.max_words_per_line))
		{
			if (lines.empty())
			{
				lines.emplace(l);
				continue;
			}
			int lwc    = std::count(l.begin(), l.end(), ' ');
			auto& prev = lines.top();
			int bwc    = std::count(prev.begin(), prev.end(), ' ');
			if ((lwc + bwc) < (opts.max_words_per_line + opts.min_words_per_line))
			{
				// std::cout << lines.top() <<std::endl;
				prev += " " + l;
				// std::cout << lines.top() <<std::endl<<std::endl;
			}
			else
			{
				lines.emplace(l);
				flush_lines(ofs, lines);
			}
		}
	}
}

int main(int argc, char* argv[])
{
	parse_args(argc, argv);

	fs::path outdir_path = fs::path(opts.output_directory);

	if (!fs::exists(outdir_path))
	{
		std::cout << "Output directory doesn't exist, creating one\n";
		fs::create_directories(outdir_path);
	}

	tf::Executor executor(opts.n_threads);
	tf::Taskflow taskflow;
	std::cout << "n worder " << executor.num_workers() << std::endl;
	taskflow.for_each(opts.files.begin(), opts.files.end(),
	                  [](const std::string& filename) { process_file(filename); });

	executor.run(taskflow).get();
	return 0;
}