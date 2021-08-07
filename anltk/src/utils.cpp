#include "anltk/anltk.hpp"

#include "utf8.h"
#include <algorithm>

namespace anltk
{
bool is_digit(char_t c)
{
    // TODO(Abdullah) This causes issues in windows, needs more testing
    // return c  >= U'0' && c <= U'9'; 
    switch (c)
    {
    case U'0':
    case U'1':
    case U'2':
    case U'3':
    case U'4':
    case U'5':
    case U'6':
    case U'7':
    case U'8':
    case U'9':
        return true;
        /* code */
        break;

    default:
        return false;
        break;
    }
}
bool is_indic_digit(char_t c)
{
    return std::find(arqam_.begin(), arqam_.end(), c) != arqam_.end();
}
bool is_tashkeel_impl(string_view_t input)
{
    if (input.empty())
    {
        return false;
    }
    auto start = input.begin();
    auto end   = input.end();
    if (utf8::distance(start, end) > 1)
    {
        return false;
    }
    return is_tashkeel(utf8::next(start, end));
}

bool is_tashkeel(char_t c)
{
    return std::find(tashkeel_list_.begin(), tashkeel_list_.end(), c) != tashkeel_list_.end();
}

bool is_arabic_alpha_impl(string_view_t input)
{
    if (input.empty())
    {
        return false;
    }

    auto start = input.begin();
    auto end   = input.end();
    if (utf8::distance(start, end) > 1)
    {
        return false;
    }
    return is_arabic_alpha(utf8::next(start, end));
}

bool is_arabic_alpha(char_t c)
{
    return std::find(alphabet_.begin(), alphabet_.end(), c) != alphabet_.end();
}

bool is_small(char_t c)
{
    return std::find(small_list_.begin(), small_list_.end(), c) != small_list_.end();
}

bool is_small_impl(string_view_t input)
{
    if (input.empty())
    {
        return false;
    }

    auto start = input.begin();
    auto end   = input.end();
    if (utf8::distance(start, end) > 1)
    {
        return false;
    }
    return is_small(utf8::next(start, end));
}

bool is_valid_kalima(string_view_t input)
{

    std::u32string text = to_32string(input);

    if (text.empty())
    {
        return false;
    }

    auto first_letter = text.front();
    if (is_tashkeel(first_letter) || first_letter == WAW_HAMZA_ABOVE
        || first_letter == YEH_HAMZA_ABOVE)
    {
        return false;
    }

    const char_t* double_shadda = U"\u0651\u0651";
    if (text.find(double_shadda) != string_t::npos)
    {
        return false;
    }

    const char_t* double_taa_teh_marboota = U"\u0629\u0629";
    if (text.find(double_taa_teh_marboota) != string_t::npos)
    {
        return false;
    }

    const char_t space = U' ';
    if (text.find(space) != string_t::npos)
    {
        return false;
    }

    // Three consecutive harakat
    if (text.length() > 3)
    {
        for (size_t i = 0; i < text.length() - 3; ++i)
        {
            if (is_tashkeel(text[i]) && is_tashkeel(text[i + 1]) && is_tashkeel(text[i + 2]))
            {
                return false;
            }
        }
    }

    // TEH_MARBOOTA or ALEF_MQSURA not at the end
    text.pop_back();
    for (auto it = text.begin(); it != text.end(); ++it)
    {
        if (*it == TEH_MARBOOTA || *it == ALEF_MAQSURA)
        {
            return false;
        }
    }

    return true;
}

std::u32string to_32string(string_view_t input)
{
    return utf8::utf8to32(input);
}

} // namespace anltk