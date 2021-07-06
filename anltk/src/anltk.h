#ifndef ANLTK_H
#define ANLTK_H
#include "utf8.h"

#include <map>

#include <anltk_algorihtm.h>
#include <anltk_typedefs.h>

namespace anltk
{


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
    const char* remove_non_alpha(string_view_t input, string_view_t stop_list);
    const char* remove_non_alphanumeric(string_view_t input, string_view_t stop_list);
    const char* remove_non_alphanumeric_and_tashkeel(string_view_t input, string_view_t stop_list);
    const char* remove_kasheeda(string_view_t input);
    const char* normalize_hamzat(string_view_t input);
    const char* duplicate_shadda_letter(string_view_t input);
    const char* extract_root(string_view_t input);

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

} // namespace anltk

#endif
