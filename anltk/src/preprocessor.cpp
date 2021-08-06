#include "anltk/anltk.hpp"
#include "anltk_algorithm.h"


#include <algorithm>
#include <iostream>
#include <vector>

namespace anltk
{

Preprocessor::Preprocessor()
{
}

const char* Preprocessor::remove_tashkeel(string_view_t input)
{
    this->result_ = anltk_erase_if(input, [](char_t c) { return anltk::is_tashkeel(c); });

    return this->result_.c_str();
}

const char* Preprocessor::remove_small(string_view_t input)
{
    this->result_ = anltk_erase_if(input, [](char_t c) { return anltk::is_small(c); });

    return this->result_.c_str();
}

const char* Preprocessor::remove_non_alpha(string_view_t input, string_view_t stop_list)
{
    std::u32string stop_list_ = to_32string(stop_list);

    this->result_ = anltk_erase_if(input,
                                   [&](char_t c)
                                   {
                                       return !anltk::is_arabic_alpha(c)
                                           && std::find(stop_list_.begin(), stop_list_.end(), c)
                                           == stop_list_.end();
                                   });

    return this->result_.c_str();
}

const char* Preprocessor::remove_non_alphanumeric(string_view_t input, string_view_t stop_list)
{

    std::u32string stop_list_ = to_32string(stop_list);

    this->result_ = anltk_erase_if(input,
                                   [&](char_t c)
                                   {
                                       return std::find(stop_list_.begin(), stop_list_.end(), c)
                                           == stop_list_.end()
                                           && !anltk::is_arabic_alpha(c)
                                           && !anltk::is_indic_digit(c) && !anltk::is_digit(c);
                                   });

    return this->result_.c_str();
}

const char* Preprocessor::remove_non_alphanumeric_and_tashkeel(string_view_t input,
                                                               string_view_t stop_list)
{

    std::u32string stop_list_ = to_32string(stop_list);

    this->result_ = anltk_erase_if(input,
                                   [&](char_t c)
                                   {
                                       return std::find(stop_list_.begin(), stop_list_.end(), c)
                                           == stop_list_.end()
                                           && !anltk::is_arabic_alpha(c)
                                           && !anltk::is_indic_digit(c) && !anltk::is_tashkeel(c)
                                           && !std::isdigit(c);
                                   });

    return this->result_.c_str();
}

const char* Preprocessor::remove_kasheeda(string_view_t input)
{
    this->result_ = anltk_erase_if(input, [](char_t c) { return c == TATWEEL; });

    return this->result_.c_str();
}

const char* Preprocessor::normalize_hamzat(string_view_t input)
{
    auto start = input.begin();
    auto end   = input.end();
    while (start < end)
    {
        char_t next = utf8::next(start, end);

        switch (next)
        {
        case HAMZA:
        case WAW_HAMZA_ABOVE:
        case YEH_HAMZA_ABOVE:
        case ALEF_HAMZA_BELOW:
        case ALEF_MADDA:
            next = ALEF_HAMZA_ABOVE;
            break;

        default:
            break;
        }

        utf8::append(next, this->result_);
    }
    return this->result_.c_str();
}

const char* Preprocessor::duplicate_shadda_letter(string_view_t input)
{
    auto start = input.begin();
    auto end   = input.end();
    char_t prev{};
    // TODO(Abdullah) : Could be more efficient
    while (start < end)
    {

        char_t next = utf8::next(start, end);
        if (next == SHADDA)
        {
            utf8::append(prev, this->result_);
        }
        else
        {
            utf8::append(next, this->result_);
        }
        prev = next;
    }

    return this->result_.c_str();
}

} // namespace anltk