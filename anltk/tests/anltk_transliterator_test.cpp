


#include "anltk/anltk_api.h"

#include "doctest.h"

#include <string>



TEST_CASE("Empty")
{
    ANLTK_Transliterator* ttor = anltk_transliterator_new(CM_AR2BW);

    const char* ar_text = "";

    const char* bw_text = anltk_transliterator_convert(ttor, ar_text);


    const char* expected = "";

    REQUIRE(std::string(bw_text) == std::string(expected));
    anltk_transliterator_free(ttor);
}



TEST_CASE("Arabic to Buckwalter")
{
    ANLTK_Transliterator* ttor = anltk_transliterator_new(CM_AR2BW);

    const char* ar_text = "أبجد هوز حطي كلمن سعفص قرشت ثخذ ضظغ";

    const char* bw_text = anltk_transliterator_convert(ttor, ar_text);


    const char* expected = ">bjd hwz HTy klmn sEfS qr$t vx* DZg";

    REQUIRE(std::string(bw_text) == std::string(expected));
    anltk_transliterator_free(ttor);
}

TEST_CASE("Buckwalter to Arabic test")
{
    ANLTK_Transliterator* ttor = anltk_transliterator_new(CM_BW2AR);

    const char* bw_text = ">bjd hwz HTy klmn sEfS qr$t vx* DZg";

    const char* ar_text  = anltk_transliterator_convert(ttor, bw_text);
    const char* expected = "أبجد هوز حطي كلمن سعفص قرشت ثخذ ضظغ";

    REQUIRE(std::string(ar_text) == std::string(expected));

    anltk_transliterator_free(ttor);
}

TEST_CASE("Buckwalter to Arabic Mixed ")
{
    ANLTK_Transliterator* ttor = anltk_transliterator_new(CM_BW2AR);

    const char* bw_text = ">bjd hwz HTy klmn sEfS qr$t vx* DZg بسم الله 123";

    const char* ar_text = anltk_transliterator_convert(ttor, bw_text);
    const char* expected = "أبجد هوز حطي كلمن سعفص قرشت ثخذ ضظغ بسم الله 123";

    REQUIRE(std::string(ar_text) == std::string(expected));

    anltk_transliterator_free(ttor);
}




TEST_CASE("Arabic to Safe Buckwalter")
{
    ANLTK_Transliterator* ttor = anltk_transliterator_new(CM_AR2SBW);

    const char* ar_text = "أبجد هوز حطي كلمن سعفص قرشت ثخذ ضظغ";

    const char* bw_text = anltk_transliterator_convert(ttor, ar_text);


    const char* expected = "Objd hwz HTy klmn sEfS qrct vxV DZg";

    REQUIRE(std::string(bw_text) == std::string(expected));
    anltk_transliterator_free(ttor);
}

TEST_CASE("Safe Buckwalter to Arabic test")
{
    ANLTK_Transliterator* ttor = anltk_transliterator_new(CM_SBW2AR);

    const char* bw_text = "Objd hwz HTy klmn sEfS qrct vxV DZg";

    const char* ar_text  = anltk_transliterator_convert(ttor, bw_text);
    const char* expected = "أبجد هوز حطي كلمن سعفص قرشت ثخذ ضظغ";

    REQUIRE(std::string(ar_text) == std::string(expected));

    anltk_transliterator_free(ttor);
}