


#include "anltk/anltk.hpp"

#include "doctest.h"

#include <string>



TEST_CASE("Empty")
{

    const char* ar_text = "";

    std::string bw_text = anltk::transliterate( ar_text,  anltk::CharMapping::AR2BW);


    const char* expected = "";

    REQUIRE(std::string(bw_text) == std::string(expected));
}



TEST_CASE("Arabic to Buckwalter")
{

    const char* ar_text = "أبجد هوز حطي كلمن سعفص قرشت ثخذ ضظغ";

    std::string bw_text = anltk::transliterate( ar_text,  anltk::CharMapping::AR2BW);


    const char* expected = ">bjd hwz HTy klmn sEfS qr$t vx* DZg";

    REQUIRE(std::string(bw_text) == std::string(expected));
}

TEST_CASE("Buckwalter to Arabic test")
{

    const char* bw_text = ">bjd hwz HTy klmn sEfS qr$t vx* DZg";

    std::string ar_text  = anltk::transliterate( bw_text, anltk::CharMapping::BW2AR);
    const char* expected = "أبجد هوز حطي كلمن سعفص قرشت ثخذ ضظغ";

    REQUIRE(std::string(ar_text) == std::string(expected));

}

TEST_CASE("Buckwalter to Arabic Mixed ")
{

    const char* bw_text = ">bjd hwz HTy klmn sEfS qr$t vx* DZg بسم الله 123";

    std::string ar_text = anltk::transliterate( bw_text, anltk::CharMapping::BW2AR);
    const char* expected = "أبجد هوز حطي كلمن سعفص قرشت ثخذ ضظغ بسم الله 123";

    REQUIRE(std::string(ar_text) == std::string(expected));

}




TEST_CASE("Arabic to Safe Buckwalter")
{

    const char* ar_text = "أبجد هوز حطي كلمن سعفص قرشت ثخذ ضظغ";

    std::string bw_text = anltk::transliterate( ar_text , anltk::CharMapping::AR2SBW);


    const char* expected = "Objd hwz HTy klmn sEfS qrct vxV DZg";

    REQUIRE(std::string(bw_text) == std::string(expected));
}

TEST_CASE("Safe Buckwalter to Arabic test")
{

    const char* bw_text = "Objd hwz HTy klmn sEfS qrct vxV DZg";

    std::string ar_text  = anltk::transliterate( bw_text, anltk::CharMapping::SBW2AR);
    const char* expected = "أبجد هوز حطي كلمن سعفص قرشت ثخذ ضظغ";

    REQUIRE(std::string(ar_text) == std::string(expected));

}