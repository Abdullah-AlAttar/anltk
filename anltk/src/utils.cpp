#include "anltk.h"
#include "char_maps.h"

#include <tinyutf8/tinyutf8.h>

#include <algorithm>

namespace anltk
{

bool is_tashkeel(char32_t c)
{
    return std::find(tashkeel_list_.begin(), tashkeel_list_.end(), c) != tashkeel_list_.end();
}

bool is_valid_kalima(const char* input)
{
    tiny_utf8::string text = input;
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

    const char32_t* double_shadda = U"\u0651\u0651";
    if (text.find(double_shadda) != tiny_utf8::string::npos)
    {
        return false;
    }

    const char32_t space = U' ';
    if (text.find(space) != tiny_utf8::string::npos)
    {
        return false;
    }

    text.pop_back();
    for (auto it = text.begin(); it != text.end(); ++it)
    {
        if (*it == TEH_MARBOOTA || *it == ALEF_MAQSURA)
        {
            return false;
        }
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
    return true;
}

} // namespace anltk