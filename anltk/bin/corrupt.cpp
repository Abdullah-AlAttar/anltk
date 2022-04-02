#include <anltk/anltk.hpp>
#include <fstream>
#include <ostream>

int main(int argc, char* argv[])
{

	std::ifstream ifs(argv[1]);
	std::string line;
	std::ofstream ofs(argv[2]);

	anltk::NoiseGenerator n_gen;
	while (std::getline(ifs, line))
	{
		std::string corrupted = anltk::remove_tashkeel(line);
		corrupted = n_gen.swap_adjacent_chars(corrupted, 5);
		corrupted = n_gen.insert_random_chars(corrupted, 5);
		corrupted = n_gen.remove_random_chars(corrupted, 5);
		corrupted = n_gen.replace_random_chars(corrupted,5);
		ofs << corrupted << '\n';
	}
}