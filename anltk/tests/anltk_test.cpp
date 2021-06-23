#include <anltk/anltk_api.h>

#include "doctest.h"
#include <iostream>
#include <tinyutf8/tinyutf8.h>

TEST_CASE("testing the factorial function")
{
    // tiny_utf8::string bw = anltk_ar_to_bw("w");
    // ;
    //  << anltk_ar_to_bw("w");

    // const char* text = "بسمء اللهص ءالرحمن الرحيم";
    // char* dad        = "\u0635";
    // tiny_utf8::string str = text;
    // char32_t HAH      = U'\u062D';
    // str.append(tiny_utf8::string(anltk::HAH));
    // str.append(tiny_utf8::string(anltk::HAH));

    // const tiny_utf8::string sad = dad;
    // std::for_each(str.rbegin(), str.rend(), [](char32_t codepoint) {
    //      << (char32_t)codepoint << " " << std::endl;
    // });

    //  << str.c_str() << std::endl;
    // for (auto i = str.begin(); i != str.end(); ++i)
    // {
    //     if (*i == sad.front())
    //     {
    //         REQUIRE(true);
    //     }
    //     if (*i == bw.front())
    //     {
    //          << "HAMZAA";
    //         REQUIRE(true);
    //     }
    //      << (uint64_t)*i << " ";
    // }
}

TEST_CASE("Arabic to Buckwalter test C-api")
{
    Transliterator* ttor = anltk_transliterator_new(CM_AR2BW);

    const char* ar_text = "أبجد هوز حطي كلمن سعفص قرشت ثخذ ضظغ";

    const char* bw_text = anltk_transliterator_convert(ttor, ar_text);


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

    REQUIRE(std::string(ar_text) == std::string(expected));

    anltk_transliterator_free(ttor);
}

TEST_CASE("Buckwalter to Arabic Mixed ")
{
    Transliterator* ttor = anltk_transliterator_new(CM_BW2AR);

    const char* bw_text = ">bjd hwz HTy klmn sEfS qr$t vx* DZg بسم الله 123";

    const char* ar_text = anltk_transliterator_convert(ttor, bw_text);
    const char* expected = "أبجد هوز حطي كلمن سعفص قرشت ثخذ ضظغ بسم الله 123";

    REQUIRE(std::string(ar_text) == std::string(expected));

    anltk_transliterator_free(ttor);
}

