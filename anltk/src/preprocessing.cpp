#include "anltk/anltk.hpp"
#include "anltk/anltk_algorithm.h"

#include <algorithm>
#include <vector>

namespace anltk
{

string_t remove_tashkeel(string_view_t input)
{
	return anltk_erase_if(input, [](char_t c) { return anltk::is_tashkeel(c); });
}

string_t remove_small(string_view_t input)
{
	return anltk_erase_if(input, [](char_t c) { return anltk::is_small(c); });
}

string_t remove_non_alpha(string_view_t input, string_view_t stop_list)
{
	std::u32string stop_list_ = to_32string(stop_list);

	return anltk_erase_if(input,
	                      [&](char_t c)
	                      {
		                      return !anltk::is_arabic_alpha(c)
		                          && std::find(stop_list_.begin(), stop_list_.end(), c)
		                          == stop_list_.end();
	                      });
}
std::string remove_non_alpha_and_tashkeel(string_view_t input, string_view_t stop_list)
{
	std::u32string stop_list_ = to_32string(stop_list);

	return anltk_erase_if(input,
	                      [&](char_t c)
	                      {
		                      return std::find(stop_list_.begin(), stop_list_.end(), c)
		                          == stop_list_.end()
		                          && !anltk::is_arabic_alpha(c) && !anltk::is_tashkeel(c);
	                      });
}
string_t remove_non_alphanumeric(string_view_t input, string_view_t stop_list)
{

	std::u32string stop_list_ = to_32string(stop_list);

	return anltk_erase_if(input,
	                      [&](char_t c)
	                      {
		                      return std::find(stop_list_.begin(), stop_list_.end(), c)
		                          == stop_list_.end()
		                          && !anltk::is_arabic_alpha(c) && !anltk::is_indic_digit(c)
		                          && !anltk::is_digit(c);
	                      });
}

string_t remove_non_alphanumeric_and_tashkeel(string_view_t input, string_view_t stop_list)
{

	std::u32string stop_list_ = to_32string(stop_list);

	return anltk_erase_if(input,
	                      [&](char_t c)
	                      {
		                      return std::find(stop_list_.begin(), stop_list_.end(), c)
		                          == stop_list_.end()
		                          && !anltk::is_arabic_alpha(c) && !anltk::is_indic_digit(c)
		                          && !anltk::is_tashkeel(c) && !std::isdigit(c);
	                      });
}

string_t remove_kasheeda(string_view_t input)
{
	return anltk_erase_if(input, [](char_t c) { return c == TATWEEL; });
}

string_t remove_if(string_view_t input, string_view_t stop_list,
                   const std::function<bool(char_t)>& func)
{
	std::u32string stop_list_ = to_32string(stop_list);

	return anltk_erase_if(input,
	                      [&](char_t c) {
		                      return std::find(stop_list_.begin(), stop_list_.end(), c)
		                          == stop_list_.end()
		                          && func(c);
	                      });
}

string_t normalize_hamzat(string_view_t input)
{
	string_t result;
	auto start = input.begin();
	auto end   = input.end();
	while (start < end)
	{
		char_t next = utf8::next(start, end);

		switch (next)
		{
		// case HAMZA:
		// case WAW_HAMZA_ABOVE:
		// case YEH_HAMZA_ABOVE:
		case ALEF_HAMZA_BELOW:
		case ALEF_MADDA:
		case ALEF_HAMZA_ABOVE:
			next = ALEF_NO_HAMZA;
			break;

		default:
			break;
		}

		utf8::append(next, result);
	}
	return result;
}

std::string normalize_to_teh(string_view_t input)
{
	string_t result;

	auto start = input.begin();
	auto end   = input.end();

	while (start < end)
	{
		char_t next = utf8::next(start, end);
		if (next == HEH)
		{
			if (start == end)
			{
				utf8::append(TEH_MARBOOTA, result);
				continue;
			}
			char_t peek = utf8::peek_next(start, end);
			if (!is_arabic_alpha(peek))
			{
				utf8::append(TEH_MARBOOTA, result);
				continue;
			}
		}

		utf8::append(next, result);
	}
	return result;
}
std::string normalize_to_heh(string_view_t input)
{
	return replace_if(
	    input, [](char_t c) { return c == TEH_MARBOOTA; }, HEH);
}

string_t duplicate_shadda_letter(string_view_t input)
{
	string_t result;
	auto start = input.begin();
	auto end   = input.end();

	char_t prev{};
	// TODO(Abdullah) : Could be more efficient
	while (start < end)
	{

		char_t next = utf8::next(start, end);
		if (next == SHADDA)
		{
			utf8::append(prev, result);
		}
		else
		{
			utf8::append(next, result);
		}
		prev = next;
	}

	return result;
}

string_t fold_if(string_view_t input, const std::function<bool(char_t, char_t)>& func)
{
	string_t result;
	if (input.empty())
	{
		return result;
	}
	auto start = input.begin();
	auto end   = input.end();

	char_t prev = utf8::next(start, end);
	utf8::append(prev, result);

	while (start < end)
	{
		char_t next = utf8::next(start, end);
		if (func(prev, next))
		{
			continue;
		}
		utf8::append(next, result);
		prev = next;
	}
	return result;
}

string_t fold_white_spaces(string_view_t input)
{

	string_t result;
	if (input.empty())
	{
		return result;
	}
	auto start = input.begin();
	auto end   = input.end();

	char_t prev = utf8::next(start, end);
	utf8::append(std::isspace(static_cast<char>(prev)) ? U' ' : prev, result);

	while (start < end)
	{
		char_t next = utf8::next(start, end);
		if (std::isspace(static_cast<char>(prev)) && std::isspace(static_cast<char>(next)))
		{
			continue;
		}
		utf8::append(std::isspace(static_cast<char>(next)) ? U' ' : next, result);
		prev = next;
	}
	return result;
}

string_t replace(string_view_t input, std::map<char_t, char_t> chars_map)
{
	string_t result;
	auto start = input.begin();
	auto end   = input.end();
	while (start < end)
	{
		char_t next = utf8::next(start, end);
		auto node   = chars_map.find(next);
		utf8::append(node != chars_map.end() ? node->second : next, result);
	}
	return result;
}

template <typename StringT>
void replace_inplace(StringT& subject, StringT search, StringT replace)
{
	size_t pos = 0;
	while ((pos = subject.find(search, pos)) != StringT::npos)
	{
		subject.replace(pos, search.length(), replace);
		pos += replace.length();
	}
}

string_t replace_str(string_view_t input, std::map<string_view_t, string_view_t> replacement_map)
{
	std::u32string result = to_32string(input);

	for (const auto& item : replacement_map)
	{
		replace_inplace(result, to_32string(item.first), to_32string(item.second));
	}

	return utf8::utf32to8(result);
}

std::string replace_if(string_view_t input, const std::function<bool(char_t)>& func,
                       char_t replacement)
{
	string_t result;
	auto start = input.begin();
	auto end   = input.end();
	while (start < end)
	{
		char_t next = utf8::next(start, end);
		utf8::append(func(next) ? replacement : next, result);
	}
	return result;
}

std::vector<char_t> to_vec(string_view_t input)
{
	std::vector<char_t> result;
	auto start = input.begin();
	auto end   = input.end();
	while (start < end)
	{
		result.push_back(utf8::next(start, end));
	}

	return result;
}

vector_t<string_t> split(string_view_t input, char_t delimeter, bool keep_delimeters)
{

	std::vector<string_t> result;
	std::string part;

	auto start = input.begin();
	auto end   = input.end();

	while (start < end)
	{
		char_t next = utf8::next(start, end);

		if (next == delimeter)
		{
			if (keep_delimeters)
			{
				utf8::append(next, part);
			}
			if (!part.empty())
			{
				result.emplace_back(std::move(part));
			}
			continue;
		}
		utf8::append(next, part);
	}

	if (!part.empty())
	{
		result.emplace_back(std::move(part));
	}

	return result;
}

vector_t<string_t> split(string_view_t input, string_view_t delimeters, bool keep_delimeters)
{

	std::vector<char_t> delims = to_vec(delimeters);

	std::vector<string_t> result;
	std::string part;

	auto start = input.begin();
	auto end   = input.end();

	while (start < end)
	{
		char_t next = utf8::next(start, end);

		if (std::find(delims.begin(), delims.end(), next) != delims.end())
		{
			if (keep_delimeters)
			{
				utf8::append(next, part);
			}
			if (!part.empty())
			{
				result.emplace_back(std::move(part));
			}
			continue;
		}
		utf8::append(next, part);
	}

	if (!part.empty())
	{
		result.emplace_back(std::move(part));
	}

	return result;
}

void split_on_impl(string_view_t input, const std::vector<char_t>& delims, int max_word_per_line,
                   size_t idx, vector_t<std::string>& output)
{

	if (idx == delims.size())
	{
		int counter = 0;
		size_t prev = 0;
		for (size_t i = 0; i < input.size(); ++i)
		{
			if (std::isspace(input[i]))
			{
				counter++;
			}
			if (counter == max_word_per_line)
			{
				output.emplace_back(
				    input.substr(std::isspace(input[prev]) ? prev + 1 : prev, i - prev));
				counter = 0;
				prev    = i;
			}
		}
		if (prev != input.size() - 1)
		{
			output.emplace_back(
			    input.substr(std::isspace(input[prev]) ? prev + 1 : prev, input.size() - prev));
		}
		return;
	}

	std::vector<std::string> lines = anltk::split(input, delims[idx], true);
	for (auto&& line : lines)
	{
		if (line.empty()
		    || std::all_of(line.begin(), line.end(), [](char c) { return std::isspace(c); }))
		{
			continue;
		}
		auto start = std::isspace(line.front()) ? line.begin() + 1 : line.begin();
		auto end   = std::isspace(line.back()) ? line.end() - 1 : line.end();

		if (std::count(start, end, ' ') > max_word_per_line)
		{
			split_on_impl(line, delims, max_word_per_line, idx + 1, output);
		}
		else
		{
			output.emplace_back(std::isspace(line.front()) ? line.substr(1) : line);
		}
	}
}

vector_t<std::string> split_on(string_view_t input, string_view_t delimeters, int max_word_per_line)
{
	std::vector<char_t> delims = to_vec(delimeters);
	vector_t<std::string> output;
	split_on_impl(input, delims, max_word_per_line, 0, output);
	return output;
}

} // namespace anltk