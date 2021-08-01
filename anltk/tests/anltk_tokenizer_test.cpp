

#include "anltk/anltk_api.h"

#include "doctest.h"

#include <iostream>
#include <string>
#include <vector>

TEST_CASE("Empty")
{
    ANLTK_Tokenizer* tok = anltk_tokenizer_new();

    ANLTK_LIST arr = anltk_tokenizer_tokenize_words(tok, "");

    REQUIRE(arr.len == 0);

    anltk_tokenizer_free(tok);
}

TEST_CASE("Very Basic Tokenization")
{
    ANLTK_Tokenizer* tok = anltk_tokenizer_new();

    ANLTK_LIST arr = anltk_tokenizer_tokenize_words(tok, "بسم.");

    REQUIRE(arr.len == 2);
    CHECK(std::string(arr.data[0]) == "بسم");
    CHECK(std::string(arr.data[1]) == ".");

    anltk_tokenizer_free(tok);
}

TEST_CASE("Basic Tokenization")
{
    ANLTK_Tokenizer* tok = anltk_tokenizer_new();

    ANLTK_LIST arr = anltk_tokenizer_tokenize_words(tok, "بسم الله الرحمن الرحيم.");
    std::vector<std::string> expected = { "بسم", "الله", "الرحمن", "الرحيم", "." };
    REQUIRE(arr.len == expected.size());
    for (size_t i = 0; i < arr.len; ++i)
    {
        CHECK(expected[i] == arr.data[i]);
    }

    anltk_tokenizer_free(tok);
}

TEST_CASE("Mixed with non arabic letters Tokenization")
{
    ANLTK_Tokenizer* tok = anltk_tokenizer_new();

    ANLTK_LIST arr = anltk_tokenizer_tokenize_words(tok, "ال3 بسم الله!! ي الرح3من ال يي");

    std::vector<std::string> expected
        = { "ال", "3", "بسم", "الله", "!!", "ي", "الرح", "3", "من", "ال", "يي" };

    REQUIRE(arr.len == expected.size());
    for (size_t i = 0; i < arr.len; ++i)
    {
        CHECK(expected[i] == arr.data[i]);
    }

    anltk_tokenizer_free(tok);
}

TEST_CASE("Mixed with non arabic letters and tashkeel Tokenization")
{
    ANLTK_Tokenizer* tok = anltk_tokenizer_new();

    ANLTK_LIST arr = anltk_tokenizer_tokenize_words(tok, "ال3 بِسْمِ الله!! ي الرّح3من ال رحيمِ؟");

    std::vector<std::string> expected
        = { "ال", "3", "بِسْمِ", "الله", "!!", "ي", "الرّح", "3", "من", "ال", "رحيمِ", "؟" };

    REQUIRE(arr.len == expected.size());
    for (size_t i = 0; i < arr.len; ++i)
    {
        CHECK(expected[i] == arr.data[i]);
    }

    anltk_tokenizer_free(tok);
}
