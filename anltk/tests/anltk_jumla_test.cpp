#include "anltk/anltk.hpp"
#include "doctest_include.h"


TEST_CASE("Jumla")
{
	SUBCASE("Basic")
	{
		anltk::Jumla jumla("إن السماءَ صافية, والعصافير تطير.");

		REQUIRE(jumla.size() == 5);
		REQUIRE(jumla.first()->size() == 2);
		REQUIRE(jumla.first()->next()->size() == 7);
		REQUIRE(jumla.first()->next()->next()->size() == 6);
		REQUIRE(jumla.last()->size() == 5);
		REQUIRE(jumla.last()->prev()->size() == 9);

		REQUIRE(jumla.first()->to_string() == "إن");
		REQUIRE(*jumla.first() == "إن");

		REQUIRE(jumla.last()->to_string() == "تطير.");
		REQUIRE(jumla.first()->next()->to_string() == "السماءَ");
		REQUIRE(jumla.first()->next()->next()->to_string() == "صافية,");
		REQUIRE(jumla.first()->next()->next()->next()->to_string() == "والعصافير");
		REQUIRE(jumla.first()->next()->next()->next()->next()->to_string() == "تطير.");
		REQUIRE(jumla.first()->next()->next()->next()->next()->next() == nullptr);
		REQUIRE(jumla.first()->first()->to_string() == "إ");
		REQUIRE(*jumla.first()->first() == "إ");
		REQUIRE(jumla.first()->first()->next()->to_string() == "ن");
		REQUIRE(jumla.first()->first()->next()->next() == nullptr);
		REQUIRE(jumla.first()->next()->first()->to_string() == "ا");
		REQUIRE(jumla.last()->first()->to_string() == "ت");
		REQUIRE(jumla.last()->last()->to_string() == ".");
		REQUIRE(jumla.first()->next()->last()->c() == anltk::FATHA);
		REQUIRE(*jumla.first()->next()->last() == anltk::FATHA);

		REQUIRE(jumla.first()->first()->kalima()->to_string() == "إن");
		REQUIRE(jumla.first()->first()->kalima()->next()->to_string() == "السماءَ");
		REQUIRE(jumla.to_string() == "إن السماءَ صافية, والعصافير تطير.");
		REQUIRE(jumla == "إن السماءَ صافية, والعصافير تطير.");
	}
}