#include <anltk/anltk.hpp>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <taskflow/taskflow.hpp>

namespace fs = std::filesystem;

std::string pipeline(std::string line)
{
	line = anltk::remove_tashkeel(line);
	return line;
}

void process_file(const fs::path& filepath)
{
	std::ifstream ifs(filepath);

	std::ofstream ofs((filepath.parent_path() / filepath.stem()).string() + "_clean"
	                  + filepath.extension().string());

	std::string line;

	while (std::getline(ifs, line))
	{
		line = pipeline(line);
		ofs << line << '\n';
	}
}

int main(int argc, char** argv)
{
	tf::Executor executor;
	tf::Taskflow taskflow;
	std::vector<fs::path> files;

	for (int i = 1; i < argc; ++i)
	{
		files.push_back(argv[i]);
	}

	taskflow.for_each(files.begin(), files.end(),
	                  [](const fs::path& filename) { process_file(filename); });

	executor.run(taskflow).get();

	return 0;
}