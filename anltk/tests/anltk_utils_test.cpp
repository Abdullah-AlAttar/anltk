#include "anltk/anltk.hpp"
#include "doctest.h"
#include <iostream>
#include <string>

TEST_CASE("Valid Kalima")
{
    SUBCASE("Has Spaces")
    {
        std::string ar_text = "أبجد هوز حطي كلمن سعفص قرشت ثخذ ضظغ";
        REQUIRE(anltk::is_valid_kalima(ar_text) == false);
    }
    SUBCASE("Empty")
    {
        std::string ar_text = "";
        REQUIRE(anltk::is_valid_kalima(ar_text) == false);
    }
    SUBCASE("Has double consecutive shadda")
    {
        std::string ar_text = "بسّّم";
        REQUIRE(anltk::is_valid_kalima(ar_text) == false);
    }
    SUBCASE("First Character tashkeel")
    {
        std::string ar_text = "ًبسم";
        REQUIRE(anltk::is_valid_kalima(ar_text) == false);
    }
    SUBCASE("First Character  WAW_HAMZA")
    {
        std::string ar_text = "ؤامر";
        REQUIRE(anltk::is_valid_kalima(ar_text) == false);
    }
    SUBCASE("First Character  YEH_HAMZA")
    {
        std::string ar_text = "ئاسر";
        REQUIRE(anltk::is_valid_kalima(ar_text) == false);
    }
    SUBCASE("Alef Maqsura not last Character")
    {
        std::string ar_text = "ىا ليلى";
        REQUIRE(anltk::is_valid_kalima(ar_text) == false);
    }

    SUBCASE("Teh Marbuta not last Character")
    {
        std::string ar_text = "ىا لةيلى";
        REQUIRE(anltk::is_valid_kalima(ar_text) == false);
    }
    SUBCASE("Three consectuve harakat")
    {
        std::string ar_text = "ىاًَُ لةيلى";
        REQUIRE(anltk::is_valid_kalima(ar_text) == false);
    }
    SUBCASE(" double Teh Marbuta")
    {
        std::string ar_text = "ىا لةةيلى";
        REQUIRE(anltk::is_valid_kalima(ar_text) == false);
    }

    SUBCASE("Valid")
    {
        std::string ar_text = "فأسقيناكموه";
        REQUIRE(anltk::is_valid_kalima(ar_text) == true);
    }
    SUBCASE("Valid1")
    {
        std::string ar_text = "فأسًقيٍنََاّكمٍوُه";
        REQUIRE(anltk::is_valid_kalima(ar_text) == true);
    }
}

TEST_CASE("is tashkeel")
{
    SUBCASE("EMPTY")
    {
        char32_t ar_text = U' ';
        REQUIRE(anltk::is_tashkeel(ar_text) == false);
    }
    SUBCASE("Fatha")
    {
        char32_t ar_text = U'َ';
        REQUIRE(anltk::is_tashkeel(ar_text) == true);
    }
    SUBCASE("Tanween Nasb")
    {
        char32_t ar_text = U'ً';
        REQUIRE(anltk::is_tashkeel(ar_text) == true);
    }
    SUBCASE("Tanween Nasb")
    {
        char32_t ar_text = U'ً';
        REQUIRE(anltk::is_tashkeel(ar_text) == true);
    }

    SUBCASE("Not tashkeel")
    {
        char32_t ar_text = U'ب';
        REQUIRE(anltk::is_tashkeel(ar_text) == false);
    }
}

TEST_CASE("Is Alphabet")
{
    SUBCASE("Basic")
    {
        char32_t ar_text = U'أ';
        REQUIRE(anltk::is_arabic_alpha(ar_text) == true);
    }
    SUBCASE("Basic2")
    {
        char32_t ar_text = U'ذ';
        REQUIRE(anltk::is_arabic_alpha(ar_text) == true);
    }
    SUBCASE("Tashkeel")
    {
        char32_t ar_text = U'ً';
        REQUIRE(anltk::is_arabic_alpha(ar_text) == false);
    }
    SUBCASE("لا")
    {
        char32_t ar_text = U'ﻻ';
        REQUIRE(anltk::is_arabic_alpha(ar_text) == false);
    }

    SUBCASE("Tatweel")
    {
        char32_t ar_text = U'ـ';
        REQUIRE(anltk::is_arabic_alpha(ar_text) == false);
    }
}