// #include "anltk/anltk_string_utils.h"
#include "doctest.h"
#include <anltk/anltk_string_utils.h>
#include <iostream>
#include <string>

TEST_CASE("Starts/ends with")
{
	using namespace std::string_literals;
	using namespace std::string_view_literals;

	SUBCASE("Starts With")
	{
		REQUIRE(true == anltk::starts_with<char32_t>(U"nice", U"n")); // Works
		REQUIRE(true == anltk::starts_with("nice", "n")); // Works
		REQUIRE(true == anltk::starts_with("nice"sv, "n"sv)); //

		REQUIRE(true == anltk::starts_with(U"nice"sv, U"n"sv)); //
		REQUIRE(true == anltk::starts_with("nice"sv, "n"sv)); //
		REQUIRE(true == anltk::starts_with("حبيبي", "حب"));

		REQUIRE(true == anltk::starts_with(U"حبيبي"sv, U"حب"sv));
		REQUIRE(true == anltk::starts_with(U"حب"sv, U"حب"sv));
		REQUIRE(true == anltk::starts_with(L"حب"sv, L"حب"sv));
		REQUIRE(true == anltk::starts_with(L"حب"s, L"حب"s));
		REQUIRE(true == anltk::starts_with(L"حب", L"حب"));
		REQUIRE(true == anltk::starts_with("حبيبي"s, "حب"s));
		REQUIRE(false == anltk::starts_with(U"حبيبي"sv, U"بب"sv));
		REQUIRE(false == anltk::starts_with(U"بب"sv, U"حبيبي"sv));
		REQUIRE(false == anltk::starts_with(U"بب"s, U"حبيبي"s));
	}
	SUBCASE("Ends With")
	{
		REQUIRE(true == anltk::ends_with("nice", "e"));
		REQUIRE(true == anltk::ends_with("nice"s, "e"s));
		REQUIRE(true == anltk::ends_with(U"nice"s, U"e"s));
		REQUIRE(true == anltk::ends_with(U"nice"sv, U"e"sv));
		REQUIRE(true == anltk::ends_with(L"nice"sv, L"nice"sv));
		REQUIRE(false == anltk::ends_with(L"nice"sv, L"nic"sv));
		REQUIRE(true == anltk::ends_with(L"سمير"sv, L"مير"sv));
		REQUIRE(false == anltk::ends_with("سمير"sv, "مي"sv));
	}
}

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