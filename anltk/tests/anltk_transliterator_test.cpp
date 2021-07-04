


#include "anltk/anltk_api.h"

#include "doctest.h"

#include <string>



TEST_CASE("Arabic to Buckwalter")
{
    Transliterator* ttor = anltk_transliterator_new(CM_AR2BW);

    const char* ar_text = "أبجد هوز حطي كلمن سعفص قرشت ثخذ ضظغ";

    const char* bw_text = anltk_transliterator_convert(ttor, ar_text);


    const char* expected = ">bjd hwz HTy klmn sEfS qr$t vx* DZg";

    REQUIRE(std::string(bw_text) == std::string(expected));
    anltk_transliterator_free(ttor);
}

TEST_CASE("Buckwalter to Arabic test")
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

