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
    tiny_utf8::string utf_ar_text = input;
    this->result_
        = anltk::remove_if(input, [](char32_t c) { return anltk::is_tashkeel(c); }).cpp_str();
    return this->result_.c_str();
}

const char* Preprocessor::remove_small(const char* input)
{
    tiny_utf8::string utf_ar_text = input;
    this->result_
        = anltk::remove_if(input, [](char32_t c) { return anltk::is_small(c); }).cpp_str();
    return this->result_.c_str();
}

std::vector<char32_t> get_stop_list(const char* stop_list, const char* separator)
{
    std::vector<char32_t> stop_list_vec;
    tiny_utf8::string stop_list_str = stop_list;
    tiny_utf8::string sep_str       = separator;
    if (stop_list_str.empty())
    {
        return stop_list_vec;
    }

    if (sep_str.empty())
    {
        stop_list_vec.push_back(stop_list_str.front());
        return stop_list_vec;
    }

    tiny_utf8::string buffer;

    char32_t sep = sep_str.front();
    for (auto it = stop_list_str.begin(); it != stop_list_str.end(); ++it)
    {
        if (*it == sep)
        {
            stop_list_vec.push_back(buffer.front());
            buffer.clear();
            continue;
        }
        buffer += *it;
    }
    stop_list_vec.push_back(buffer.front());
    std::cout << stop_list <<" "<< sep <<" "<< separator << " : "<<stop_list_vec.size() << std::endl;
    return stop_list_vec;
}
const char* Preprocessor::remove_non_alpha(const char* input, const char* stop_list,
                                           const char* separator)
{
    tiny_utf8::string utf_ar_text   = input;

    std::vector<char32_t> stop_list_vec = get_stop_list(stop_list, separator);

    this->result_ = anltk::remove_if(input, [&stop_list_vec](char32_t c) {
                        return !anltk::is_arabic_alpha(c)
                            && std::find(stop_list_vec.begin(), stop_list_vec.end(), c)
                            == stop_list_vec.end();
                    }).cpp_str();

    return this->result_.c_str();
}

} // namespace anltk