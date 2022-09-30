#include "anltk/anltk.hpp"
#include "doctest_include.h"


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
}

TEST_CASE("Chars Removal")
{
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
}

TEST_CASE("Chars Replace")
{
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
}

TEST_CASE("Join Words")
{
	anltk::NoiseGenerator n_gen;
	n_gen.set_seed(1);
	CHECK(n_gen.join_random_words("له") == "له");
	CHECK(n_gen.join_random_words("له", 2) == "له");
	CHECK(n_gen.join_random_words("له", 3) == "له");

	CHECK(n_gen.join_random_words("صوتف صفير البلبل", 1) == "صوتف صفيرالبلبل");
	CHECK(n_gen.join_random_words("صوتف صفير البلبل", 1) == "صوتفصفير البلبل");
	CHECK(n_gen.join_random_words("صوتف صفير البلبل", 2) == "صوتفصفيرالبلبل");
	CHECK(n_gen.join_random_words("صوتف صفير البلبل", 5) == "صوتفصفيرالبلبل");
}

TEST_CASE("Swap Words")
{
	anltk::NoiseGenerator n_gen;
	n_gen.set_seed(1);
	CHECK(n_gen.swap_random_words("له") == "له");
	CHECK(n_gen.swap_random_words("له", 2) == "له");
	CHECK(n_gen.swap_random_words("له", 3) == "له");

	CHECK(n_gen.swap_random_words("صوتف صفير البلبل", 1) == "صوتف البلبل صفير");
	CHECK(n_gen.swap_random_words("صوتف صفير البلبل", 1) == "البلبل صفير صوتف");
	CHECK(n_gen.swap_random_words("صوتف صفير البلبل", 2) == "صفير البلبل صوتف");
	CHECK(n_gen.swap_random_words("صوتف صفير البلبل", 5) == "البلبل صفير صوتف");

	CHECK(n_gen.swap_random_words("واحد اثنان", 1) == "اثنان واحد");
	CHECK(n_gen.swap_random_words("واحد اثنان", 2) == "واحد اثنان");
	CHECK(n_gen.swap_random_words("واحد اثنان", 3) == "اثنان واحد");
	CHECK(n_gen.swap_random_words("واحد اثنان", 4) == "واحد اثنان");
}