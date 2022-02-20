#include "anltk/anltk.hpp"
#include "doctest.h"

TEST_CASE("Char Names")
{
	CHECK(anltk::char_name(U'ي') == "ARABIC LETTER YEH");
	CHECK(anltk::char_name(U'و') == "ARABIC LETTER WAW");
	CHECK(anltk::char_name(U'c') == "<unk>");
}