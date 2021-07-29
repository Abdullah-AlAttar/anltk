

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
    CHECK(std::string(arr.data[0]) == "بسم");
    CHECK(std::string(arr.data[1]) == "الله");
    CHECK(std::string(arr.data[2]) == "الرحمن");
    CHECK(std::string(arr.data[3]) == "الرحيم");
    CHECK(std::string(arr.data[4]) == ".");

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
    CHECK(std::string(arr.data[0]) == "ال");
    CHECK(std::string(arr.data[1]) == "3");
    CHECK(std::string(arr.data[2]) == "بسم");
    CHECK(std::string(arr.data[3]) == "الله");
    CHECK(std::string(arr.data[4]) == "!!");
    CHECK(std::string(arr.data[5]) == "ي");
    CHECK(std::string(arr.data[6]) == "الرح");
    CHECK(std::string(arr.data[7]) == "3");
    CHECK(std::string(arr.data[8]) == "من");
    CHECK(std::string(arr.data[9]) == "ال");
    CHECK(std::string(arr.data[10]) == "يي");
    anltk_tokenizer_free(tok);
}