#include <anltk/anltk_api.h>

#include "doctest.h"
#include <iostream>
#include <tinyutf8/tinyutf8.h>

TEST_CASE("testing the factorial function")
{
    // tiny_utf8::string bw = anltk_ar_to_bw("w");
    // ;
    // std::cout << anltk_ar_to_bw("w");

    // const char* text = "بسمء اللهص ءالرحمن الرحيم";
    // char* dad        = "\u0635";
    // tiny_utf8::string str = text;
    // char32_t HAH      = U'\u062D';
    // str.append(tiny_utf8::string(anltk::HAH));
    // str.append(tiny_utf8::string(anltk::HAH));

    // const tiny_utf8::string sad = dad;
    // std::for_each(str.rbegin(), str.rend(), [](char32_t codepoint) {
    //     std::cout << (char32_t)codepoint << " " << std::endl;
    // });

    // std::cout << str.c_str() << std::endl;
    // for (auto i = str.begin(); i != str.end(); ++i)
    // {
    //     if (*i == sad.front())
    //     {
    //         REQUIRE(true);
    //     }
    //     if (*i == bw.front())
    //     {
    //         std::cout << "HAMZAA";
    //         REQUIRE(true);
    //     }
    //     std::cout << (uint64_t)*i << " ";
    // }
}

TEST_CASE("Arabic to Buckwalter test C-api")
{
    Transliterator* ttor = anltk_transliterator_new(CM_AR2BW);

    const char* ar_text = "أبجد هوز حطي كلمن سعفص قرشت ثخذ ضظغ";

    const char* bw_text = anltk_transliterator_convert(ttor, ar_text);

    std::cout << bw_text << std::endl;

    const char* expected = ">bjd hwz HTy klmn sEfS qr$t vx* DZg";

    REQUIRE(std::string(bw_text) == std::string(expected));
    anltk_transliterator_free(ttor);
}

TEST_CASE("Buckwalter to Arabic test C-api")
{
    Transliterator* ttor = anltk_transliterator_new(CM_BW2AR);

    const char* bw_text = ">bjd hwz HTy klmn sEfS qr$t vx* DZg";

    const char* ar_text  = anltk_transliterator_convert(ttor, bw_text);
    const char* expected = "أبجد هوز حطي كلمن سعفص قرشت ثخذ ضظغ";

    std::cout << ar_text << std::endl;
    REQUIRE(std::string(ar_text) == std::string(expected));

    anltk_transliterator_free(ttor);
}

TEST_CASE("Buckwalter to Arabic Mixed ")
{
    Transliterator* ttor = anltk_transliterator_new(CM_BW2AR);

    const char* bw_text = ">bjd hwz HTy klmn sEfS qr$t vx* DZg بسم الله 123";

    const char* ar_text = anltk_transliterator_convert(ttor, bw_text);
    const char* expected = "أبجد هوز حطي كلمن سعفص قرشت ثخذ ضظغ بسم الله 123";

    std::cout << ar_text << std::endl;
    REQUIRE(std::string(ar_text) == std::string(expected));

    anltk_transliterator_free(ttor);
}

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