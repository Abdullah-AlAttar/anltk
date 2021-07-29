

#include "anltk/anltk_api.h"

#include "doctest.h"

#include <iostream>
#include <string>

TEST_CASE("Empty")
{
    ANLTK_Tokenizer* tok = anltk_tokenizer_new();

    ANLTK_LIST arr = anltk_tokenizer_tokenize_words(tok, "");

    REQUIRE(arr.len == 0);
    //  CHECK(std::string(arr.data[0]) == "بسم");
    //  CHECK(std::string(arr.data[1]) == ".");

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

    REQUIRE(arr.len == 5);
    size_t i = 0;
    CHECK(std::string(arr.data[i++]) == "بسم");
    CHECK(std::string(arr.data[i++]) == "الله");
    CHECK(std::string(arr.data[i++]) == "الرحمن");
    CHECK(std::string(arr.data[i++]) == "الرحيم");
    CHECK(std::string(arr.data[i++]) == ".");

    anltk_tokenizer_free(tok);
}

TEST_CASE("Mixed with non arabic letters Tokenization")
{
    ANLTK_Tokenizer* tok = anltk_tokenizer_new();

    ANLTK_LIST arr = anltk_tokenizer_tokenize_words(tok, "ال3 بسم الله!! ي الرح3من ال يي");

    //  for (size_t i = 0; i < arr.len; ++i)
    //  {
    //      std::cout << i << " \"" << arr.data[i] << '"' << std::endl;
    //  }
    REQUIRE(arr.len == 11);
    size_t i = 0;

    CHECK(std::string(arr.data[i++]) == "ال");
    CHECK(std::string(arr.data[i++]) == "3");
    CHECK(std::string(arr.data[i++]) == "بسم");
    CHECK(std::string(arr.data[i++]) == "الله");
    CHECK(std::string(arr.data[i++]) == "!!");
    CHECK(std::string(arr.data[i++]) == "ي");
    CHECK(std::string(arr.data[i++]) == "الرح");
    CHECK(std::string(arr.data[i++]) == "3");
    CHECK(std::string(arr.data[i++]) == "من");
    CHECK(std::string(arr.data[i++]) == "ال");
    CHECK(std::string(arr.data[i++]) == "يي");
    anltk_tokenizer_free(tok);
}

TEST_CASE("Mixed with non arabic letters and tashkeel Tokenization")
{
    ANLTK_Tokenizer* tok = anltk_tokenizer_new();

    ANLTK_LIST arr = anltk_tokenizer_tokenize_words(tok, "ال3 بِسْمِ الله!! ي الرّح3من ال رحيمِ؟");

    for (size_t i = 0; i < arr.len; ++i)
    {
        std::cout << i << " \"" << arr.data[i] << '"' << std::endl;
    }
    REQUIRE(arr.len == 12);
    size_t i = 0;
    CHECK(std::string(arr.data[i++]) == "ال");
    CHECK(std::string(arr.data[i++]) == "3");
    CHECK(std::string(arr.data[i++]) == "بِسْمِ");
    CHECK(std::string(arr.data[i++]) == "الله");
    CHECK(std::string(arr.data[i++]) == "!!");
    CHECK(std::string(arr.data[i++]) == "ي");
    CHECK(std::string(arr.data[i++]) == "الرّح");
    CHECK(std::string(arr.data[i++]) == "3");
    CHECK(std::string(arr.data[i++]) == "من");
    CHECK(std::string(arr.data[i++]) == "ال");
    CHECK(std::string(arr.data[i++]) == "رحيمِ");
    CHECK(std::string(arr.data[i++]) == "؟");

    anltk_tokenizer_free(tok);
}
