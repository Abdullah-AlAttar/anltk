#ifndef ANLTK_ALGORIHTM_H
#define ANLTK_ALGORIHTM_H

#include "anltk/anltk_typedefs.h"
#include "utf8.h"

namespace anltk
{
template <typename Func>
string_t anltk_erase_if(string_view_t input, Func&& f)
{
    auto start = input.begin();
    auto end   = input.end();

    string_t output;

    while (start < end)
    {
        char_t next = utf8::next(start, end);
        if (!f(next))
        {
            utf8::append(next, output);
        }
    }

    return output;
}
} // namespace anltk
#endif