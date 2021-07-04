#ifndef ANLTK_H
#define ANLTK_H
#include "utf8.h"

#include <map>

#include <anltk_typedefs.h>

namespace anltk
{

// using string_t = std::u32string;

enum class Mappings
{
    AR2BW,
    BW2AR
};
class Transliterator
{
public:
    Transliterator(Mappings);
    ~Transliterator() = default;
    const char* convert(string_view_t);

private:
    string_t result_;
    const std::map<char_t, char_t>* chars_map_;
};

class Mofaqqet
{
public:
    Mofaqqet(bool is_ordinal, bool is_feminine);
    ~Mofaqqet() = default;
    const char* tafqeet(long long number);

private:
    string_t result_;
    bool is_ordinal_;
    bool is_feminine_;
};

class Preprocessor
{
public:
    Preprocessor();
    ~Preprocessor() = default;
    const char* remove_tashkeel(string_view_t input);
    const char* remove_small(string_view_t input);
    const char* remove_non_alpha(string_view_t input, const char* stop_list);
    const char* remove_non_alphanumeric(string_view_t input, const char* stop_list);
    const char* remove_non_alphanumeric_and_tashkeel(string_view_t input, const char* stop_list);

private:
    string_t result_;
};

bool is_tashkeel(string_view_t input);

bool is_tashkeel(char_t c);

bool is_arabic_alpha(string_view_t input);

bool is_arabic_alpha(char_t c);

bool is_valid_kalima(string_view_t input);

bool is_small(char_t c);

bool is_small(string_view_t input);

bool is_indic_digit(char_t c);

std::u32string to_32string(string_view_t input);

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
