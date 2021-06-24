#include "anltk/anltk_api.h"
#include "doctest.h"
#include <iostream>
#include <string>

TEST_CASE("Valid Kalima")
{
    SUBCASE("Has Spaces")
    {
        const char* ar_text = "أبجد هوز حطي كلمن سعفص قرشت ثخذ ضظغ";
        REQUIRE(anltk_is_valid_kalima(ar_text) == false);
    }
    SUBCASE("Empty")
    {
        const char* ar_text = "";
        REQUIRE(anltk_is_valid_kalima(ar_text) == false);
    }
    SUBCASE("Has double consecutive shadda")
    {
        const char* ar_text = "بسّّم";
        REQUIRE(anltk_is_valid_kalima(ar_text) == false);
    }
    SUBCASE("First Character tashkeel")
    {
        const char* ar_text = "ًبسم";
        REQUIRE(anltk_is_valid_kalima(ar_text) == false);
    }
    SUBCASE("First Character  WAW_HAMZA")
    {
        const char* ar_text = "ؤامر";
        REQUIRE(anltk_is_valid_kalima(ar_text) == false);
    }
    SUBCASE("First Character  YEH_HAMZA")
    {
        const char* ar_text = "ئاسر";
        REQUIRE(anltk_is_valid_kalima(ar_text) == false);
    }
    SUBCASE("Alef Maqsura not last Character")
    {
        const char* ar_text = "ىا ليلى";
        REQUIRE(anltk_is_valid_kalima(ar_text) == false);
    }

    SUBCASE("Teh Marbuta not last Character")
    {
        const char* ar_text = "ىا لةيلى";
        REQUIRE(anltk_is_valid_kalima(ar_text) == false);
    }
    SUBCASE("Three consectuve harakat")
    {
        const char* ar_text = "ىاًَُ لةيلى";
        REQUIRE(anltk_is_valid_kalima(ar_text) == false);
    }
       SUBCASE(" double Teh Marbuta")
    {
        const char* ar_text = "ىا لةةيلى";
        REQUIRE(anltk_is_valid_kalima(ar_text) == false);
    }

    SUBCASE("Valid")
    {
        const char* ar_text = "فأسقيناكموه";
        REQUIRE(anltk_is_valid_kalima(ar_text) == true);
    }
    SUBCASE("Valid1")
    {
        const char* ar_text = "فأسًقيٍنََاّكمٍوُه";
        REQUIRE(anltk_is_valid_kalima(ar_text) == true);
    }
}

TEST_CASE("is tashkeel")
{
    SUBCASE("Fatha")
    {
        const char* ar_text = "َ";
        REQUIRE(anltk_is_tashkeel(ar_text) == true);
    }
    SUBCASE("Tanween Nasb")
    {
        const char* ar_text = "ً";
        REQUIRE(anltk_is_tashkeel(ar_text) == true);
    }
    SUBCASE("Tanween Nasb")
    {
        const char* ar_text = "ً";
        REQUIRE(anltk_is_tashkeel(ar_text) == true);
    }
    SUBCASE("Double tashkeel")
    {
        const char* ar_text = "ًّ";
        REQUIRE(anltk_is_tashkeel(ar_text) == false);
    }

    SUBCASE("Not tashkeel")
    {
        const char* ar_text = "ب";
        REQUIRE(anltk_is_tashkeel(ar_text) == false);
    }
}

TEST_CASE("Is Alphabet")
{
    SUBCASE("Basic")
    {
        const char* ar_text = "أ";
        REQUIRE(anltk_is_arabic_alpha(ar_text) == true);
    }
    SUBCASE("Basic2")
    {
        const char* ar_text = "ذ";
        REQUIRE(anltk_is_arabic_alpha(ar_text) == true);
    }
    SUBCASE("Tashkeel")
    {
        const char* ar_text = "ً";
        REQUIRE(anltk_is_arabic_alpha(ar_text) == false);
    }
    SUBCASE("double character")
    {
        const char* ar_text = "ثا";
        REQUIRE(anltk_is_arabic_alpha(ar_text) == false);
    }
    SUBCASE("لا")
    {
        const char* ar_text = "ﻻ";
        REQUIRE(anltk_is_arabic_alpha(ar_text) == false);
    }

    SUBCASE("Tatweel")
    {
        const char* ar_text = "ـ";
        REQUIRE(anltk_is_arabic_alpha(ar_text) == false);
    }
}