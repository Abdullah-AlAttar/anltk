#include "anltk/anltk.hpp"
#include "doctest.h"
#include <random>
#include <iostream>

TEST_CASE("Swap Chars")
{

	anltk::NoiseGenerator n_gen;
	n_gen.set_seed(1);
	CHECK(n_gen.swap_adjacent_chars("له") == "هل");
	CHECK(n_gen.swap_adjacent_chars("ل") == "ل");
	CHECK(n_gen.swap_adjacent_chars("") == "");

	CHECK(n_gen.swap_adjacent_chars("هل يمكن") == "هل ميكن");
	CHECK(n_gen.swap_adjacent_chars("لا يجب علينا أن نذهب") == "لا يجب علينا أن ذنهب");

	CHECK(n_gen.swap_adjacent_chars("هل يمكن", 2) == "له يكمن");
	CHECK(n_gen.swap_adjacent_chars("هل يمكن", 3) == "له يكنم");
	CHECK(n_gen.swap_adjacent_chars("هل يمكن", 5) == "له مينك");
	CHECK(n_gen.swap_adjacent_chars("له", 2) == "له");
}

TEST_CASE("Chars Insertion")
{
	// std::srand(42);
	anltk::NoiseGenerator n_gen;
	n_gen.set_seed(1);
	CHECK(n_gen.insert_random_chars("له") == "لهش");
	CHECK(n_gen.insert_random_chars("له") == "لىه");
	CHECK(n_gen.insert_random_chars("له") == "لته");
	CHECK(n_gen.insert_random_chars("له") == "لبه");

	CHECK(n_gen.insert_random_chars("ل") == "لئ");
	CHECK(n_gen.insert_random_chars("ل", 5) == "لب");
	CHECK(n_gen.insert_random_chars("") == "");
	CHECK(n_gen.insert_random_chars("هل يمكن", 2) == "هل يثمكحن");
	CHECK(n_gen.insert_random_chars("هل يمكن", 3) == "هول يآمكند");
	CHECK(n_gen.insert_random_chars("هل يمكن", 5) == "هنلد يبمظكطن");

	// CHECK(n_gen.insert_random_chars("لا يجب علينا أن نذهب", 5)
	//       == "لا يجب علءيعنا أنف نرذهبء");
}