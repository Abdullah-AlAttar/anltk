#include <anltk/anltk.hpp>
#include <iostream>
#include <utf8.h>

int main(int argc, char const* argv[])
{

	std::string input;
	std::cin >> input;
	if (utf8::is_valid(input))
	{
		auto res = anltk::remove_tashkeel(input);
		res = anltk::transliterate(input, anltk::CharMapping::AR2BW);
		res = anltk::transliterate(input, anltk::CharMapping::BW2AR);
		res = anltk::transliterate(input, anltk::CharMapping::AR2SBW);
		res = anltk::transliterate(input, anltk::CharMapping::SBW2AR);
		res = anltk::remove_small(input);
		res = anltk::remove_non_alpha(input, " ");
		res = anltk::remove_non_alpha_and_tashkeel(input, " ");
		res = anltk::remove_non_alphanumeric(input, " ");
		res = anltk::remove_non_alphanumeric_and_tashkeel(input, " ");
		res = anltk::remove_kasheeda(input);
		res = anltk::normalize_to_teh(input);
		res = anltk::duplicate_shadda_letter(input);
		res = anltk::normalize_to_heh(input);
		res = anltk::fold_white_spaces(input);
		auto words = anltk::tokenize_words(input);
		words = anltk::split(input);
	}

	return 0;
}
