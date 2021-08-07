

#include "anltk/anltk.hpp"

#include "doctest.h"

#include <iostream>
#include <string>
#include <vector>

TEST_CASE("Empty")
{
    std::vector<std::string> arr = anltk::tokenize_words( "");

    REQUIRE(arr.size() == 0);

}

TEST_CASE("Very Basic Tokenization")
{

    std::vector<std::string> arr = anltk::tokenize_words( "بسم.");

    REQUIRE(arr.size() == 2);
    CHECK(std::string(arr[0]) == "بسم");
    CHECK(std::string(arr[1]) == ".");

}

TEST_CASE("Basic Tokenization")
{

    std::vector<std::string> arr = anltk::tokenize_words( "بسم الله الرحمن الرحيم.");
    std::vector<std::string> expected = { "بسم", "الله", "الرحمن", "الرحيم", "." };
    REQUIRE(arr.size() == expected.size());
    for (size_t i = 0; i < arr.size(); ++i)
    {
        CHECK(expected[i] == arr[i]);
    }

}

TEST_CASE("Mixed with non arabic letters Tokenization")
{

    std::vector<std::string> arr = anltk::tokenize_words( "ال3 بسم الله!! ي الرح3من ال يي");

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

    std::vector<std::string> arr = anltk::tokenize_words( "ال3 بِسْمِ الله!! ي الرّح3من ال رحيمِ؟");

    std::vector<std::string> expected
        = { "ال", "3", "بِسْمِ", "الله", "!!", "ي", "الرّح", "3", "من", "ال", "رحيمِ", "؟" };

    REQUIRE(arr.size() == expected.size());
    for (size_t i = 0; i < arr.size(); ++i)
    {
        CHECK(expected[i] == arr[i]);
    }

}
