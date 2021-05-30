#include "anltk/anltk_api.h"
#include "doctest.h"
#include <iostream>
#include <string>

TEST_CASE("Presprocessor")
{
    using namespace std::string_literals;
    Preprocessor* p = anltk_preprocessor_new();

    SUBCASE("Basic")
    {
        const char* input = "وَلَا أَنتُمْ عَابِدُونَ مَا أَعْبُدُ";
        REQUIRE(anltk_preprocessor_remove_tashkeel(p, input) == "ولا أنتم عابدون ما أعبد"s);
    }

    SUBCASE("Mixed with non arabic ")
    {
        const char* input = "وَلَاd أَنتُمْ عَابِدُونَ مَا أَعْبُدُ";
        REQUIRE(anltk_preprocessor_remove_tashkeel(p, input) == "ولاd أنتم عابدون ما أعبد"s);
    }
}