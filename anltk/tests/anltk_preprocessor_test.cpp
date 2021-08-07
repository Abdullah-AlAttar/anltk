#include "anltk/anltk.hpp"
#include "doctest.h"
#include <iostream>
#include <string>

TEST_CASE("Presprocessor Remove tashkeel")
{
    using namespace std::string_literals;

    SUBCASE("Basic")
    {
        std::string input = "";

        REQUIRE(anltk::remove_tashkeel(input) == ""s);
    }

    SUBCASE("Basic")
    {
        std::string input = "وَلَا أَنتُمْ عَابِدُونَ مَا أَعْبُدُ";

        REQUIRE(anltk::remove_tashkeel(input) == "ولا أنتم عابدون ما أعبد"s);
    }

    SUBCASE("Mixed with non arabic ")
    {
        std::string input = "وَلَاd أَنتُمْ عَابِدُونَ مَا أَعْبُدُ";
        REQUIRE(anltk::remove_tashkeel(input) == "ولاd أنتم عابدون ما أعبد"s);
    }
    SUBCASE("Remove small")
    {
        std::string input       = "الرَّحْمَٰنِ الرَّحِيمِ";
        std::string no_tashkeel = anltk::remove_tashkeel(input);
        REQUIRE(no_tashkeel == "الرحمٰن الرحيم"s);
        REQUIRE(anltk::remove_small(no_tashkeel) == "الرحمن الرحيم"s);
    }
}

TEST_CASE("Presprocessor Remove non alpha")
{
    using namespace std::string_literals;

    SUBCASE("Empty")
    {
        std::string input = "";
        REQUIRE(anltk::remove_non_alpha(input, " ") == ""s);
    }

    SUBCASE("Basic")
    {
        std::string input = "وَلَا أَنتُمْ عَابِدُونَ مَا أَعْبُدُ";
        REQUIRE(anltk::remove_non_alpha(input, " ") == "ولا أنتم عابدون ما أعبد"s);
    }

    SUBCASE("Mixed with non arabic ")
    {
        std::string input = "وَلَاd !!!!أَنتُمْsdf 32عَابِدُونَ مَا أَعْبُدُ";

        REQUIRE(anltk::remove_non_alpha(input, " ") == "ولا أنتم عابدون ما أعبد"s);
    }
    SUBCASE("Remove multi speartor")
    {
        std::string input = "وَلَاd !!!!أَنتُمْsdf 32عَابِدُونَ مَا أَعْبُدُ";

        REQUIRE(anltk::remove_non_alpha(input, " !") == "ولا !!!!أنتم عابدون ما أعبد"s);
    }
}

TEST_CASE("Presprocessor Remove non alphanmeric")
{
    using namespace std::string_literals;

    SUBCASE("Empty")
    {
        std::string input = "";
        REQUIRE(anltk::remove_non_alphanumeric(input, " ") == ""s);
    }

    SUBCASE("Basic")
    {
        std::string input = "وَلَا أَنتُمْ عَابِدُونَ مَا أَعْبُدُ";
        REQUIRE(anltk::remove_non_alphanumeric(input, " ") == "ولا أنتم عابدون ما أعبد"s);
    }

    SUBCASE("Mixed with non arabic ")
    {
        std::string input = "وَلَاd !!!!أَنتُمْsdf 32عَابِدُونَ مَا أَعْبُدُ";

        REQUIRE(anltk::remove_non_alphanumeric(input, " ") == "ولا أنتم 32عابدون ما أعبد"s);
    }
    SUBCASE("Remove multi speartor")
    {
        std::string input = "وَلَاd d!!!!أَنتُمْsdf 32عَابِدُونَ مَا أَعْبُدُ";
        REQUIRE(anltk::remove_non_alphanumeric(input, " عd!")
                == "ولاd d!!!!أنتمd 32عابدون ما أعبد"s);
    }
}

TEST_CASE("Presprocessor Remove non alphanmeric and tashkeel")
{
    using namespace std::string_literals;

    SUBCASE("Empty")
    {
        std::string input = "";
        std::string found = anltk::remove_non_alphanumeric_and_tashkeel(input, " ");
        REQUIRE(found == ""s);
    }

    SUBCASE("Basic")
    {
        std::string input = "وَلَا أَنتُمْ عَابِدُونَ مَا أَعْبُدُ";
        std::string found = anltk::remove_non_alphanumeric_and_tashkeel(input, " ");
        REQUIRE(found == "وَلَا أَنتُمْ عَابِدُونَ مَا أَعْبُدُ"s);
    }

    SUBCASE("Mixed with non arabic ")
    {
        std::string input = "وَلَاd !!!!أَنتُمْsdf 32عَابِدُونَ مَا أَعْبُدُ";
        std::string found = anltk::remove_non_alphanumeric_and_tashkeel(input, " ");
        // وَلَا أأأأأأَنتُمْ 32ععععَابِدُونَ مَا أَعْبُدُ
        // وَلَا أَنتُمْ 32عَابِدُونَ مَا أَعْبُدُبُدُ
        REQUIRE(found == "وَلَا أَنتُمْ 32عَابِدُونَ مَا أَعْبُدُ"s);
    }
    SUBCASE("Remove multi speartor")
    {
        std::string input = "وَلَاd d!!!!أَنتُمْsdf 32عَابِدُونَ مَا أَعْبُدُ";
        std::string found = anltk::remove_non_alphanumeric_and_tashkeel(input, " d");

        REQUIRE(found == "وَلَاd dأَنتُمْd 32عَابِدُونَ مَا أَعْبُدُ"s);
    }

    SUBCASE("Remove mixed sepratred")
    {
        std::string input = "بسم الله al rahman";
        std::string found = anltk::remove_non_alpha(input, " ");

        REQUIRE(found == "بسم الله  "s);
    }
}

TEST_CASE("HAMZA Normalization")
{
    using namespace std::string_literals;

    SUBCASE("Empty")
    {
        std::string input = "";
        std::string found = anltk::normalize_hamzat(input);
        REQUIRE(found == ""s);
    }
    SUBCASE("Basic")
    {
        std::string input = "سماء";
        std::string found = anltk::normalize_hamzat(input);
        REQUIRE(found == "سماأ"s);
    }

    SUBCASE("Full")
    {
        std::string input = " يآ إمام اللؤلؤ المتلألئ في المساء";
        std::string found = anltk::normalize_hamzat(input);
        REQUIRE(found == " يأ أمام اللألأ المتلألأ في المساأ"s);
    }
    SUBCASE("Should do nothing")
    {
        std::string input = "وَلَاd d!!!!أَنتُمْsdf 32عَابِدُونَ مَا أَعْبُدُ";
        std::string found = anltk::normalize_hamzat(input);

        REQUIRE(found == "وَلَاd d!!!!أَنتُمْsdf 32عَابِدُونَ مَا أَعْبُدُ"s);
    }
}

TEST_CASE("Remove Kasheeda")
{
    using namespace std::string_literals;

    SUBCASE("Basic")
    {
        std::string input = " سـماء زرقــاء";
        std::string found = anltk::remove_kasheeda(input);
        REQUIRE(found == " سماء زرقاء"s);
    }
}

TEST_CASE("Duplicate Shadda Letters")
{
    using namespace std::string_literals;

    SUBCASE("Basic")
    {
        std::string input = "الشّمس برّاقة";
        std::string found = anltk::duplicate_shadda_letter(input);
        REQUIRE(found == "الششمس برراقة"s);
    }
}
