#include <algorithm>
#include <anltk/anltk.hpp>
#include <assert.h>
#include <iostream>
#include <utf8.h>

namespace anltk
{

static bool ends_with(std::string_view str, std::string_view suffix)
{
	return str.size() >= suffix.size()
	    && 0 == str.compare(str.size() - suffix.size(), suffix.size(), suffix);
}

static bool starts_with(std::string_view str, std::string_view prefix)
{
	return str.size() >= prefix.size() && 0 == str.compare(0, prefix.size(), prefix);
}

static bool ends_with(std::u32string_view str, std::u32string_view suffix)
{
	return str.size() >= suffix.size()
	    && 0 == str.compare(str.size() - suffix.size(), suffix.size(), suffix);
}

static bool starts_with(std::u32string_view str, std::u32string_view prefix)
{
	return str.size() >= prefix.size() && 0 == str.compare(0, prefix.size(), prefix);
}

size_t match_pattern(std::u32string_view word, std::u32string_view pattern, anltk::string_t& root)
{

	if (word.size() != pattern.size())
	{
		return 0;
	}
	assert(word.size() == pattern.size());

	size_t n_matches = 0;
	size_t n_chars   = 0;

	for (size_t i = 0; i < word.size(); ++i)
	{
		char_t a = word[i];
		char_t b = pattern[i];
		if (a == b)
		{
			n_matches++;
			if (a == anltk::FEH || a == anltk::AIN || a == anltk::LAM)
			{
				utf8::append(a, root);
			}
		}
		else
		{
			utf8::append(a, root);
		}
		n_chars++;
	}
	// assert(n_chars > 3);
	return n_matches;
}

anltk::string_t get_root_from_patterns(std::u32string_view word,
                                       const std::vector<std::u32string>& patterns)
{
	anltk::string_t output;

	int max_match = 0;
	for (size_t i = 0; i < patterns.size(); ++i)
	{

		const auto& pattern = patterns[i];
		anltk::string_t root;
		int match = match_pattern(word, pattern, root);
		std::cout << utf8::utf32to8(word) << " " << utf8::utf32to8(pattern) << " " << word.size()
		          << " " << pattern.size() << " " << root << " " << match << std::endl;
		if (match > 0 && match > max_match)
		{
			std::cout << "Yes\n";
			max_match = match;
			output    = root;
		}
	}
	return output;
}

std::vector<std::u32string> to_32vec(const std::vector<std::string>& vec)

{
	std::vector<std::u32string> output;
	output.reserve(vec.size());
	std::transform(vec.begin(), vec.end(), std::back_inserter(output), &to_32string);
	return output;
}

anltk::string_t rafal_stem(const std::string& word, const std::vector<std::string>& stop_words_,
                           const std::vector<std::string>& prefixes_,
                           const std::vector<std::string>& suffixes_,
                           const std::vector<std::string>& patterns_)
{

	std::vector<std::u32string> stop_words = to_32vec(stop_words_);
	std::vector<std::u32string> prefixes   = to_32vec(prefixes_);
	std::vector<std::u32string> suffixes   = to_32vec(suffixes_);
	std::vector<std::u32string> patterns   = to_32vec(patterns_);

	anltk::string_t normalized = anltk::normalize_hamzat(word);
	// Normalize hamzat
	// clang-format off
	normalized = anltk::replace(normalized, 
		{
			{anltk::ALEF_MADDA, 	  anltk::ALEF_NO_HAMZA},
			{anltk::ALEF_HAMZA_BELOW, anltk::ALEF_NO_HAMZA},
			{anltk::ALEF_HAMZA_ABOVE, anltk::ALEF_NO_HAMZA}
		});
	// clang-format on

	std::u32string u32_word = to_32string(normalized);

	bool is_stop_word
	    = std::find(stop_words.begin(), stop_words.end(), u32_word) != stop_words.end();
	if (is_stop_word)
	{
		return anltk::string_t{ word.begin(), word.end() };
	}

	bool has_prefix = false;
	// for (int i = 0; i < 4; ++i)
	// {
	for (const auto& prefix : prefixes)
	{
		if (starts_with(u32_word, prefix))
		{
			has_prefix = true;
			u32_word   = u32_word.substr(prefix.size());
			break;
		}
	}
	// }
	bool has_suffix = false;

	for (const auto& suffix : suffixes)
	{
		if (ends_with(u32_word, suffix))
		{
			has_suffix = true;
			u32_word   = u32_word.substr(0, u32_word.size() - suffix.size());
		}
	}

	// std::cout << normalized << std::endl;
	// if (!has_prefix || !has_suffix)
	// {
	// 	return anltk::string_t{ word.begin(), word.end() };
	// }

	is_stop_word = std::find(stop_words.begin(), stop_words.end(), u32_word) != stop_words.end();
	if (is_stop_word)
	{
		return anltk::string_t{ word.begin(), word.end() };
	}

	std::string output = get_root_from_patterns(u32_word, patterns);
	return output.empty() ? word : output;
	// return anltk::string_t{ word.begin(), word.end() };
}
} // namespace anltk
