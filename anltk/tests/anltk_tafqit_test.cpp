#include "anltk/anltk.hpp"
#include "doctest.h"
#include <iostream>
#include <string>
TEST_CASE("Testing new parameters")
{
	using namespace std::string_literals;
	anltk::TafqitOptions opts;
	SUBCASE("Default")
	{
		CHECK(anltk::tafqit(2000, opts) == "ألفان"s);
		CHECK(anltk::tafqit(2020, opts) == "ألفان وعشرون"s);
		CHECK(anltk::tafqit(15000120, opts) == "خمسة عشر مليونًا ومائة وعشرون");
		CHECK(anltk::tafqit(0, opts) == "صفر"s);
		CHECK(anltk::tafqit(1, opts) == "واحد"s);
		CHECK(anltk::tafqit(2, opts) == "اثنان"s);
		CHECK(anltk::tafqit(3, opts) == "ثلاثة"s);
		CHECK(anltk::tafqit(4, opts) == "أربعة"s);
		CHECK(anltk::tafqit(5, opts) == "خمسة"s);
		CHECK(anltk::tafqit(6, opts) == "ستة"s);
		CHECK(anltk::tafqit(7, opts) == "سبعة"s);
		CHECK(anltk::tafqit(8, opts) == "ثمانية"s);
		CHECK(anltk::tafqit(9, opts) == "تسعة"s);

		CHECK(anltk::tafqit(10, opts) == "عشرة"s);
		CHECK(anltk::tafqit(22, opts) == "اثنان وعشرون"s);
		CHECK(anltk::tafqit(30, opts) == "ثلاثون"s);

		CHECK(anltk::tafqit(119, opts) == "مائة وتسعة عشر"s);
		CHECK(anltk::tafqit(120, opts) == "مائة وعشرون"s);
		CHECK(anltk::tafqit(199, opts) == "مائة وتسعة وتسعون"s);

		CHECK(anltk::tafqit(200, opts) == "مائتان"s);

		CHECK(anltk::tafqit(300, opts) == "ثلاثمائة"s);
		CHECK(anltk::tafqit(311, opts) == "ثلاثمائة وأحد عشر"s);

		CHECK(anltk::tafqit(1019, opts) == "ألف وتسعة عشر"s);
		CHECK(anltk::tafqit(3019, opts) == "ثلاثة آلاف وتسعة عشر"s);
		CHECK(anltk::tafqit(10000, opts) == "عشرة آلاف"s);
		CHECK(anltk::tafqit(10500, opts) == "عشرة آلاف وخمسمائة"s);
		CHECK(anltk::tafqit(100500, opts) == "مائة ألف وخمسمائة"s);
		CHECK(anltk::tafqit(110500, opts) == "مائة وعشرة آلاف وخمسمائة"s);
		CHECK(anltk::tafqit(-110500, opts) == "سالب مائة وعشرة آلاف وخمسمائة"s);
		CHECK(anltk::tafqit(99999, opts) == "تسعة وتسعون ألفًا وتسعمائة وتسعة وتسعون"s);
		CHECK(anltk::tafqit(999999, opts) == "تسعمائة وتسعة وتسعون ألفًا وتسعمائة وتسعة وتسعون"s);
		CHECK(anltk::tafqit(1000000000, opts) == "مليار"s);
		CHECK(anltk::tafqit(1000000001, opts) == "مليار وواحد"s);
		CHECK(anltk::tafqit(10000000000, opts) == "عشرة مليارات"s);
		CHECK(anltk::tafqit(1000000000000, opts) == "ترليون"s);
		CHECK(anltk::tafqit(123456789)
		      == "مائة وثلاثة وعشرون مليونًا وأربعمائة وستة وخمسون ألفًا وسبعمائة وتسعة وثمانون"s);
	}
	SUBCASE("Feminine ")
	{
		opts.is_feminine = true;
		CHECK(anltk::tafqit(2000, opts) == "ألفان"s);
		CHECK(anltk::tafqit(2020, opts) == "ألفان وعشرون"s);
		CHECK(anltk::tafqit(15000120, opts) == "خمسة عشر مليونًا ومائة وعشرون");
		CHECK(anltk::tafqit(0, opts) == "صفر"s);
		CHECK(anltk::tafqit(1, opts) == "واحدة"s);
		CHECK(anltk::tafqit(2, opts) == "اثنتان"s);
		CHECK(anltk::tafqit(3, opts) == "ثلاث"s);
		CHECK(anltk::tafqit(4, opts) == "أربع"s);
		CHECK(anltk::tafqit(5, opts) == "خمس"s);
		CHECK(anltk::tafqit(6, opts) == "ست"s);
		CHECK(anltk::tafqit(7, opts) == "سبع"s);
		CHECK(anltk::tafqit(8, opts) == "ثمان"s);
		CHECK(anltk::tafqit(9, opts) == "تسع"s);

		CHECK(anltk::tafqit(10, opts) == "عشر"s);
		CHECK(anltk::tafqit(22, opts) == "اثنتان وعشرون"s);
		CHECK(anltk::tafqit(30, opts) == "ثلاثون"s);

		CHECK(anltk::tafqit(119, opts) == "مائة وتسع عشرة"s);
		CHECK(anltk::tafqit(120, opts) == "مائة وعشرون"s);
		CHECK(anltk::tafqit(199, opts) == "مائة وتسع وتسعون"s);

		CHECK(anltk::tafqit(200, opts) == "مائتان"s);

		CHECK(anltk::tafqit(300, opts) == "ثلاثمائة"s);
		CHECK(anltk::tafqit(311, opts) == "ثلاثمائة وإحدى عشرة"s);

		CHECK(anltk::tafqit(1019, opts) == "ألف وتسع عشرة"s);
		CHECK(anltk::tafqit(3019, opts) == "ثلاثة آلاف وتسع عشرة"s);
		CHECK(anltk::tafqit(10000, opts) == "عشرة آلاف"s);
		CHECK(anltk::tafqit(10500, opts) == "عشرة آلاف وخمسمائة"s);
		CHECK(anltk::tafqit(100500, opts) == "مائة ألف وخمسمائة"s);
		CHECK(anltk::tafqit(110500, opts) == "مائة وعشرة آلاف وخمسمائة"s);
		CHECK(anltk::tafqit(-110500, opts) == "سالب مائة وعشرة آلاف وخمسمائة"s);
		CHECK(anltk::tafqit(99999, opts) == "تسعة وتسعون ألفًا وتسعمائة وتسع وتسعون"s);
		CHECK(anltk::tafqit(999999, opts) == "تسعمائة وتسعة وتسعون ألفًا وتسعمائة وتسع وتسعون"s);
		CHECK(anltk::tafqit(1000000000, opts) == "مليار"s);
		CHECK(anltk::tafqit(1000000001, opts) == "مليار وواحدة"s);
		CHECK(anltk::tafqit(10000000000, opts) == "عشرة مليارات"s);
		CHECK(anltk::tafqit(1000000000000, opts) == "ترليون"s);
		CHECK(anltk::tafqit(123456789)
		      == "مائة وثلاثة وعشرون مليونًا وأربعمائة وستة وخمسون ألفًا وسبعمائة وتسعة وثمانون"s);
	}

	SUBCASE("Feminine & Comma & Miah & SplitHund")
	{
		opts.is_feminine  = true;
		opts.use_comma     = true;
		opts.use_miah      = true;
		opts.split_hundred = true;
		CHECK(anltk::tafqit(2000, opts) == "ألفان"s);
		CHECK(anltk::tafqit(2020, opts) == "ألفان، وعشرون"s);
		CHECK(anltk::tafqit(15000120, opts) == "خمسة عشر مليونًا، ومئة وعشرون");
		CHECK(anltk::tafqit(0, opts) == "صفر"s);
		CHECK(anltk::tafqit(1, opts) == "واحدة"s);
		CHECK(anltk::tafqit(2, opts) == "اثنتان"s);
		CHECK(anltk::tafqit(3, opts) == "ثلاث"s);
		CHECK(anltk::tafqit(4, opts) == "أربع"s);
		CHECK(anltk::tafqit(5, opts) == "خمس"s);
		CHECK(anltk::tafqit(6, opts) == "ست"s);
		CHECK(anltk::tafqit(7, opts) == "سبع"s);
		CHECK(anltk::tafqit(8, opts) == "ثمان"s);
		CHECK(anltk::tafqit(9, opts) == "تسع"s);

		CHECK(anltk::tafqit(10, opts) == "عشر"s);
		CHECK(anltk::tafqit(22, opts) == "اثنتان وعشرون"s);
		CHECK(anltk::tafqit(30, opts) == "ثلاثون"s);

		CHECK(anltk::tafqit(119, opts) == "مئة وتسع عشرة"s);
		CHECK(anltk::tafqit(120, opts) == "مئة وعشرون"s);
		CHECK(anltk::tafqit(199, opts) == "مئة وتسع وتسعون"s);

		CHECK(anltk::tafqit(200, opts) == "مئتان"s);

		CHECK(anltk::tafqit(300, opts) == "ثلاث مئة"s);
		CHECK(anltk::tafqit(311, opts) == "ثلاث مئة وإحدى عشرة"s);

		CHECK(anltk::tafqit(1019, opts) == "ألف، وتسع عشرة"s);
		CHECK(anltk::tafqit(3019, opts) == "ثلاثة آلاف، وتسع عشرة"s);
		CHECK(anltk::tafqit(10000, opts) == "عشرة آلاف"s);
		CHECK(anltk::tafqit(10500, opts) == "عشرة آلاف، وخمس مئة"s);
		CHECK(anltk::tafqit(100500, opts) == "مئة ألف، وخمس مئة"s);
		CHECK(anltk::tafqit(110500, opts) == "مئة وعشرة آلاف، وخمس مئة"s);
		CHECK(anltk::tafqit(-110500, opts) == "سالب مئة وعشرة آلاف، وخمس مئة"s);
		CHECK(anltk::tafqit(99999, opts) == "تسعة وتسعون ألفًا، وتسع مئة وتسع وتسعون"s);
		CHECK(anltk::tafqit(999999, opts) == "تسع مئة وتسعة وتسعون ألفًا، وتسع مئة وتسع وتسعون"s);
		CHECK(anltk::tafqit(1000000000, opts) == "مليار"s);
		CHECK(anltk::tafqit(1000000001, opts) == "مليار، وواحدة"s);
		CHECK(anltk::tafqit(10000000000, opts) == "عشرة مليارات"s);
		CHECK(anltk::tafqit(1000000000000, opts) == "ترليون"s);
		CHECK(anltk::tafqit(123456789)
		      == "مائة وثلاثة وعشرون مليونًا وأربعمائة وستة وخمسون ألفًا وسبعمائة وتسعة وثمانون"s);
	}

	SUBCASE("Billions & AG ")
	{
		opts.use_billion     = true;
		opts.is_accusative           = true;
		opts.has_followup_text = true;

		CHECK(anltk::tafqit(2000, opts) == "ألفي"s);
		CHECK(anltk::tafqit(2020, opts) == "ألفين وعشرين"s);
		CHECK(anltk::tafqit(15000120, opts) == "خمسة عشر مليونًا ومائة وعشرين");
		CHECK(anltk::tafqit(0, opts) == "صفر"s);
		CHECK(anltk::tafqit(1, opts) == "واحد"s);
		CHECK(anltk::tafqit(2, opts) == "اثنين"s);
		CHECK(anltk::tafqit(3, opts) == "ثلاثة"s);
		CHECK(anltk::tafqit(4, opts) == "أربعة"s);
		CHECK(anltk::tafqit(5, opts) == "خمسة"s);
		CHECK(anltk::tafqit(6, opts) == "ستة"s);
		CHECK(anltk::tafqit(7, opts) == "سبعة"s);
		CHECK(anltk::tafqit(8, opts) == "ثمانية"s);
		CHECK(anltk::tafqit(9, opts) == "تسعة"s);

		CHECK(anltk::tafqit(10, opts) == "عشرة"s);
		CHECK(anltk::tafqit(22, opts) == "اثنين وعشرين"s);
		CHECK(anltk::tafqit(30, opts) == "ثلاثين"s);

		CHECK(anltk::tafqit(119, opts) == "مائة وتسعة عشر"s);
		CHECK(anltk::tafqit(120, opts) == "مائة وعشرين"s);
		CHECK(anltk::tafqit(199, opts) == "مائة وتسعة وتسعين"s);

		CHECK(anltk::tafqit(200, opts) == "مائتي"s);

		CHECK(anltk::tafqit(300, opts) == "ثلاثمائة"s);
		CHECK(anltk::tafqit(311, opts) == "ثلاثمائة وأحد عشر"s);

		CHECK(anltk::tafqit(1019, opts) == "ألف وتسعة عشر"s);
		CHECK(anltk::tafqit(3019, opts) == "ثلاثة آلاف وتسعة عشر"s);
		CHECK(anltk::tafqit(10000, opts) == "عشرة آلاف"s);
		CHECK(anltk::tafqit(10500, opts) == "عشرة آلاف وخمسمائة"s);
		CHECK(anltk::tafqit(100500, opts) == "مائة ألف وخمسمائة"s);
		CHECK(anltk::tafqit(110500, opts) == "مائة وعشرة آلاف وخمسمائة"s);
		CHECK(anltk::tafqit(-110500, opts) == "سالب مائة وعشرة آلاف وخمسمائة"s);
		CHECK(anltk::tafqit(99999, opts) == "تسعة وتسعين ألفًا وتسعمائة وتسعة وتسعين"s);
		CHECK(anltk::tafqit(999999, opts) == "تسعمائة وتسعة وتسعين ألفًا وتسعمائة وتسعة وتسعين"s);
		CHECK(anltk::tafqit(1000000000, opts) == "بليون"s);
		CHECK(anltk::tafqit(1000000001, opts) == "بليون وواحد"s);
		CHECK(anltk::tafqit(10000000000, opts) == "عشرة بلايين"s);
		CHECK(anltk::tafqit(1000000000000, opts) == "ترليون"s);
		CHECK(anltk::tafqit(123456789)
		      == "مائة وثلاثة وعشرون مليونًا وأربعمائة وستة وخمسون ألفًا وسبعمائة وتسعة وثمانون"s);
	}
	SUBCASE("Subject")
	{
		opts.subjects = std::vector<std::string>{ "طالب", "طالبان", "طلاب", "طالبًا" };

		CHECK(anltk::tafqit(1, opts) == "طالب واحد"s);
		CHECK(anltk::tafqit(2, opts) == "طالبان اثنان"s);
		CHECK(anltk::tafqit(3, opts) == "ثلاثة طلاب"s);
		CHECK(anltk::tafqit(10, opts) == "عشرة طلاب"s);
		CHECK(anltk::tafqit(21, opts) == "واحد وعشرون طالبًا"s);
		CHECK(anltk::tafqit(350, opts) == "ثلاثمائة وخمسون طالبًا"s);

		opts.subjects = std::vector<std::string>{ "ليرة", "ليرتان", "ليرات", "ليرةً" };
		opts.is_feminine = true;
		CHECK(anltk::tafqit(1, opts) == "ليرة واحدة"s);
		CHECK(anltk::tafqit(2, opts) == "ليرتان اثنتان"s);
		CHECK(anltk::tafqit(3, opts) == "ثلاث ليرات"s);
		CHECK(anltk::tafqit(10, opts) == "عشر ليرات"s);
		CHECK(anltk::tafqit(21, opts) == "إحدى وعشرون ليرةً"s);
		CHECK(anltk::tafqit(350, opts) == "ثلاثمائة وخمسون ليرةً"s);
	}
	SUBCASE("Legal")
	{
		opts.use_legal_form = true;
		CHECK(anltk::tafqit(101000, opts) == "مائة ألف وألف"s);
		CHECK(anltk::tafqit(102010, opts) == "مائة ألف وألفان وعشرة"s);
		opts.use_legal_form = false;
		CHECK(anltk::tafqit(101000, opts) == "مائة وألف"s);
		CHECK(anltk::tafqit(102010, opts) == "مائة وألفان وعشرة"s);
	}
}
