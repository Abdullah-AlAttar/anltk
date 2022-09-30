#include "anltk/anltk.hpp"
#include "doctest_include.h"


TEST_CASE("Normalization")
{
	// https://towardsdatascience.com/what-on-earth-is-unicode-normalization-56c005c55ad0
	SUBCASE("NFD")
	{
		std::string c_with_cedilla = "\u00C7";
		std::string c_plus_cedilla = "\u0043\u0327";

		REQUIRE(anltk::normalize_unicode(c_with_cedilla, anltk::NormalizeMode::NFD)
		        == c_plus_cedilla);
	}
	SUBCASE("NFC")
	{
		std::string c_with_cedilla = "\u00C7";
		std::string c_plus_cedilla = "\u0043\u0327";

		REQUIRE(anltk::normalize_unicode(c_plus_cedilla, anltk::NormalizeMode::NFC)
		        == c_with_cedilla);
	}
	SUBCASE("NFKD")
	{
		std::string fancy_H = "ℌ";

		REQUIRE(anltk::normalize_unicode(fancy_H, anltk::NormalizeMode::NFKD) == "H");
	}
	SUBCASE("NFKC")
	{
		std::string fancy_H_with_cedilla = "\u210B\u0327";
		std::string H_with_cedilla       = "\u1e28";
		REQUIRE(anltk::normalize_unicode(fancy_H_with_cedilla, anltk::NormalizeMode::NFKC)
		        == H_with_cedilla);
	}
}