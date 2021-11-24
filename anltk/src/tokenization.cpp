#include "utf8.h"
#include <anltk/anltk.hpp>
#include <anltk/anltk_algorithm.h>
namespace anltk
{



vector_t<string_t> tokenize_words(string_view_t input)
{
	vector_t<string_t> result;
	if (input.empty())
	{
		return result;
	}

	auto start = input.begin();
	auto end   = input.end();

	char_t next = utf8::next(start, end);
	bool done   = false;

	while (start != end)
	{

		if (isspace(static_cast<char>(next)))
		{
			next = utf8::next(start, end);
			continue;
		}

		if (is_arabic_alpha(next) || is_tashkeel(next) || is_TATWEEL(next))
		{
			result.push_back(parse_sequence(
			    next, start, end, done,
			    [](char_t c) { return is_arabic_alpha(c) || is_tashkeel(c) || is_TATWEEL(c); }));
		}
		else
		{
			result.push_back(parse_sequence(
			    next, start, end, done,
			    [](char_t c) { return !is_arabic_alpha(c) && !isspace(static_cast<char>(c)); }));
		}
		// To handle last character, if it didn't belong to the previous sequence eg : "بسم."
		if (done)
		{
			string_t last;
			utf8::append(next, last);
			result.push_back(std::move(last));
		}
	}

	return result;
}


std::vector<std::pair<int, std::string>>
tokenize_if(string_view_t input, const std::vector<std::function<bool(char_t)>>& funcs)
{
	auto start = input.begin();
	auto end   = input.end();
	std::vector<std::pair<int, std::string>> result;

	auto get_nth_match = [&funcs](char_t c)
	{
		for (size_t i = 0; i < funcs.size(); ++i)
		{
			if (funcs[i](c))
			{
				return static_cast<int>(i);
			}
		}
		return -1;
	};

	char_t next = utf8::next(start, end);

	while (start < end)
	{
		int func_match = get_nth_match(next);
		bool done      = false;
		if (func_match == -1)
		{
			// std::cout << "next \"" << utf8::utf32to8(std::u32string{ next }) << '"' << std::endl;
			std::string sequence = parse_sequence(next, start, end, done,
			                                      [&](char_t c) { return get_nth_match(c) == -1; });
			// std::cout << "Seq " << sequence << std::endl;
			result.push_back({ -1, sequence });
		}
		else
		{
			const auto& func = funcs[func_match];
			std::string sequence
			    = parse_sequence(next, start, end, done, [&](char_t c) { return func(c); });

			// std::cout << "Seq " << sequence << std::endl;
			result.push_back({ func_match, sequence });
		}
		if (done)
		{
			string_t last;
			utf8::append(next, last);
			func_match = get_nth_match(next);

			result.push_back({ func_match, last });
		}
	}
	return result;
}

} // namespace anltk
