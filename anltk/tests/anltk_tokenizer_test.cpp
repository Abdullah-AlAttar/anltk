

#include "anltk/anltk.hpp"
#include "anltk/anltk_string_utils.h"
#include "doctest.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

TEST_CASE("Empty")
{
	std::vector<std::string> arr = anltk::tokenize_words("");

	REQUIRE(arr.size() == 0);
}

TEST_CASE("Very Basic Tokenization")
{

	std::vector<std::string> arr = anltk::tokenize_words("بسم.");

	REQUIRE(arr.size() == 2);
	CHECK(std::string(arr[0]) == "بسم");
	CHECK(std::string(arr[1]) == ".");
}

TEST_CASE("Basic Tokenization")
{

	std::vector<std::string> arr = anltk::tokenize_words("بسم الله الرحمن الرحيم.");
	std::vector<std::string> expected = { "بسم", "الله", "الرحمن", "الرحيم", "." };
	REQUIRE(arr.size() == expected.size());
	for (size_t i = 0; i < arr.size(); ++i)
	{
		CHECK(expected[i] == arr[i]);
	}
}

TEST_CASE("Mixed with non arabic letters Tokenization")
{

	std::vector<std::string> arr = anltk::tokenize_words("ال3 بسم الله!! ي الرح3من ال يي");

	std::vector<std::string> expected
	    = { "ال", "3", "بسم", "الله", "!!", "ي", "الرح", "3", "من", "ال", "يي" };

	REQUIRE(arr.size() == expected.size());
	for (size_t i = 0; i < arr.size(); ++i)
	{
		CHECK(expected[i] == arr[i]);
	}
}

TEST_CASE("Mixed with non arabic letters and tashkeel Tokenization")
{

	std::vector<std::string> arr = anltk::tokenize_words("ال3 بِسْمِ الـله!! ي الرّح3من ال رحيمِ؟");

	std::vector<std::string> expected
	    = { "ال", "3", "بِسْمِ", "الـله", "!!", "ي", "الرّح", "3", "من", "ال", "رحيمِ", "؟" };

	REQUIRE(arr.size() == expected.size());
	for (size_t i = 0; i < arr.size(); ++i)
	{
		CHECK(expected[i] == arr[i]);
	}
}

TEST_CASE("tokenize If")
{
	SUBCASE("Basic")
	{
		std::string input = "Is 123 this a بسم الله real life,345 or it's just a f567antasy3";

		std::vector<std::pair<int, std::string>> expected
		    = { { -1, "Is " },         { 0, "123" },     { -1, " this a " },
			    { 1, "بسم" },          { -1, " " },      { 1, "الله" },
			    { -1, " real life," }, { 0, "345" },     { -1, " or it's just a f" },
			    { 0, "567" },          { -1, "antasy" }, { 0, "3" } };

		std::vector<std::pair<int, std::string>> found = anltk::tokenize_if(
		    input,
		    { [](char32_t c) { return anltk::is_digit(c); }, &anltk::is_arabic_alpha

		    });

		REQUIRE(found == expected);
	}

	SUBCASE("Tashkeel ")
	{
		std::string input = "إِنَّ الَّذِينَ كَفَرُوا سَوَاءٌ عَلَيْهِمْ أَأَنذَرْتَهُمْ أَمْ لَمْ تُنذِرْهُمْ لَا يُؤْمِنُونَ .";

		std::vector<std::pair<int, std::string>> expected
		    = { { -1, "إ" },   { 0, "ِ" }, { -1, "ن" },  { 0, "َّ" }, { -1, " ال" },  { 0, "َّ" },
			    { -1, "ذ" },   { 0, "ِ" }, { -1, "ين" }, { 0, "َ" }, { -1, " ك" },   { 0, "َ" },
			    { -1, "ف" },   { 0, "َ" }, { -1, "ر" },  { 0, "ُ" }, { -1, "وا س" }, { 0, "َ" },
			    { -1, "و" },   { 0, "َ" }, { -1, "اء" }, { 0, "ٌ" }, { -1, " ع" },   { 0, "َ" },
			    { -1, "ل" },   { 0, "َ" }, { -1, "ي" },  { 0, "ْ" }, { -1, "ه" },    { 0, "ِ" },
			    { -1, "م" },   { 0, "ْ" }, { -1, " أ" }, { 0, "َ" }, { -1, "أ" },    { 0, "َ" },
			    { -1, "نذ" },  { 0, "َ" }, { -1, "ر" },  { 0, "ْ" }, { -1, "ت" },    { 0, "َ" },
			    { -1, "ه" },   { 0, "ُ" }, { -1, "م" },  { 0, "ْ" }, { -1, " أ" },   { 0, "َ" },
			    { -1, "م" },   { 0, "ْ" }, { -1, " ل" }, { 0, "َ" }, { -1, "م" },    { 0, "ْ" },
			    { -1, " ت" },  { 0, "ُ" }, { -1, "نذ" }, { 0, "ِ" }, { -1, "ر" },    { 0, "ْ" },
			    { -1, "ه" },   { 0, "ُ" }, { -1, "م" },  { 0, "ْ" }, { -1, " ل" },   { 0, "َ" },
			    { -1, "ا ي" }, { 0, "ُ" }, { -1, "ؤ" },  { 0, "ْ" }, { -1, "م" },    { 0, "ِ" },
			    { -1, "ن" },   { 0, "ُ" }, { -1, "ون" }, { 0, "َ" }, { -1, " ." } };

		std::vector<std::pair<int, std::string>> found
		    = anltk::tokenize_if(input, { [](char32_t c) { return anltk::is_tashkeel(c); } });

		REQUIRE(found == expected);
	}

	SUBCASE("Tashkeel and Alpha ")
	{
		std::string input = "إِنَّ الَّذِينَ كَفَرُوا سَوَاءٌ عَلَيْهِمْ أَأَنذَرْتَهُمْ أَمْ لَمْ تُنذِرْهُمْ لَا يُؤْمِنُونَ .";

		std::vector<std::pair<int, std::string>> expected
		    = { { 1, "إ" },  { 0, "ِ" },   { 1, "ن" },  { 0, "َّ" },   { -1, " " }, { 1, "ال" },
			    { 0, "َّ" },   { 1, "ذ" },  { 0, "ِ" },   { 1, "ين" }, { 0, "َ" },   { -1, " " },
			    { 1, "ك" },  { 0, "َ" },   { 1, "ف" },  { 0, "َ" },   { 1, "ر" },  { 0, "ُ" },
			    { 1, "وا" }, { -1, " " }, { 1, "س" },  { 0, "َ" },   { 1, "و" },  { 0, "َ" },
			    { 1, "اء" }, { 0, "ٌ" },   { -1, " " }, { 1, "ع" },  { 0, "َ" },   { 1, "ل" },
			    { 0, "َ" },   { 1, "ي" },  { 0, "ْ" },   { 1, "ه" },  { 0, "ِ" },   { 1, "م" },
			    { 0, "ْ" },   { -1, " " }, { 1, "أ" },  { 0, "َ" },   { 1, "أ" },  { 0, "َ" },
			    { 1, "نذ" }, { 0, "َ" },   { 1, "ر" },  { 0, "ْ" },   { 1, "ت" },  { 0, "َ" },
			    { 1, "ه" },  { 0, "ُ" },   { 1, "م" },  { 0, "ْ" },   { -1, " " }, { 1, "أ" },
			    { 0, "َ" },   { 1, "م" },  { 0, "ْ" },   { -1, " " }, { 1, "ل" },  { 0, "َ" },
			    { 1, "م" },  { 0, "ْ" },   { -1, " " }, { 1, "ت" },  { 0, "ُ" },   { 1, "نذ" },
			    { 0, "ِ" },   { 1, "ر" },  { 0, "ْ" },   { 1, "ه" },  { 0, "ُ" },   { 1, "م" },
			    { 0, "ْ" },   { -1, " " }, { 1, "ل" },  { 0, "َ" },   { 1, "ا" },  { -1, " " },
			    { 1, "ي" },  { 0, "ُ" },   { 1, "ؤ" },  { 0, "ْ" },   { 1, "م" },  { 0, "ِ" },
			    { 1, "ن" },  { 0, "ُ" },   { 1, "ون" }, { 0, "َ" },   { -1, " ." }

		      };

		std::vector<std::pair<int, std::string>> found
		    = anltk::tokenize_if(input,
		                         { [](char32_t c) { return anltk::is_tashkeel(c); },
		                           [](char32_t c) { return anltk::is_arabic_alpha(c); } });

		REQUIRE(found == expected);
	}

	SUBCASE("Empty input")
	{
		std::string input = "";

		std::vector<std::pair<int, std::string>> expected = {};

		std::vector<std::pair<int, std::string>> found
		    = anltk::tokenize_if(input,
		                         { [](char32_t c) { return anltk::is_tashkeel(c); },
		                           [](char32_t c) { return anltk::is_arabic_alpha(c); } });

		REQUIRE(found == expected);
	}
	SUBCASE("Empty Functors")
	{
		std::string input = "Nice Input Bro";

		std::vector<std::pair<int, std::string>> expected = { { -1, "Nice Input Bro" } };

		std::vector<std::pair<int, std::string>> found = anltk::tokenize_if(input, {});

		REQUIRE(found == expected);
	}

	SUBCASE("Multiple Matches")
	{
		// Matches by functions order
		std::string input = "بسم الله";

		std::vector<std::pair<int, std::string>> expected
		    = { { 0, "بسم" }, { -1, " " }, { 0, "الله" } };

		std::vector<std::pair<int, std::string>> found
		    = anltk::tokenize_if(input, { &anltk::is_arabic_alpha, &anltk::is_arabic_alpha });

		// for (auto [i, seq] : found)
		// {
		// 	std::cout << "{" << i << " , \"" << seq << "\"}," << std::endl;
		// }
		REQUIRE(found == expected);
	}
	SUBCASE("Tokenize words")
	{
		std::vector<std::pair<int, std::string>> tmp = anltk::tokenize_if(
		    "ال3 بِسْمِ الـله!! ي الرّح3من ال رحيمِ؟", { [](char32_t c) {
			    return anltk::is_arabic_alpha(c) || anltk::is_tashkeel(c) || anltk::is_TATWEEL(c);
		    } });
		std::vector<std::string> expected;
		for (auto [id, token] : tmp)
		{
			anltk::trim(token);
			if (token.empty())
			{
				continue;
			}
			expected.push_back(token);
		}

		std::vector<std::string> found
		    = { "ال", "3", "بِسْمِ", "الـله", "!!", "ي", "الرّح", "3", "من", "ال", "رحيمِ", "؟" };

		REQUIRE(found == expected);
	}
}