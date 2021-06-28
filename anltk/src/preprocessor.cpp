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

const char* Preprocessor::remove_tashkeel(const char* input)
{
    this->result_ = input;
    anltk::erase_if(this->result_,
                    [](const string_t::value_type& c) { return anltk::is_tashkeel(c); });

    return this->result_.c_str();
}

const char* Preprocessor::remove_small(const char* input)
{
    this->result_ = input;
    anltk::erase_if(this->result_, [](char32_t c) { return anltk::is_small(c); });

    return this->result_.c_str();
}

const char* Preprocessor::remove_non_alpha(const char* input, const char* stop_list)
{
    this->result_ = input;

    string_t stop_list_ = stop_list;

    anltk::erase_if(result_, [&stop_list_](char32_t c) {
        return !anltk::is_arabic_alpha(c)
            && std::find(stop_list_.begin(), stop_list_.end(), c) == stop_list_.end();
    });

    return this->result_.c_str();
}
const char* Preprocessor::remove_non_alphanumeric(const char* input, const char* stop_list)
{
    this->result_ = input;

    string_t stop_list_ = stop_list;
    
    anltk::erase_if(result_, [&stop_list_](char32_t c) {
        return std::find(stop_list_.begin(), stop_list_.end(), c) == stop_list_.end()
            && !anltk::is_arabic_alpha(c)
            && !anltk::is_indic_digit(c)
            && !std::isdigit(c);
    });

    return this->result_.c_str();
}
const char* Preprocessor::remove_non_alphanumeric_and_tashkeel(const char* input, const char* stop_list)
{
    this->result_ = input;

    string_t stop_list_ = stop_list;
    
    anltk::erase_if(result_, [&stop_list_](char32_t c) {
        return std::find(stop_list_.begin(), stop_list_.end(), c) == stop_list_.end()
            && !anltk::is_arabic_alpha(c)
            && !anltk::is_indic_digit(c)
            && !std::isdigit(c)
            && !anltk::is_tashkeel(c);
    });

    return this->result_.c_str();
}
} // namespace anltk