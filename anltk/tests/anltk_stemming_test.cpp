#include "anltk/anltk.hpp"
#include "doctest.h"

TEST_CASE("Stemming")
{
	// SUBCASE("Basic")
	// {
	// 	std::string input = "تزخر";

	// 	std::string found    = anltk::rafal_stem(input);
	// 	std::string expected = "زخر";
	// 	REQUIRE(expected == found);
	// }
	// SUBCASE("Basic")
	// {
	// 	std::string input = "يجعلنا";

	// 	std::string found    = anltk::rafal_stem(input);
	// 	std::string expected = "جعل";
	// 	REQUIRE(expected == found);
	// }
	// SUBCASE("Basic")
	// {
	// 	std::string input = "الفسوق";

	// 	std::string found    = anltk::rafal_stem(input);
	// 	std::string expected = "فسق";
	// 	REQUIRE(expected == found);
	// }
	// SUBCASE("Basic")
	// {
	// 	std::string input = "ربه";

	// 	std::string found    = anltk::rafal_stem(input);
	// 	std::string expected = "رب";
	// 	REQUIRE(expected == found);
	// }
	// SUBCASE("Basic")
	// {
	// 	std::string input = "فسيعملون";

	// 	std::string found    = anltk::rafal_stem(input);
	// 	std::string expected = "عمل";
	// 	REQUIRE(expected == found);
	// }
	SUBCASE("Basic")
	{
		std::string input = "الواجب";

		std::string found    = anltk::rafal_stem(input);
		std::string expected = "وجب";
		REQUIRE(expected == found);
	}
	SUBCASE("Basic")
	{
		std::string input = "‫استعمالتها";

		std::string found    = anltk::rafal_stem(input);
		std::string expected = "‫عمل‬";
		REQUIRE(expected == found);
	}
	SUBCASE("Basic")
	{
		std::string input = "‫رماهم‬";

		std::string found    = anltk::rafal_stem(input);
		std::string expected = "‫رمى‬";
		REQUIRE(expected == found);
	}
	SUBCASE("Basic")
	{
		std::string input = "‫تماثيل‬";

		std::string found    = anltk::rafal_stem(input);
		std::string expected = "‫مثل‬";
		REQUIRE(expected == found);
	}

	SUBCASE("Basic")
	{
		std::string input = "‫اللذين‬";

		std::string found    = anltk::rafal_stem(input);
		std::string expected = "‫اللذين‬";
		REQUIRE(expected == found);
	}

	SUBCASE("Basic")
	{
		std::string input = "‫استقالة‬";

		std::string found    = anltk::rafal_stem(input);
		std::string expected = "‫سقل‬";
		REQUIRE(expected == found);
	}

	SUBCASE("Basic")
	{
		std::string input = "‫مخترعين‬";

		std::string found    = anltk::rafal_stem(input);
		std::string expected = "‫خرع‬";
		REQUIRE(expected == found);
	}

	SUBCASE("Basic")
	{
		std::string input = "‫كالطير‬";

		std::string found    = anltk::rafal_stem(input);
		std::string expected = "‫طير‬";
		REQUIRE(expected == found);
	}

	SUBCASE("Basic")
	{
		std::string input = "‫سيقول‬";

		std::string found    = anltk::rafal_stem(input);
		std::string expected = "‫قول‬";
		REQUIRE(expected == found);
	}
}