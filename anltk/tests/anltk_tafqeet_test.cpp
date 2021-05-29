#include "anltk/anltk_api.h"
#include "doctest.h"
#include <iostream>
#include <string>

TEST_CASE("Testing Cardinal Masculine")
{
    using namespace std::string_literals;
    Mofaqqet* mof = anltk_mofaqqet_new(false, false);

    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 0)) == "صفر"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 0)) == "صفر"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 1)) == "واحد"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 2)) == "اثنان"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 3)) == "ثلاثة"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 4)) == "أربعة"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 5)) == "خمسة"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 6)) == "ستة"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 7)) == "سبعة"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 8)) == "ثمانية"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 9)) == "تسعة"s);

    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 10)) == "عشرة"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 22)) == "اثنان و عشرون"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 30)) == "ثلاثون"s);

    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 119)) == "مئة و تسعة عشر"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 120)) == "مئة و عشرون"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 199)) == "مئة و تسعة و تسعون"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 200)) == "مئتان"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 300)) == "ثلاثمئة"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 311)) == "ثلاثمئة و احدى عشر"s);

    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 1019)) == "ألف و تسعة عشر"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 3019)) == "ثلاثة آلاف و تسعة عشر"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 10000)) == "عشرة آلاف"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 10500)) == "عشرة آلاف و خمسمئة"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 100500)) == "مئة ألف و خمسمئة"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 110500)) == "مئة و عشرة آلاف و خمسمئة"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, -110500)) == "سالب مئة و عشرة آلاف و خمسمئة"s);

    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 99999))
          == "تسعة و تسعون ألف و تسعمئة و تسعة و تسعون"s);
    CHECK(anltk_mofaqqet_tafqeet(mof, 999999)
          == "تسعمئة و تسعة و تسعون ألف و تسعمئة و تسعة و تسعون"s);

    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 1000000)) == "مليون"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 1000001)) == "مليون و واحد"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 1000101)) == "مليون و مئة و واحد"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 5000101)) == "خمسة ملايين و مئة و واحد"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 51000101)) == "واحد و خمسون مليون و مئة و واحد"s);

    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 51090101))
          == "واحد و خمسون مليون و تسعون ألف و مئة و واحد"s);
    CHECK(anltk_mofaqqet_tafqeet(mof, 9999999)
          == "تسعة ملايين و تسعمئة و تسعة و تسعون ألف و تسعمئة و تسعة و تسعون"s);
    CHECK(anltk_mofaqqet_tafqeet(mof, 999999999)
          == "تسعمئة و تسعة و تسعون مليون و تسعمئة و تسعة و تسعون ألف و تسعمئة و تسعة و تسعون"s);

    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 1000000000)) == "مليار"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 1000000001)) == "مليار و واحد"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 10000000000)) == "عشرة مليارات"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 1000000000000)) == "ترليون"s);
    CHECK(anltk_mofaqqet_tafqeet(mof, 123456789)
          == "مئة و ثلاثة و عشرون مليون و أربعمئة و ستة و خمسون ألف و سبعمئة و تسعة و ثمانون"s);
    // doctest can't handle long strings
    //     CHECK(
    //   anltk_mofaqqet_tafqeet(mof, 123456789123456789)
    //   == "مئة و ثلاثة و عشرون ترليون و أربعمئة و ستة و خمسون ترليون و سبعمئة و تسعة و ثمانون
    //   بليون و مئة و ثلاثة و عشرون مليون و أربعمئة و ستة و خمسون ألف و سبعمئة و تسعة و ثمانون"s);
    // CHECK(anltk_mofaqqet_tafqeet(mof, 1234512345123451234)
    //       == "كوادريليون و مئتان و أربعة و ثلاثون ترليون و خمسمئة و اثنى عشر ترليون و ثلاثمئة و "
    //          "خمسة و اربعون بليون و مئة و ثلاثة و عشرون مليون و أربعمئة و واحد و خمسون ألف و
    //          مئتان " "و أربعة و ثلاثون"s);

    anltk_mofaqqet_free(mof);
}

TEST_CASE("Testing Ordinal Masculine")
{
    using namespace std::string_literals;

    Mofaqqet* mof = anltk_mofaqqet_new(true, false);

    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 0)) == "الصفر"s);

    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 1)) == "الأول"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 2)) == "الثاني"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 3)) == "الثالث"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 4)) == "الرابع"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 5)) == "الخامس"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 6)) == "السادس"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 7)) == "السابع"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 8)) == "الثامن"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 9)) == "التاسع"s);

    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 10)) == "العاشر"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 22)) == "الثاني و العشرون"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 30)) == "الثلاثون"s);

    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 119)) == "المئة و التاسع عشر"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 120)) == "المئة و العشرون"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 199)) == "المئة و التاسع و التسعون"s);

    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 200)) == "المئتان"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 300)) == "الثلاثمئة"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 311)) == "الثلاثمئة و الحادي عشر"s);

    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 1311)) == "الألف و الثلاثمئة و الحادي عشر"s);
    anltk_mofaqqet_free(mof);
}

TEST_CASE("Testing Ordinal Feminine")
{
    using namespace std::string_literals;

    Mofaqqet* mof = anltk_mofaqqet_new(true, true);

    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 0)) == "الصفر"s);

    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 1)) == "الأولى"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 2)) == "الثانية"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 3)) == "الثالثة"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 4)) == "الرابعة"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 5)) == "الخامسة"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 6)) == "السادسة"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 7)) == "السابعة"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 8)) == "الثامنة"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 9)) == "التاسعة"s);

    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 10)) == "العاشرة"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 22)) == "الثانية و العشرون"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 30)) == "الثلاثون"s);

    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 119)) == "المئة و التاسعة عشرة"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 120)) == "المئة و العشرون"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 199)) == "المئة و التاسعة و التسعون"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 200)) == "المئتان"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 300)) == "الثلاثمئة"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 311)) == "الثلاثمئة و الحادية عشرة"s);

    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 1311)) == "الألف و الثلاثمئة و الحادية عشرة"s);
    anltk_mofaqqet_free(mof);
}

TEST_CASE("Testing Cardinal Feminine")
{
    using namespace std::string_literals;
    // TODO(abdullah): not sure about these
    Mofaqqet* mof = anltk_mofaqqet_new(false, true);

    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 0)) == "صفر"s);

    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 1)) == "واحد"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 2)) == "اثنان"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 3)) == "ثلاثة"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 4)) == "أربعة"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 5)) == "خمسة"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 6)) == "ستة"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 7)) == "سبعة"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 8)) == "ثمانية"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 9)) == "تسعة"s);

    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 10)) == "عشرة"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 22)) == "اثنان و عشرون"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 30)) == "ثلاثون"s);

    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 119)) == "مئة و تسعة عشر"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 120)) == "مئة و عشرون"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 199)) == "مئة و تسعة و تسعون"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 200)) == "مئتان"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 300)) == "ثلاثمئة"s);
    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 311)) == "ثلاثمئة و احدى عشر"s);

    CHECK(std::string(anltk_mofaqqet_tafqeet(mof, 1311)) == "ألف و ثلاثمئة و احدى عشر"s);
    anltk_mofaqqet_free(mof);
}
