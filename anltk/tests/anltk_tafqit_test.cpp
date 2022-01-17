#include "anltk/anltk.hpp"
#include "doctest.h"
#include <iostream>
#include <string>
TEST_CASE("Testing new parameters")
{
	using namespace std::string_literals;
	anltk::TafqeetOpts opts;
	SUBCASE("Default")
	{
		CHECK(anltk::tafqit(2000) == "ألفان"s);
		CHECK(anltk::tafqit(2020) == "ألفان وعشرون"s);
		CHECK(anltk::tafqit(15000120) == "خمسة عشر مليونًا ومائة وعشرون");
		CHECK(anltk::tafqit(0) == "صفر"s);
		CHECK(anltk::tafqit(0) == "صفر"s);
		CHECK(anltk::tafqit(1) == "واحد"s);
		CHECK(anltk::tafqit(2) == "اثنان"s);
		CHECK(anltk::tafqit(3) == "ثلاثة"s);
		CHECK(anltk::tafqit(4) == "أربعة"s);
		CHECK(anltk::tafqit(5) == "خمسة"s);
		CHECK(anltk::tafqit(6) == "ستة"s);
		CHECK(anltk::tafqit(7) == "سبعة"s);
		CHECK(anltk::tafqit(8) == "ثمانية"s);
		CHECK(anltk::tafqit(9) == "تسعة"s);

		CHECK(anltk::tafqit(10) == "عشرة"s);
		CHECK(anltk::tafqit(22) == "اثنان وعشرون"s);
		CHECK(anltk::tafqit(30) == "ثلاثون"s);

		CHECK(anltk::tafqit(119) == "مائة وتسعة عشر"s);
		CHECK(anltk::tafqit(120) == "مائة وعشرون"s);
		CHECK(anltk::tafqit(199) == "مائة وتسعة وتسعون"s);

		CHECK(anltk::tafqit(200) == "مائتان"s);

		CHECK(anltk::tafqit(300) == "ثلاثمائة"s);
		CHECK(anltk::tafqit(311) == "ثلاثمائة وأحد عشر"s);

		CHECK(anltk::tafqit(1019) == "ألف وتسعة عشر"s);
		CHECK(anltk::tafqit(3019) == "ثلاثة آلاف وتسعة عشر"s);
		CHECK(anltk::tafqit(10000) == "عشرة آلاف"s);
		CHECK(anltk::tafqit(10500) == "عشرة آلاف وخمسمائة"s);
		CHECK(anltk::tafqit(100500) == "مائة ألف وخمسمائة"s);
		CHECK(anltk::tafqit(110500) == "مائة وعشرة آلاف وخمسمائة"s);
		CHECK(anltk::tafqit(-110500) == "سالب مائة وعشرة آلاف وخمسمائة"s);
		CHECK(anltk::tafqit(99999) == "تسعة وتسعون ألفًا وتسعمائة وتسعة وتسعون"s);
		CHECK(anltk::tafqit(999999) == "تسعمائة وتسعة وتسعون ألفًا وتسعمائة وتسعة وتسعون"s);
		CHECK(anltk::tafqit(1000000000) == "مليار"s);
		CHECK(anltk::tafqit(1000000001) == "مليار وواحد"s);
		CHECK(anltk::tafqit(10000000000) == "عشرة مليارات"s);
		CHECK(anltk::tafqit(1000000000000) == "ترليون"s);
		CHECK(anltk::tafqit(123456789)
		      == "مائة وثلاثة وعشرون مليونًا وأربعمائة وستة وخمسون ألفًا وسبعمائة وتسعة وثمانون"s);
	}
}

// TEST_CASE("Testing Cardinal Masculine")
// {
// 	using namespace std::string_literals;

// 	bool is_ordinal = false, is_feminine = false;

// 	CHECK(anltk::tafqeet(0) == "صفر"s);
// 	CHECK(anltk::tafqeet(0) == "صفر"s);
// 	CHECK(anltk::tafqeet(1) == "واحد"s);
// 	CHECK(anltk::tafqeet(2) == "اثنان"s);
// 	CHECK(anltk::tafqeet(3) == "ثلاثة"s);
// 	CHECK(anltk::tafqeet(4) == "أربعة"s);
// 	CHECK(anltk::tafqeet(5) == "خمسة"s);
// 	CHECK(anltk::tafqeet(6) == "ستة"s);
// 	CHECK(anltk::tafqeet(7) == "سبعة"s);
// 	CHECK(anltk::tafqeet(8) == "ثمانية"s);
// 	CHECK(anltk::tafqeet(9) == "تسعة"s);

// 	CHECK(anltk::tafqeet(10) == "عشرة"s);
// 	CHECK(anltk::tafqeet(22) == "اثنان و عشرون"s);
// 	CHECK(anltk::tafqeet(30) == "ثلاثون"s);

// 	CHECK(anltk::tafqeet(119) == "مائة و تسعة عشر"s);
// 	CHECK(anltk::tafqeet(120) == "مائة و عشرون"s);
// 	CHECK(anltk::tafqeet(199) == "مائة و تسعة و تسعون"s);
// 	CHECK(anltk::tafqeet(200) == "مئتان"s);
// 	CHECK(anltk::tafqeet(300) == "ثلاثمائة"s);
// 	CHECK(anltk::tafqeet(311) == "ثلاثمائة و احدى عشر"s);

// 	CHECK(anltk::tafqeet(1019) == "ألف و تسعة عشر"s);
// 	CHECK(anltk::tafqeet(3019) == "ثلاثة آلاف و تسعة عشر"s);
// 	CHECK(anltk::tafqeet(10000) == "عشرة آلاف"s);
// 	CHECK(anltk::tafqeet(10500) == "عشرة آلاف و خمسمائة"s);
// 	CHECK(anltk::tafqeet(100500) == "مائة ألف و خمسمائة"s);
// 	CHECK(anltk::tafqeet(110500) == "مائة و عشرة آلاف و خمسمائة"s);
// 	CHECK(anltk::tafqeet(-110500) == "سالب مائة و عشرة آلاف و خمسمائة"s);

// 	CHECK(anltk::tafqeet(99999)
// 	      == "تسعة و تسعون ألف و تسعمائة و تسعة و تسعون"s);
// 	CHECK(anltk::tafqeet(999999)
// 	      == "تسعمائة و تسعة و تسعون ألف و تسعمائة و تسعة و تسعون"s);

// 	CHECK(anltk::tafqeet(1000000) == "مليون"s);
// 	CHECK(anltk::tafqeet(1000001) == "مليون و واحد"s);
// 	CHECK(anltk::tafqeet(1000101) == "مليون و مائة و واحد"s);
// 	CHECK(anltk::tafqeet(5000101) == "خمسة ملايين و مائة و واحد"s);
// 	CHECK(anltk::tafqeet(51000101) == "واحد و خمسون مليون و مائة و واحد"s);

// 	CHECK(anltk::tafqeet(51090101)
// 	      == "واحد و خمسون مليون و تسعون ألف و مائة و واحد"s);
// 	CHECK(anltk::tafqeet(9999999)
// 	      == "تسعة ملايين و تسعمائة و تسعة و تسعون ألف و تسعمائة و تسعة و تسعون"s);
// 	CHECK(anltk::tafqeet(999999999)
// 	      == "تسعمائة و تسعة و تسعون مليون و تسعمائة و تسعة و تسعون ألف و تسعمائة و تسعة و تسعون"s);

// 	CHECK(anltk::tafqeet(1000000000) == "مليار"s);
// 	CHECK(anltk::tafqeet(1000000001) == "مليار و واحد"s);
// 	CHECK(anltk::tafqeet(10000000000) == "عشرة مليارات"s);
// 	CHECK(anltk::tafqeet(1000000000000) == "ترليون"s);
// 	CHECK(anltk::tafqeet(123456789)
// 	      == "مائة و ثلاثة و عشرون مليون و أربعمائة و ستة و خمسون ألف و سبعمائة و تسعة و ثمانون"s);
// 	// doctest can't handle long strings
// 	//     CHECK(
// 	//   anltk_mofaqqet_tafqeet( 123456789123456789)
// 	//   == "مائة و ثلاثة و عشرون ترليون و أربعمائة و ستة و خمسون ترليون و سبعمائة و تسعة و ثمانون
// 	//   بليون و مائة و ثلاثة و عشرون مليون و أربعمائة و ستة و خمسون ألف و سبعمائة و تسعة و
// ثمانون"s);
// 	// CHECK(anltk_mofaqqet_tafqeet( 1234512345123451234)
// 	//       == "كوادريليون و مئتان و أربعة و ثلاثون ترليون و خمسمائة و اثنى عشر ترليون و ثلاثمائة و
// "
// 	//          "خمسة و اربعون بليون و مائة و ثلاثة و عشرون مليون و أربعمائة و واحد و خمسون ألف و
// 	//          مئتان " "و أربعة و ثلاثون"s);
// }

// TEST_CASE("Testing Ordinal Masculine")
// {
// 	using namespace std::string_literals;

// 	bool is_ordinal = true, is_feminine = false;

// 	CHECK(anltk::tafqeet(0) == "الصفر"s);

// 	CHECK(anltk::tafqeet(1) == "الأول"s);
// 	CHECK(anltk::tafqeet(2) == "الثاني"s);
// 	CHECK(anltk::tafqeet(3) == "الثالث"s);
// 	CHECK(anltk::tafqeet(4) == "الرابع"s);
// 	CHECK(anltk::tafqeet(5) == "الخامس"s);
// 	CHECK(anltk::tafqeet(6) == "السادس"s);
// 	CHECK(anltk::tafqeet(7) == "السابع"s);
// 	CHECK(anltk::tafqeet(8) == "الثامن"s);
// 	CHECK(anltk::tafqeet(9) == "التاسع"s);

// 	CHECK(anltk::tafqeet(10) == "العاشر"s);
// 	CHECK(anltk::tafqeet(22) == "الثاني و العشرون"s);
// 	CHECK(anltk::tafqeet(30) == "الثلاثون"s);

// 	CHECK(anltk::tafqeet(119) == "المائة و التاسع عشر"s);
// 	CHECK(anltk::tafqeet(120) == "المائة و العشرون"s);
// 	CHECK(anltk::tafqeet(199) == "المائة و التاسع و التسعون"s);

// 	CHECK(anltk::tafqeet(200) == "المئتان"s);
// 	CHECK(anltk::tafqeet(300) == "الثلاثمائة"s);
// 	CHECK(anltk::tafqeet(311) == "الثلاثمائة و الحادي عشر"s);

// 	CHECK(anltk::tafqeet(1311) == "الألف و الثلاثمائة و الحادي عشر"s);
// }

// TEST_CASE("Testing Ordinal Feminine")
// {
// 	using namespace std::string_literals;

// 	bool is_ordinal = true, is_feminine = true;

// 	CHECK(anltk::tafqeet(0) == "الصفر"s);

// 	CHECK(anltk::tafqeet(1) == "الأولى"s);
// 	CHECK(anltk::tafqeet(2) == "الثانية"s);
// 	CHECK(anltk::tafqeet(3) == "الثالثة"s);
// 	CHECK(anltk::tafqeet(4) == "الرابعة"s);
// 	CHECK(anltk::tafqeet(5) == "الخامسة"s);
// 	CHECK(anltk::tafqeet(6) == "السادسة"s);
// 	CHECK(anltk::tafqeet(7) == "السابعة"s);
// 	CHECK(anltk::tafqeet(8) == "الثامنة"s);
// 	CHECK(anltk::tafqeet(9) == "التاسعة"s);

// 	CHECK(anltk::tafqeet(10) == "العاشرة"s);
// 	CHECK(anltk::tafqeet(22) == "الثانية و العشرون"s);
// 	CHECK(anltk::tafqeet(30) == "الثلاثون"s);

// 	CHECK(anltk::tafqeet(119) == "المائة و التاسعة عشرة"s);
// 	CHECK(anltk::tafqeet(120) == "المائة و العشرون"s);
// 	CHECK(anltk::tafqeet(199) == "المائة و التاسعة و التسعون"s);
// 	CHECK(anltk::tafqeet(200) == "المئتان"s);
// 	CHECK(anltk::tafqeet(300) == "الثلاثمائة"s);
// 	CHECK(anltk::tafqeet(311) == "الثلاثمائة و الحادية عشرة"s);

// 	CHECK(anltk::tafqeet(1311) == "الألف و الثلاثمائة و الحادية عشرة"s);
// }

// TEST_CASE("Testing Cardinal Feminine")
// {
// 	using namespace std::string_literals;
// 	// TODO(abdullah): not sure about these

// 	bool is_ordinal = false, is_feminine = true;
// 	CHECK(anltk::tafqeet(0) == "صفر"s);
// 	CHECK(anltk::tafqeet(1) == "واحد"s);
// 	CHECK(anltk::tafqeet(2) == "اثنان"s);
// 	CHECK(anltk::tafqeet(3) == "ثلاثة"s);
// 	CHECK(anltk::tafqeet(4) == "أربعة"s);
// 	CHECK(anltk::tafqeet(5) == "خمسة"s);
// 	CHECK(anltk::tafqeet(6) == "ستة"s);
// 	CHECK(anltk::tafqeet(7) == "سبعة"s);
// 	CHECK(anltk::tafqeet(8) == "ثمانية"s);
// 	CHECK(anltk::tafqeet(9) == "تسعة"s);

// 	CHECK(anltk::tafqeet(10) == "عشرة"s);
// 	CHECK(anltk::tafqeet(22) == "اثنان و عشرون"s);
// 	CHECK(anltk::tafqeet(30) == "ثلاثون"s);

// 	CHECK(anltk::tafqeet(119) == "مائة و تسعة عشر"s);
// 	CHECK(anltk::tafqeet(120) == "مائة و عشرون"s);
// 	CHECK(anltk::tafqeet(199) == "مائة و تسعة و تسعون"s);
// 	CHECK(anltk::tafqeet(200) == "مئتان"s);
// 	CHECK(anltk::tafqeet(300) == "ثلاثمائة"s);
// 	CHECK(anltk::tafqeet(311) == "ثلاثمائة و احدى عشر"s);

// 	CHECK(anltk::tafqeet(1311) == "ألف و ثلاثمائة و احدى عشر"s);
// }
