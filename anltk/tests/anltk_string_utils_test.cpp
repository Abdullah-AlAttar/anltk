// #include "anltk/anltk_string_utils.h"
#include <anltk/anltk_string_utils.h>

#include "doctest_include.h"



TEST_CASE("TRIM")
{
	using namespace std::string_literals;
	SUBCASE("basic string")
	{
		std::string input = " really ";
		anltk::trim(input);
		REQUIRE(input == "really");

		input = " \treally \t\n";
		anltk::trim(input);
		REQUIRE(input == "really");
	}

	SUBCASE("32")
	{
		std::u32string input = U" really ";
		anltk::trim(input);
		REQUIRE(input == U"really");

		input = U" \treally \t\n";
		anltk::trim(input);
		REQUIRE(input == U"really");
	}
}