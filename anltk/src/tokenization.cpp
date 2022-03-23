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

		if (is_arabic_alpha(next) || is_tashkeel(next) || next == TATWEEL)
		{
			result.push_back(parse_sequence(
			    next, start, end, done,
			    [](char_t c) { return is_arabic_alpha(c) || is_tashkeel(c) || c == TATWEEL; }));
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
	if (input.empty())
	{
		return {};
	}

	if (funcs.empty())
	{
		return { { -1, std::string(input.begin(), input.end()) } };
	}

	auto start = input.begin();
	auto end   = input.end();

	std::vector<std::pair<int, std::string>> result;

	const size_t funcs_len = funcs.size(); // Does the compiler optimize this?

	auto get_nth_match = [&funcs, &funcs_len](char_t c) -> int
	{
		for (size_t i = 0; i < funcs_len; ++i)
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
		int func_idx = get_nth_match(next);
		bool done    = false;
		if (func_idx == -1)
		{
			std::string seq = parse_sequence(next, start, end, done,
			                                 [&get_nth_match](char_t c) -> bool
			                                 { return get_nth_match(c) == -1; });
			result.push_back({ -1, seq });
		}
		else
		{
			const auto& func = funcs[func_idx];

			std::string seq = parse_sequence(next, start, end, done,
			                                 [&func](char_t c) -> bool { return func(c); });

			result.push_back({ func_idx, seq });
		}
		if (done)
		{
			string_t last;
			utf8::append(next, last);
			func_idx = get_nth_match(next);
			result.push_back({ func_idx, last });
		}
	}
	return result;
}

} // namespace anltk
