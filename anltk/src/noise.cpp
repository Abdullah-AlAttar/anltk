#include <anltk/anltk.hpp>
#include <random>
#include <utf8.h>

namespace anltk
{

NoiseGenerator::NoiseGenerator()
{
	auto seed = rd();
	gen.seed(seed);
}

bool _has_adjacent_ar_chars(const std::u32string& inp)
{
	bool has_adjacent_ar_chars = false;
	for (size_t i = 1; i < inp.size(); ++i)
	{
		if (is_arabic_alpha(inp[i]) && is_arabic_alpha(inp[i - 1]))
		{
			has_adjacent_ar_chars = true;
			break;
		}
	}
	return has_adjacent_ar_chars;
}

std::vector<size_t> _get_indices_if(const std::u32string& inp, std::function<bool(char32_t)>&& f)
{
	std::vector<size_t> indices;

	for (size_t i = 0; i < inp.size(); i++)
	{
		if (f(inp[i]))
		{
			indices.push_back(i);
		}
	}
	return indices;
}
std::string NoiseGenerator::swap_adjacent_chars(anltk::string_view_t input, size_t n)
{
	if (n == 0)
	{
		return std::string(input.begin(), input.end());
	}

	std::u32string inp = anltk::to_32string(input);
	size_t len         = inp.size();
	if (len < 2)
	{
		return std::string(input.begin(), input.end());
	}

	if (!_has_adjacent_ar_chars(inp))
	{
		return std::string(input.begin(), input.end());
	}

	for (size_t i = 0; i < n; i++)
	{
		size_t pos = (this->gen() % len) - 1;

		while (!(is_arabic_alpha(inp[pos]) && is_arabic_alpha(inp[pos + 1])))
		{
			pos = (this->gen() % len) - 1;
		}
		std::swap(inp[pos], inp[pos + 1]);
	}

	return utf8::utf32to8(inp);
}

std::string NoiseGenerator::insert_random_chars(anltk::string_view_t input, size_t n)
{
	if (n == 0)
	{
		return std::string(input.begin(), input.end());
	}
	std::u32string inp = anltk::to_32string(input);

	std::vector<size_t> indices = _get_indices_if(inp, anltk::is_arabic_alpha);

	std::shuffle(indices.begin(), indices.end(), this->gen);

	std::sort(indices.begin(), indices.begin() + std::min(n, indices.size()));

	auto start = inp.begin();
	auto end   = inp.end();

	size_t insertion_idx = 0, random_idx = 0;

	std::string result;

	while (start < end)
	{
		utf8::append(*start, result);

		if (random_idx < n && insertion_idx == indices[random_idx])
		{
			utf8::append(alphabet_[std::rand() % alphabet_.size()], result);
			random_idx++;
		}

		insertion_idx++;
		start++;
	}

	return result;
}

std::string NoiseGenerator::remove_random_chars(anltk::string_view_t input, size_t n)
{
	if (n == 0)
	{
		return std::string(input.begin(), input.end());
	}

	std::u32string inp = anltk::to_32string(input);
	size_t len         = inp.size();

	std::vector<size_t> indices = _get_indices_if(inp, anltk::is_arabic_alpha);

	std::shuffle(indices.begin(), indices.end(), this->gen);

	size_t limit = std::min(n, indices.size());

	std::sort(indices.begin(), indices.begin() + limit);

	std::string result;

	for (size_t i = 0, del_i = 0; i < len; ++i)
	{
		if (del_i < limit && i == indices[del_i])
		{
			del_i++;
			continue;
		}
		utf8::append(inp[i], result);
	}

	return result;
}

std::string NoiseGenerator::replace_random_chars(anltk::string_view_t input, size_t n)
{
	if (n == 0)
	{
		return std::string(input.begin(), input.end());
	}

	std::u32string inp = anltk::to_32string(input);
	size_t len         = inp.size();

	std::vector<size_t> indices = _get_indices_if(inp, anltk::is_arabic_alpha);

	std::shuffle(indices.begin(), indices.end(), this->gen);

	size_t limit = std::min(n, indices.size());

	std::sort(indices.begin(), indices.begin() + limit);

	std::string result;

	for (size_t i = 0, repl_i = 0; i < len; ++i)
	{
		if (repl_i < limit && i == indices[repl_i])
		{
			repl_i++;
			utf8::append(alphabet_[this->gen() % alphabet_.size()], result);
			continue;
		}
		utf8::append(inp[i], result);
	}

	return result;
}

std::string NoiseGenerator::join_random_words(string_view_t input, size_t n)
{
	if (n == 0)
	{
		return std::string(input.begin(), input.end());
	}
	std::u32string inp = anltk::to_32string(input);
	size_t len         = inp.size();

	std::vector<size_t> indices
	    = _get_indices_if(inp, [](char32_t c) { return std::isspace(static_cast<char>(c)); });

	std::shuffle(indices.begin(), indices.end(), this->gen);

	size_t limit = std::min(n, indices.size());

	std::sort(indices.begin(), indices.begin() + limit);

	std::string result;

	for (size_t i = 0, del_i = 0; i < len; ++i)
	{
		if (del_i < limit && i == indices[del_i])
		{
			del_i++;
			continue;
		}
		utf8::append(inp[i], result);
	}

	return result;
}

std::string NoiseGenerator::swap_random_words(string_view_t input, size_t n)
{
	if (n == 0)
	{
		return std::string(input.begin(), input.end());
	}
	std::vector<std::string> words = split(input);

	size_t words_len = words.size();

	if (words_len <= 1)
	{
		return std::string(input.begin(), input.end());
	}
	auto get_two_random_numbers = [this](auto start, auto end)
	{
		std::uniform_int_distribution<> distr(start, end);
		int a = distr(this->gen);
		int b = distr(this->gen);
		while (a == b)
			b = distr(this->gen);
		return std::pair{ a, b };
	};
	using std::swap;

	for (size_t i = 0; i < n; i++)
	{
		auto [a, b] = get_two_random_numbers(0, words_len - 1);
		swap(words[a], words[b]);
	}

	std::string res = words[0];
	for (size_t i = 1; i < words_len; ++i)
	{
		res += " " + words[i];
	}
	return res;
}
void NoiseGenerator::set_seed(int seed)
{
	this->gen.seed(seed);
}
} // namespace anltk