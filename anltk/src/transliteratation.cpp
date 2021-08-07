#include "anltk/anltk.hpp"
#include <iostream>
#include "utf8.h"
// #include <tinyutf8/tinyutf8.h>

namespace anltk
{
string_t transliterate(string_view_t input, CharMapping mapping)
{
    const std::map<char_t, char_t>* chars_map;
    switch (mapping)
    {
    case CharMapping::AR2BW:
        chars_map = &arabic_to_buckwalter_;
        break;
    case CharMapping::BW2AR:
        chars_map = &buckwalter_to_arabic_;
        break;
    case CharMapping::AR2SBW:
        chars_map = &arabic_to_safe_buckwalter_;
        break;
    case CharMapping::SBW2AR:
        chars_map = &safe_buckwalter_to_arabic_;
        break;
    default:
        // TODO(abdullah): handle this
        return {};
        break;
    }

    string_t result;
    auto start = input.begin();
    auto end   = input.end();
    while (start < end)
    {
        char_t next = utf8::next(start, end);

        auto node = chars_map->find(next);

        utf8::append(node != chars_map->end() ? node->second : next, result);
    }
    return result;
}

} // namespace anltk
