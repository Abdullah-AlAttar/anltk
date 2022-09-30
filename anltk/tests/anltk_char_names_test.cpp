#include "anltk/anltk.hpp"
#include "doctest_include.h"
#include <string>

TEST_CASE("Char Names")
{
	CHECK(anltk::char_name(U'ي') == "ARABIC LETTER YEH");
	CHECK(anltk::char_name(U'و') == "ARABIC LETTER WAW");
	CHECK(anltk::char_name(U'c') == "<unk>");
}