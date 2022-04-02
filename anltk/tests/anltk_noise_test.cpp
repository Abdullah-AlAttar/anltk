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
	CHECK(n_gen.swap_adjacent_chars("لا يجب علينا أن نذهب") == "لا يجب لعينا أن نذهب");

	CHECK(n_gen.swap_adjacent_chars("هل يمكن", 2) == "هل ينمك");
	CHECK(n_gen.swap_adjacent_chars("هل يمكن", 3) == "هل منيك");
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

TEST_CASE("Chars Removal")
{
	// std::srand(42);
	anltk::NoiseGenerator n_gen;
	n_gen.set_seed(1);
	CHECK(n_gen.remove_random_chars("له") == "ل");
	CHECK(n_gen.remove_random_chars("له") == "ه");
	CHECK(n_gen.remove_random_chars("له") == "ه");
	CHECK(n_gen.remove_random_chars("له") == "ه");
	CHECK(n_gen.remove_random_chars("له", 2) == "");
	CHECK(n_gen.remove_random_chars("له", 3) == "");

	CHECK(n_gen.remove_random_chars("صوت صفير البلبل", 3) == "وت صفير للبل");
	CHECK(n_gen.remove_random_chars("صوت صفير البلبل", 3) == "صوت في البلب");
	CHECK(n_gen.remove_random_chars("صوت صفير البلبل", 3) == "صو صير لبلبل");

	// CHECK(n_gen.insert_random_chars("لا يجب علينا أن نذهب", 5)
	//       == "لا يجب علءيعنا أنف نرذهبء");
}


TEST_CASE("Chars Replace")
{
	// std::srand(42);
	anltk::NoiseGenerator n_gen;
	n_gen.set_seed(1);
	CHECK(n_gen.replace_random_chars("له") == "لظ");
	CHECK(n_gen.replace_random_chars("له") == "هه");
	CHECK(n_gen.replace_random_chars("له") == "لآ");
	CHECK(n_gen.replace_random_chars("له") == "لئ");
	CHECK(n_gen.replace_random_chars("له", 2) == "ءص");
	CHECK(n_gen.replace_random_chars("له", 3) == "كي");

	CHECK(n_gen.replace_random_chars("صوت صفير البلبل", 3) == "اوت صفير البلبف");
	CHECK(n_gen.replace_random_chars("صوت صفير البلبل", 3) == "صطت صفير الدلصل");
	CHECK(n_gen.replace_random_chars("صوت صفير البلبل", 3) == "صصت صفيأ الولبل");
	CHECK(n_gen.replace_random_chars("له", 0) == "له");
	CHECK(n_gen.replace_random_chars("wow", 2) == "wow"); // WIll not replace non arab

	// CHECK(n_gen.insert_random_chars("لا يجب علينا أن نذهب", 5)
	//       == "لا يجب علءيعنا أنف نرذهبء");
}
