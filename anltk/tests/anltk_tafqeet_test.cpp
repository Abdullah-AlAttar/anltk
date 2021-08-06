#include "anltk/anltk.hpp"
#include "doctest.h"
#include <iostream>
#include <string>

TEST_CASE("Testing Cardinal Masculine")
{
    using namespace std::string_literals;
    bool is_ordinal = false, is_feminine = false;

    CHECK(anltk::tafqeet(0, is_ordinal, is_feminine) == "صفر"s);
    CHECK(anltk::tafqeet(0, is_ordinal, is_feminine) == "صفر"s);
    CHECK(anltk::tafqeet(1, is_ordinal, is_feminine) == "واحد"s);
    CHECK(anltk::tafqeet(2, is_ordinal, is_feminine) == "اثنان"s);
    CHECK(anltk::tafqeet(3, is_ordinal, is_feminine) == "ثلاثة"s);
    CHECK(anltk::tafqeet(4, is_ordinal, is_feminine) == "أربعة"s);
    CHECK(anltk::tafqeet(5, is_ordinal, is_feminine) == "خمسة"s);
    CHECK(anltk::tafqeet(6, is_ordinal, is_feminine) == "ستة"s);
    CHECK(anltk::tafqeet(7, is_ordinal, is_feminine) == "سبعة"s);
    CHECK(anltk::tafqeet(8, is_ordinal, is_feminine) == "ثمانية"s);
    CHECK(anltk::tafqeet(9, is_ordinal, is_feminine) == "تسعة"s);

    CHECK(anltk::tafqeet(10, is_ordinal, is_feminine) == "عشرة"s);
    CHECK(anltk::tafqeet(22, is_ordinal, is_feminine) == "اثنان و عشرون"s);
    CHECK(anltk::tafqeet(30, is_ordinal, is_feminine) == "ثلاثون"s);

    CHECK(anltk::tafqeet(119, is_ordinal, is_feminine) == "مئة و تسعة عشر"s);
    CHECK(anltk::tafqeet(120, is_ordinal, is_feminine) == "مئة و عشرون"s);
    CHECK(anltk::tafqeet(199, is_ordinal, is_feminine) == "مئة و تسعة و تسعون"s);
    CHECK(anltk::tafqeet(200, is_ordinal, is_feminine) == "مئتان"s);
    CHECK(anltk::tafqeet(300, is_ordinal, is_feminine) == "ثلاثمئة"s);
    CHECK(anltk::tafqeet(311, is_ordinal, is_feminine) == "ثلاثمئة و احدى عشر"s);

    CHECK(anltk::tafqeet(1019, is_ordinal, is_feminine) == "ألف و تسعة عشر"s);
    CHECK(anltk::tafqeet(3019, is_ordinal, is_feminine) == "ثلاثة آلاف و تسعة عشر"s);
    CHECK(anltk::tafqeet(10000, is_ordinal, is_feminine) == "عشرة آلاف"s);
    CHECK(anltk::tafqeet(10500, is_ordinal, is_feminine) == "عشرة آلاف و خمسمئة"s);
    CHECK(anltk::tafqeet(100500, is_ordinal, is_feminine) == "مئة ألف و خمسمئة"s);
    CHECK(anltk::tafqeet(110500, is_ordinal, is_feminine) == "مئة و عشرة آلاف و خمسمئة"s);
    CHECK(anltk::tafqeet(-110500, is_ordinal, is_feminine) == "سالب مئة و عشرة آلاف و خمسمئة"s);

    CHECK(anltk::tafqeet(99999, is_ordinal, is_feminine)
          == "تسعة و تسعون ألف و تسعمئة و تسعة و تسعون"s);
    CHECK(anltk::tafqeet(999999, is_ordinal, is_feminine)
          == "تسعمئة و تسعة و تسعون ألف و تسعمئة و تسعة و تسعون"s);

    CHECK(anltk::tafqeet(1000000, is_ordinal, is_feminine) == "مليون"s);
    CHECK(anltk::tafqeet(1000001, is_ordinal, is_feminine) == "مليون و واحد"s);
    CHECK(anltk::tafqeet(1000101, is_ordinal, is_feminine) == "مليون و مئة و واحد"s);
    CHECK(anltk::tafqeet(5000101, is_ordinal, is_feminine) == "خمسة ملايين و مئة و واحد"s);
    CHECK(anltk::tafqeet(51000101, is_ordinal, is_feminine) == "واحد و خمسون مليون و مئة و واحد"s);

    CHECK(anltk::tafqeet(51090101, is_ordinal, is_feminine)
          == "واحد و خمسون مليون و تسعون ألف و مئة و واحد"s);
    CHECK(anltk::tafqeet(9999999)
          == "تسعة ملايين و تسعمئة و تسعة و تسعون ألف و تسعمئة و تسعة و تسعون"s);
    CHECK(anltk::tafqeet(999999999)
          == "تسعمئة و تسعة و تسعون مليون و تسعمئة و تسعة و تسعون ألف و تسعمئة و تسعة و تسعون"s);

    CHECK(anltk::tafqeet(1000000000, is_ordinal, is_feminine) == "مليار"s);
    CHECK(anltk::tafqeet(1000000001, is_ordinal, is_feminine) == "مليار و واحد"s);
    CHECK(anltk::tafqeet(10000000000, is_ordinal, is_feminine) == "عشرة مليارات"s);
    CHECK(anltk::tafqeet(1000000000000, is_ordinal, is_feminine) == "ترليون"s);
    CHECK(anltk::tafqeet(123456789)
          == "مئة و ثلاثة و عشرون مليون و أربعمئة و ستة و خمسون ألف و سبعمئة و تسعة و ثمانون"s);
    // doctest can't handle long strings
    //     CHECK(
    //   anltk_mofaqqet_tafqeet( 123456789123456789)
    //   == "مئة و ثلاثة و عشرون ترليون و أربعمئة و ستة و خمسون ترليون و سبعمئة و تسعة و ثمانون
    //   بليون و مئة و ثلاثة و عشرون مليون و أربعمئة و ستة و خمسون ألف و سبعمئة و تسعة و ثمانون"s);
    // CHECK(anltk_mofaqqet_tafqeet( 1234512345123451234)
    //       == "كوادريليون و مئتان و أربعة و ثلاثون ترليون و خمسمئة و اثنى عشر ترليون و ثلاثمئة و "
    //          "خمسة و اربعون بليون و مئة و ثلاثة و عشرون مليون و أربعمئة و واحد و خمسون ألف و
    //          مئتان " "و أربعة و ثلاثون"s);
}

TEST_CASE("Testing Ordinal Masculine")
{
    using namespace std::string_literals;

    bool is_ordinal = true, is_feminine = false;

    CHECK(anltk::tafqeet(0, is_ordinal, is_feminine) == "الصفر"s);

    CHECK(anltk::tafqeet(1, is_ordinal, is_feminine) == "الأول"s);
    CHECK(anltk::tafqeet(2, is_ordinal, is_feminine) == "الثاني"s);
    CHECK(anltk::tafqeet(3, is_ordinal, is_feminine) == "الثالث"s);
    CHECK(anltk::tafqeet(4, is_ordinal, is_feminine) == "الرابع"s);
    CHECK(anltk::tafqeet(5, is_ordinal, is_feminine) == "الخامس"s);
    CHECK(anltk::tafqeet(6, is_ordinal, is_feminine) == "السادس"s);
    CHECK(anltk::tafqeet(7, is_ordinal, is_feminine) == "السابع"s);
    CHECK(anltk::tafqeet(8, is_ordinal, is_feminine) == "الثامن"s);
    CHECK(anltk::tafqeet(9, is_ordinal, is_feminine) == "التاسع"s);

    CHECK(anltk::tafqeet(10, is_ordinal, is_feminine) == "العاشر"s);
    CHECK(anltk::tafqeet(22, is_ordinal, is_feminine) == "الثاني و العشرون"s);
    CHECK(anltk::tafqeet(30, is_ordinal, is_feminine) == "الثلاثون"s);

    CHECK(anltk::tafqeet(119, is_ordinal, is_feminine) == "المئة و التاسع عشر"s);
    CHECK(anltk::tafqeet(120, is_ordinal, is_feminine) == "المئة و العشرون"s);
    CHECK(anltk::tafqeet(199, is_ordinal, is_feminine) == "المئة و التاسع و التسعون"s);

    CHECK(anltk::tafqeet(200, is_ordinal, is_feminine) == "المئتان"s);
    CHECK(anltk::tafqeet(300, is_ordinal, is_feminine) == "الثلاثمئة"s);
    CHECK(anltk::tafqeet(311, is_ordinal, is_feminine) == "الثلاثمئة و الحادي عشر"s);

    CHECK(anltk::tafqeet(1311, is_ordinal, is_feminine) == "الألف و الثلاثمئة و الحادي عشر"s);
}

TEST_CASE("Testing Ordinal Feminine")
{
    using namespace std::string_literals;

    bool is_ordinal = true, is_feminine = true;

    CHECK(anltk::tafqeet(0, is_ordinal, is_feminine) == "الصفر"s);

    CHECK(anltk::tafqeet(1, is_ordinal, is_feminine) == "الأولى"s);
    CHECK(anltk::tafqeet(2, is_ordinal, is_feminine) == "الثانية"s);
    CHECK(anltk::tafqeet(3, is_ordinal, is_feminine) == "الثالثة"s);
    CHECK(anltk::tafqeet(4, is_ordinal, is_feminine) == "الرابعة"s);
    CHECK(anltk::tafqeet(5, is_ordinal, is_feminine) == "الخامسة"s);
    CHECK(anltk::tafqeet(6, is_ordinal, is_feminine) == "السادسة"s);
    CHECK(anltk::tafqeet(7, is_ordinal, is_feminine) == "السابعة"s);
    CHECK(anltk::tafqeet(8, is_ordinal, is_feminine) == "الثامنة"s);
    CHECK(anltk::tafqeet(9, is_ordinal, is_feminine) == "التاسعة"s);

    CHECK(anltk::tafqeet(10, is_ordinal, is_feminine) == "العاشرة"s);
    CHECK(anltk::tafqeet(22, is_ordinal, is_feminine) == "الثانية و العشرون"s);
    CHECK(anltk::tafqeet(30, is_ordinal, is_feminine) == "الثلاثون"s);

    CHECK(anltk::tafqeet(119, is_ordinal, is_feminine) == "المئة و التاسعة عشرة"s);
    CHECK(anltk::tafqeet(120, is_ordinal, is_feminine) == "المئة و العشرون"s);
    CHECK(anltk::tafqeet(199, is_ordinal, is_feminine) == "المئة و التاسعة و التسعون"s);
    CHECK(anltk::tafqeet(200, is_ordinal, is_feminine) == "المئتان"s);
    CHECK(anltk::tafqeet(300, is_ordinal, is_feminine) == "الثلاثمئة"s);
    CHECK(anltk::tafqeet(311, is_ordinal, is_feminine) == "الثلاثمئة و الحادية عشرة"s);

    CHECK(anltk::tafqeet(1311, is_ordinal, is_feminine) == "الألف و الثلاثمئة و الحادية عشرة"s);
}

TEST_CASE("Testing Cardinal Feminine")
{
    using namespace std::string_literals;
    // TODO(abdullah): not sure about these

    bool is_ordinal = false, is_feminine = true;
    CHECK(anltk::tafqeet(0, is_ordinal, is_feminine) == "صفر"s);
    CHECK(anltk::tafqeet(1, is_ordinal, is_feminine) == "واحد"s);
    CHECK(anltk::tafqeet(2, is_ordinal, is_feminine) == "اثنان"s);
    CHECK(anltk::tafqeet(3, is_ordinal, is_feminine) == "ثلاثة"s);
    CHECK(anltk::tafqeet(4, is_ordinal, is_feminine) == "أربعة"s);
    CHECK(anltk::tafqeet(5, is_ordinal, is_feminine) == "خمسة"s);
    CHECK(anltk::tafqeet(6, is_ordinal, is_feminine) == "ستة"s);
    CHECK(anltk::tafqeet(7, is_ordinal, is_feminine) == "سبعة"s);
    CHECK(anltk::tafqeet(8, is_ordinal, is_feminine) == "ثمانية"s);
    CHECK(anltk::tafqeet(9, is_ordinal, is_feminine) == "تسعة"s);

    CHECK(anltk::tafqeet(10, is_ordinal, is_feminine) == "عشرة"s);
    CHECK(anltk::tafqeet(22, is_ordinal, is_feminine) == "اثنان و عشرون"s);
    CHECK(anltk::tafqeet(30, is_ordinal, is_feminine) == "ثلاثون"s);

    CHECK(anltk::tafqeet(119, is_ordinal, is_feminine) == "مئة و تسعة عشر"s);
    CHECK(anltk::tafqeet(120, is_ordinal, is_feminine) == "مئة و عشرون"s);
    CHECK(anltk::tafqeet(199, is_ordinal, is_feminine) == "مئة و تسعة و تسعون"s);
    CHECK(anltk::tafqeet(200, is_ordinal, is_feminine) == "مئتان"s);
    CHECK(anltk::tafqeet(300, is_ordinal, is_feminine) == "ثلاثمئة"s);
    CHECK(anltk::tafqeet(311, is_ordinal, is_feminine) == "ثلاثمئة و احدى عشر"s);

    CHECK(anltk::tafqeet(1311, is_ordinal, is_feminine) == "ألف و ثلاثمئة و احدى عشر"s);
}
