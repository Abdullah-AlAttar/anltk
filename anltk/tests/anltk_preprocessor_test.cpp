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
    SUBCASE("Remove small")
    {
        const char *input = "الرَّحْمَٰنِ الرَّحِيمِ";
        const char *no_tashkeel = anltk_preprocessor_remove_tashkeel(p, input);
        REQUIRE(no_tashkeel == "الرحمٰن الرحيم"s);
        REQUIRE(anltk_preprocessor_remove_small(p, no_tashkeel) == "الرحمن الرحيم"s);
    }
    
}


TEST_CASE("Presprocessor Remove non alpha")
{
    using namespace std::string_literals;
    Preprocessor* p = anltk_preprocessor_new();

    SUBCASE("Basic")
    {
        const char* input = "وَلَا أَنتُمْ عَابِدُونَ مَا أَعْبُدُ";
        std::cout<< anltk_preprocessor_remove_non_alpha(p, input, " ", "")<<std::endl;
        REQUIRE(anltk_preprocessor_remove_non_alpha(p, input, " " , "") == "ولا أنتم عابدون ما أعبد"s);
    }

    SUBCASE("Mixed with non arabic ")
    {
        const char* input = "وَلَاd !!!!أَنتُمْsdf 32عَابِدُونَ مَا أَعْبُدُ";
        std::cout<< anltk_preprocessor_remove_non_alpha(p, input, " ", "")<<std::endl;

        REQUIRE(anltk_preprocessor_remove_non_alpha(p, input, " ", "") == "ولا أنتم عابدون ما أعبد"s);
    }
    SUBCASE("Remove multi speartor")
    {
        const char* input = "وَلَاd !!!!أَنتُمْsdf 32عَابِدُونَ مَا أَعْبُدُ";
        std::cout<< anltk_preprocessor_remove_non_alpha(p, input, " ,!", ",") <<std::endl;

        REQUIRE(anltk_preprocessor_remove_non_alpha(p, input, " ,!", ",") == "ولا !!!!أنتم عابدون ما أعبد"s);
    }
    
}