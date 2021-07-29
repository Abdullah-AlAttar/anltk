#include "anltk/anltk_api.h"
#include "doctest.h"
#include <iostream>
#include <string>

TEST_CASE("Presprocessor Remove tashkeel")
{
    using namespace std::string_literals;
    ANLTK_Preprocessor* p = anltk_preprocessor_new();

    SUBCASE("Basic")
    {
        const char* input = "";

        REQUIRE(anltk_preprocessor_remove_tashkeel(p, input) == ""s);
    }

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
        const char* input       = "الرَّحْمَٰنِ الرَّحِيمِ";
        const char* no_tashkeel = anltk_preprocessor_remove_tashkeel(p, input);
        REQUIRE(no_tashkeel == "الرحمٰن الرحيم"s);
        REQUIRE(anltk_preprocessor_remove_small(p, no_tashkeel) == "الرحمن الرحيم"s);
    }
    anltk_preprocessor_free(p);
}

TEST_CASE("Presprocessor Remove non alpha")
{
    using namespace std::string_literals;
    ANLTK_Preprocessor* p = anltk_preprocessor_new();

    SUBCASE("Empty")
    {
        const char* input = "";
        REQUIRE(anltk_preprocessor_remove_non_alpha(p, input, " ") == ""s);
    }

    SUBCASE("Basic")
    {
        const char* input = "وَلَا أَنتُمْ عَابِدُونَ مَا أَعْبُدُ";
        REQUIRE(anltk_preprocessor_remove_non_alpha(p, input, " ") == "ولا أنتم عابدون ما أعبد"s);
    }

    SUBCASE("Mixed with non arabic ")
    {
        const char* input = "وَلَاd !!!!أَنتُمْsdf 32عَابِدُونَ مَا أَعْبُدُ";

        REQUIRE(anltk_preprocessor_remove_non_alpha(p, input, " ") == "ولا أنتم عابدون ما أعبد"s);
    }
    SUBCASE("Remove multi speartor")
    {
        const char* input = "وَلَاd !!!!أَنتُمْsdf 32عَابِدُونَ مَا أَعْبُدُ";

        REQUIRE(anltk_preprocessor_remove_non_alpha(p, input, " !")
                == "ولا !!!!أنتم عابدون ما أعبد"s);
    }
    anltk_preprocessor_free(p);
}

TEST_CASE("Presprocessor Remove non alphanmeric")
{
    using namespace std::string_literals;
    ANLTK_Preprocessor* p = anltk_preprocessor_new();

    SUBCASE("Empty")
    {
        const char* input = "";
        REQUIRE(anltk_preprocessor_remove_non_alphanumeric(p, input, " ") == ""s);
    }

    SUBCASE("Basic")
    {
        const char* input = "وَلَا أَنتُمْ عَابِدُونَ مَا أَعْبُدُ";
        REQUIRE(anltk_preprocessor_remove_non_alphanumeric(p, input, " ")
                == "ولا أنتم عابدون ما أعبد"s);
    }

    SUBCASE("Mixed with non arabic ")
    {
        const char* input = "وَلَاd !!!!أَنتُمْsdf 32عَابِدُونَ مَا أَعْبُدُ";

        REQUIRE(anltk_preprocessor_remove_non_alphanumeric(p, input, " ")
                == "ولا أنتم 32عابدون ما أعبد"s);
    }
    SUBCASE("Remove multi speartor")
    {
        const char* input = "وَلَاd d!!!!أَنتُمْsdf 32عَابِدُونَ مَا أَعْبُدُ";
        REQUIRE(anltk_preprocessor_remove_non_alphanumeric(p, input, " عd!")
                == "ولاd d!!!!أنتمd 32عابدون ما أعبد"s);
    }
    anltk_preprocessor_free(p);
}

TEST_CASE("Presprocessor Remove non alphanmeric and tashkeel")
{
    using namespace std::string_literals;
    ANLTK_Preprocessor* p = anltk_preprocessor_new();

    SUBCASE("Empty")
    {
        const char* input = "";
        const char* found = anltk_preprocessor_remove_non_alphanumeric_and_tashkeel(p, input, " ");
        REQUIRE(found == ""s);
    }

    SUBCASE("Basic")
    {
        const char* input = "وَلَا أَنتُمْ عَابِدُونَ مَا أَعْبُدُ";
        const char* found = anltk_preprocessor_remove_non_alphanumeric_and_tashkeel(p, input, " ");
        REQUIRE(found == "وَلَا أَنتُمْ عَابِدُونَ مَا أَعْبُدُ"s);
    }

    SUBCASE("Mixed with non arabic ")
    {
        const char* input = "وَلَاd !!!!أَنتُمْsdf 32عَابِدُونَ مَا أَعْبُدُ";
        const char* found = anltk_preprocessor_remove_non_alphanumeric_and_tashkeel(p, input, " ");
        // وَلَا أأأأأأَنتُمْ 32ععععَابِدُونَ مَا أَعْبُدُ
        // وَلَا أَنتُمْ 32عَابِدُونَ مَا أَعْبُدُبُدُ
        REQUIRE(found == "وَلَا أَنتُمْ 32عَابِدُونَ مَا أَعْبُدُ"s);
    }
    SUBCASE("Remove multi speartor")
    {
        const char* input = "وَلَاd d!!!!أَنتُمْsdf 32عَابِدُونَ مَا أَعْبُدُ";
        const char* found = anltk_preprocessor_remove_non_alphanumeric_and_tashkeel(p, input, " d");

        REQUIRE(found == "وَلَاd dأَنتُمْd 32عَابِدُونَ مَا أَعْبُدُ"s);
    }

    SUBCASE("Remove mixed sepratred")
    {
        const char* input = "بسم الله al rahman";
        const char* found = anltk_preprocessor_remove_non_alpha(p, input, " ");

        REQUIRE(found == "بسم الله  "s);
    }
    anltk_preprocessor_free(p);
}

TEST_CASE("HAMZA Normalization")
{
    using namespace std::string_literals;
    ANLTK_Preprocessor* p = anltk_preprocessor_new();

    SUBCASE("Empty")
    {
        const char* input = "";
        const char* found = anltk_preprocessor_normalize_hamzat(p, input);
        REQUIRE(found == ""s);
    }
    SUBCASE("Basic")
    {
        const char* input = "سماء";
        const char* found = anltk_preprocessor_normalize_hamzat(p, input);
        REQUIRE(found == "سماأ"s);
    }

    SUBCASE("Full")
    {
        const char* input = " يآ إمام اللؤلؤ المتلألئ في المساء";
        const char* found = anltk_preprocessor_normalize_hamzat(p, input);
        REQUIRE(found == " يأ أمام اللألأ المتلألأ في المساأ"s);
    }
    SUBCASE("Should do nothing")
    {
        const char* input = "وَلَاd d!!!!أَنتُمْsdf 32عَابِدُونَ مَا أَعْبُدُ";
        const char* found = anltk_preprocessor_normalize_hamzat(p, input);

        REQUIRE(found == "وَلَاd d!!!!أَنتُمْsdf 32عَابِدُونَ مَا أَعْبُدُ"s);
    }
    anltk_preprocessor_free(p);
}

TEST_CASE("Remove Kasheeda")
{
    using namespace std::string_literals;
    ANLTK_Preprocessor* p = anltk_preprocessor_new();

    SUBCASE("Basic")
    {
        const char* input = " سـماء زرقــاء";
        const char* found = anltk_preprocessor_remove_kasheeda(p, input);
        REQUIRE(found == " سماء زرقاء"s);
    }
    anltk_preprocessor_free(p);
}

TEST_CASE("Duplicate Shadda Letters")
{
    using namespace std::string_literals;
    ANLTK_Preprocessor* p = anltk_preprocessor_new();

    SUBCASE("Basic")
    {
        const char* input = "الشّمس برّاقة";
        const char* found = anltk_preprocessor_duplicate_shadda_letter(p, input);
        REQUIRE(found == "الششمس برراقة"s);
    }
    anltk_preprocessor_free(p);
}
