#include "anltk/anltk.hpp"
#include <algorithm>
#include <array>
#include <string>
#include <vector>

namespace anltk
{

const std::string ahaad[20]
    = { "",          "واحد",     "اثنان",   "ثلاثة",    "أربعة",      "خمسة",     "ستة",
        "سبعة",      "ثمانية",   "تسعة",    "عشرة",     "احدى عشر",   "اثنى عشر", "ثلاثة عشر",
        "اربعة عشر", "خمسة عشر", "ستة عشر", "سبعة عشر", "ثمانية عشر", "تسعة عشر" };

const std::string ahaad_ordinal[][20]
    = { { // masculine
          "",           "الواحد",     "الثاني",     "الثالث",     "الرابع",
          "الخامس",     "السادس",     "السابع",     "الثامن",     "التاسع",
          "العاشر",     "الحادي عشر", "الثاني عشر", "الثالث عشر", "الرابع عشر",
          "الخامس عشر", "السادس عشر", "السابع عشر", "الثامن عشر", "التاسع عشر" },
        { // feminine
          "",
          "الواحدة",
          "الثانية",
          "الثالثة",
          "الرابعة",
          "الخامسة",
          "السادسة",
          "السابعة",
          "الثامنة",
          "التاسعة",
          "العاشرة",
          "الحادية عشرة",
          "الثانية عشرة",
          "الثالثة عشرة",
          "الرابعة عشرة",
          "الخامسة عشرة",
          "السادسة عشرة",
          "السابعة عشرة",
          "الثامنة عشرة",
          "التاسعة عشرة" } };

const std::string asharat[10]
    = { "", "", "عشرون", "ثلاثون", "اربعون", "خمسون", "ستون", "سبعون", "ثمانون", "تسعون" };

const std::string meaat[10] = { "",       "مئة",   "مئتان",  "ثلاثمئة", "أربعمئة",
                                "خمسمئة", "ستمئة", "سبعمئة", "ثمانمئة", "تسعمئة" };

const std::array<long long, 6> alaaf_numbers
    = { 1000, 1000000, 1000000000,
        //  do we really need large numbers
        1000000000000, 1000000000000000, 1000000000000000000 };

const std::string alaaf[][4] = {
    { "", "ألف", "ألفان", "آلاف" },
    { "", "مليون", "مليونان", "ملايين" },
    { "", "مليار", "ملياران", "مليارات" },
    { "", "ترليون", "ترليونان", "ترليونات" },
    { "", "كوادريليون", "كوادريليونان", "كوادريليونات" },
    { "", "ترليار", "ترلياران", "ترليارات" },
};

bool is_between(long long num, long long lower_bound, long long upper_bound)
{
    return num > lower_bound and num < upper_bound;
}

void tafqeet_impl(long long num, std::vector<std::string>& pieces, bool is_ordinal = false,
                  bool is_feminine = false)
{
    if (num == 0)
    {
        return;
    }
    if (num < 20)
    {
        pieces.push_back(is_ordinal ? ahaad_ordinal[is_feminine ? 1 : 0][num] : ahaad[num]);
        return;
    }
    if (num < 100)
    {
        pieces.push_back(is_ordinal ? ahaad_ordinal[is_feminine ? 1 : 0][num % 10]
                                    : ahaad[num % 10]);
        pieces.push_back(is_ordinal ? "ال" + asharat[num / 10] : asharat[num / 10]);
        return;
    }
    if (num < 1000)
    {
        pieces.push_back(is_ordinal ? "ال" + meaat[num / 100] : meaat[num / 100]);
        tafqeet_impl(num % 100, pieces, is_ordinal, is_feminine);
        return;
    }

    for (size_t i = 1; i < alaaf_numbers.size(); ++i)
    {
        if (num < alaaf_numbers[i])
        {
            long long current_multiplier = alaaf_numbers[i - 1];
            long long thousands_digits   = num / current_multiplier;

            if (thousands_digits < 3)
            {
                std::string next_piece = alaaf[i - 1][thousands_digits];
                pieces.push_back(is_ordinal ? "ال" + next_piece : next_piece);
            }
            else
            {
                long long tmp = current_multiplier / 10;
                tafqeet_impl(thousands_digits, pieces, is_ordinal, is_feminine);
                pieces.back() += is_between(thousands_digits % tmp, 2, 11) ? " " + alaaf[i - 1][3]
                                                                           : " " + alaaf[i - 1][1];
            }
            tafqeet_impl(num % current_multiplier, pieces, is_ordinal, is_feminine);
            return;
        }
    }

    size_t i                     = alaaf_numbers.size();
    long long current_multiplier = alaaf_numbers[i - 1];
    long long thousands_digits   = num / current_multiplier;

    if (thousands_digits < 3)
    {
        std::string next_piece = alaaf[i - 1][thousands_digits];
        pieces.push_back(is_ordinal ? "ال" + next_piece : next_piece);
    }
    else
    {
        long long tmp = current_multiplier / 10;

        tafqeet_impl(thousands_digits, pieces, is_feminine);
        pieces.back() += is_between(thousands_digits % tmp, 2, 11) ? " " + alaaf[i - 1][3]
                                                                   : " " + alaaf[i - 1][1];
    }
    tafqeet_impl(num % current_multiplier, pieces, is_ordinal, is_feminine);
}

std::string tafqeet_internal(long long number, bool is_ordinal, bool is_feminine)
{
    bool is_negative = false;
    if (number < 0)
    {
        is_negative = true;
        number      = -number;
    }
    if (number == 0)
    {
        return std::string() + (is_negative ? "سالب " : "") + (is_ordinal ? "الصفر" : "صفر");
    }
    if (number == 1 and is_ordinal)
    {
        return std::string() + (is_negative ? "سالب " : "") + (is_feminine ? "الأولى" : "الأول");
    }

    std::vector<std::string> pieces;

    tafqeet_impl(number, pieces, is_ordinal, is_feminine);

    pieces.erase(std::remove_if(pieces.begin(), pieces.end(),
                                [](const std::string& elm) { return elm.empty(); }),
                 pieces.end());

    std::string res = pieces.front();

    for (size_t i = 1; i < pieces.size(); ++i)
    {
        if (!pieces[i].empty())
            res += " و " + pieces[i];
    }

    return (is_negative ? "سالب " : "") + res;
}


string_t tafqeet(long long number, bool is_ordinal, bool is_feminine)
{
    return tafqeet_internal(number, is_ordinal, is_feminine);
}




} // namespace anltk