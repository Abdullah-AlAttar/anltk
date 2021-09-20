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

TEST_CASE("Remove If")
{
	using namespace std::string_literals;

	SUBCASE("Basic")
	{
		std::string input = "الشّمس برّاقة";
		std::string found
		    = anltk::remove_if(input, " ", [](anltk::char_t c) { return anltk::is_tashkeel(c); });

		REQUIRE(found == "الشمس براقة"s);
	}

	SUBCASE("Basic1")
	{
		std::string input = "الشّم11س برّاقةd";
		std::string found = anltk::remove_if(
		    input, " ", [](anltk::char_t c) { return !anltk::is_arabic_alpha(c); }

		);

		REQUIRE(found == "الشمس براقة"s);
	}

	SUBCASE("Basic1")
	{
		std::string input = "الشّم11س برّاقةd";
		std::string found = anltk::remove_if(
		    input, " ",
		    [](anltk::char_t c) { return !anltk::is_arabic_alpha(c) || c == U'd' || c == U'1'; });

		REQUIRE(found == "الشمس براقة"s);
	}

	SUBCASE("Basic2")
	{
		std::string input = "الشّم11س برّاقةd";
		std::string found = anltk::remove_if(
		    input, " 1",
		    [](anltk::char_t c) { return !anltk::is_arabic_alpha(c) || c == U'd' || c == U'1'; });

		REQUIRE(found == "الشم11س براقة"s);
	}
}

TEST_CASE("Replace")
{

	SUBCASE("Basic")
	{
		std::string input = "يالالال يالالا";
		std::string found = anltk::replace(input, { { U'ا', U'ل' } });

		REQUIRE(found == "يلللللل يللللل");
	}

	SUBCASE("YEH")
	{
		std::string input = "سكر محلي محطوط عليه كريمة";

		std::string found = anltk::replace(
		    input, { { anltk::YEH, anltk::ALEF_MAQSURA }, { anltk::TEH_MARBOOTA, anltk::HEH } });

		REQUIRE(found == "سكر محلى محطوط علىه كرىمه");
	}

	SUBCASE("STR")
	{
		std::string input = "سكر محلي محطوط عليه كريمة";

		std::string found = anltk::replace_str(input, { { "سكر", "مش سكر" }, { "كر", "asdf" } });

		REQUIRE(found == "مش سasdf محلي محطوط عليه asdfيمة");
	}

	SUBCASE("STR2")
	{
		std::string input = "الكل يرد أن يحصل على حجر الفلاسفة";

		std::string found = anltk::replace_str(input, { { "ال", "الْ" }, { "أن", "إن" } });

		REQUIRE(found == "الْكل يرد إن يحصل على حجر الْفلاسفة");
	}

	SUBCASE("STR3")
	{
		std::string input = "بسم الله";

		std::string found = anltk::replace_str(input,
		                                       {
		                                           { "بس", "ي" },
		                                       });

		REQUIRE(found == "يم الله");
	}

	SUBCASE("STR4")
	{
		std::string input = "بسم الله";

		std::string found = anltk::replace_str(input,
		                                       {
		                                           { "بس", "" },
		                                       });

		REQUIRE(found == "م الله");
	}
	SUBCASE("STR TASHKEEL")
	{
		std::string input = "فَرَاشَةٌ مُلَوَّنَةٌ تَطِيْرُ في البُسْتَانِ، حُلْوَةٌ مُهَنْدَمَةٌ تُدْهِشُ الإِنْسَانَ";

		std::string found = anltk::replace_str(input,
		                                       {
		                                           { "فَرَ", "فر" },
		                                           { "الإِ", "الإ" },
		                                           { "في", "فِيْ" },

		                                       });

		REQUIRE(found == "فراشَةٌ مُلَوَّنَةٌ تَطِيْرُ فِيْ البُسْتَانِ، حُلْوَةٌ مُهَنْدَمَةٌ تُدْهِشُ الإنْسَانَ");
	}

	SUBCASE("STR Space")
	{
		std::string input = "بسم الله";

		std::string found = anltk::replace_str(input,
		                                       {
		                                           { "ل", "v" },
		                                           { " ", "3" },
		                                           { "الله", "d" },

		                                       });

		REQUIRE(found == "بسم3d");
	}
}

TEST_CASE("Folding ")
{

	SUBCASE("Empty")
	{
		std::string input = "";

		std::string found = anltk::fold_white_spaces(input);

		REQUIRE(found == "");
	}
	SUBCASE("Single Character")
	{
		std::string input = "ب";

		std::string found = anltk::fold_white_spaces(input);

		REQUIRE(found == "ب");
	}

	SUBCASE("Double Character")
	{
		std::string input = "  ";

		std::string found = anltk::fold_white_spaces(input);

		REQUIRE(found == " ");
	}

	SUBCASE("Basic")
	{
		std::string input = "بسم  الله";

		std::string found = anltk::fold_white_spaces(input);

		REQUIRE(found == "بسم الله");
	}
	SUBCASE("Basic1")
	{
		std::string input = "  بسم   الله  ";

		std::string found = anltk::fold_white_spaces(input);

		REQUIRE(found == " بسم الله ");
	}
	SUBCASE("New line")
	{
		std::string input = "  بسم  \n الله  ";

		std::string found = anltk::fold_white_spaces(input);

		REQUIRE(found == " بسم الله ");
	}

	SUBCASE("Tab")
	{
		std::string input = " \t بسم  \n الله  ";

		std::string found = anltk::fold_white_spaces(input);

		REQUIRE(found == " بسم الله ");
	}

	SUBCASE("Generic")
	{
		std::string input = "بببسم الله";

		std::string found = anltk::fold_if(input,
		                                   [](anltk::char_t a, anltk::char_t b) {
			                                   return (a == anltk::BEH && b == anltk::BEH)
			                                       || (a == anltk::LAM && b == anltk::LAM);
		                                   });

		REQUIRE(found == "بسم اله");
	}
}

TEST_CASE("Splitting")
{

	SUBCASE("Basic")
	{
		std::string input                 = "بسم الله";
		std::vector<std::string> found    = anltk::split(input, " ", false);
		std::vector<std::string> expected = { "بسم", "الله" };
		for (auto i : found)
		{
			std::cout << '"' << i << '"' << ',';
		}
		REQUIRE(found == expected);
	}

	SUBCASE("Long")
	{
		std::string input = ".فَرَاشَةٌ مُلَوَّنَةٌ تَطِيْرُ في البُسْتَانِ، حُلْوَةٌ مُهَنْدَمَةٌ تُدْهِشُ الإِنْسَانَ";

		std::vector<std::string> found = anltk::split(input, " ", false);
		std::vector<std::string> expected
		    = { ".فَرَاشَةٌ", "مُلَوَّنَةٌ", "تَطِيْرُ", "في", "البُسْتَانِ،", "حُلْوَةٌ", "مُهَنْدَمَةٌ", "تُدْهِشُ", "الإِنْسَانَ" };

		REQUIRE(found == expected);
	}
	SUBCASE("comma")
	{
		std::string input = ".فَرَاشَةٌ مُلَوَّنَةٌ تَطِيْرُ في البُسْتَانِ، حُلْوَةٌ مُهَنْدَمَةٌ تُدْهِشُ الإِنْسَانَ";

		std::vector<std::string> found = anltk::split(input, "،", false);
		std::vector<std::string> expected
		    = { ".فَرَاشَةٌ مُلَوَّنَةٌ تَطِيْرُ في البُسْتَانِ", " حُلْوَةٌ مُهَنْدَمَةٌ تُدْهِشُ الإِنْسَانَ" };
		for (auto i : found)
		{
			std::cout << '"' << i << '"' << ',';
		}
		REQUIRE(found == expected);

		found    = anltk::split(input, "،", true);
		expected = { ".فَرَاشَةٌ مُلَوَّنَةٌ تَطِيْرُ في البُسْتَانِ،", " حُلْوَةٌ مُهَنْدَمَةٌ تُدْهِشُ الإِنْسَانَ" };

		REQUIRE(found == expected);
	}

	SUBCASE("Multiple seperators")
	{
		std::string input = "فَرَاشَةٌ مُلَوَّنَةٌ. تَطِيْرُ في البُسْتَانِ، حُلْوَةٌ مُهَنْدَمَةٌ. تُدْهِشُ الإِنْسَانَ.";

		std::vector<std::string> found = anltk::split(input, "،.", false);
		std::vector<std::string> expected
		    = { "فَرَاشَةٌ مُلَوَّنَةٌ", " تَطِيْرُ في البُسْتَانِ", " حُلْوَةٌ مُهَنْدَمَةٌ", " تُدْهِشُ الإِنْسَانَ" };

		REQUIRE(found == expected);

		found    = anltk::split(input, "،.", true);
		expected = { "فَرَاشَةٌ مُلَوَّنَةٌ.", " تَطِيْرُ في البُسْتَانِ،", " حُلْوَةٌ مُهَنْدَمَةٌ.", " تُدْهِشُ الإِنْسَانَ." };
		for (auto i : found)
		{
			std::cout << '"' << i << '"' << ',';
		}
		REQUIRE(found == expected);
	}

	SUBCASE("Surround")
	{
		std::string input = ".بسم.";

		std::vector<std::string> found    = anltk::split(input, "،.", false);
		std::vector<std::string> expected = { "بسم" };

		REQUIRE(found == expected);

		found    = anltk::split(input, "،.", true);
		expected = { ".", "بسم." };
		std::cout << std::endl;
		for (auto i : found)
		{
			std::cout << '"' << i << '"' << ',';
		}
		REQUIRE(found == expected);
	}

	SUBCASE("English")
	{
		std::string input = "Is this a real life, or it's just a fantasy.";

		std::vector<std::string> found    = anltk::split(input, ",.", false);
		std::vector<std::string> expected = { "Is this a real life", " or it's just a fantasy" };

		REQUIRE(found == expected);

		found    = anltk::split(input, ",.", true);
		expected = { "Is this a real life,", " or it's just a fantasy." };

		REQUIRE(found == expected);
	}
}