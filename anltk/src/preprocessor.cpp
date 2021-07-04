#include "anltk.h"
#include "char_maps.h"
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
    this->result_ = anltk_erase_if(input, [](char32_t c) { return anltk::is_tashkeel(c); });

    return this->result_.c_str();
}

const char* Preprocessor::remove_small(string_view_t input)
{
    this->result_ = anltk_erase_if(input, [](char32_t c) { return anltk::is_small(c); });

    return this->result_.c_str();
}

const char* Preprocessor::remove_non_alpha(string_view_t input, const char* stop_list)
{
    this->result_ = input;

    std::u32string stop_list_ = to_32string(stop_list);

    this->result_ = anltk_erase_if(input, [&](char32_t c) {
        return !anltk::is_arabic_alpha(c)
            && std::find(stop_list_.begin(), stop_list_.end(), c) == stop_list_.end();
    });

    return this->result_.c_str();
}

const char* Preprocessor::remove_non_alphanumeric(string_view_t input, const char* stop_list)
{

    this->result_ = input;

    std::u32string stop_list_ = to_32string(stop_list);

    this->result_ = anltk_erase_if(input, [&](char32_t c) {
        return std::find(stop_list_.begin(), stop_list_.end(), c) == stop_list_.end()
            && !anltk::is_arabic_alpha(c) && !anltk::is_indic_digit(c) && !std::isdigit(c);
    });

    return this->result_.c_str();
}

const char* Preprocessor::remove_non_alphanumeric_and_tashkeel(string_view_t input,
                                                               const char* stop_list)
{

    this->result_ = input;

    std::u32string stop_list_ = to_32string(stop_list);

    this->result_ = anltk_erase_if(input, [&](char32_t c) {
        return std::find(stop_list_.begin(), stop_list_.end(), c) == stop_list_.end()
            && !anltk::is_arabic_alpha(c) && !anltk::is_indic_digit(c) && !std::isdigit(c)
            && !anltk::is_tashkeel(c);
    });

    return this->result_.c_str();
}
} // namespace anltk