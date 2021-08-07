#include <anltk/anltk.hpp>
#include "utf8.h"
namespace anltk
{

template <typename Iter, typename F>
string_t parse_sequence(char_t& next, Iter& start, Iter end, bool& done, F&& predicate)
{
    string_t res;
    utf8::append(next, res);
    next = utf8::next(start, end);
    while (true)
    {
        if (!predicate(next))
        {
            done = (start == end);
            break;
        }
        utf8::append(next, res);
        if (start == end)
        {
            break;
        }
        next = utf8::next(start, end);
    }
    return res;
}

vector_t<string_t> tokenize_words(string_view_t input)
{
    vector_t<string_t> result;
    if (input.empty())
    {
        return result;
    }

    auto start = input.begin();
    auto end   = input.end();

    char_t next = utf8::next(start, end);
    bool done   = false;

    while (start != end)
    {

        if (isspace(next))
        {
            next = utf8::next(start, end);
            continue;
        }

        if (is_arabic_alpha(next) || is_tashkeel(next))
        {
            result.push_back(parse_sequence(next, start, end, done,
                                            [](char_t c)
                                            { return is_arabic_alpha(c) || is_tashkeel(c); }));
        }
        else
        {
            result.push_back(parse_sequence(next, start, end, done,
                                            [](char_t c)
                                            { return !is_arabic_alpha(c) && !isspace(c); }));
        }
        // To handle last character, if it didn't belong to the previous sequence eg : "بسم."
        if (done)
        {
            string_t last;
            utf8::append(next, last);
            result.push_back(std::move(last));
        }
    }

    return result;
}

} // namespace anltk
