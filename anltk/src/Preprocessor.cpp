#include "anltk.h"
#include "char_maps.h"
#include <iostream>
#include <tinyutf8/tinyutf8.h>

namespace anltk
{

Preprocessor::Preprocessor()
{
}

const char* Preprocessor::remove_tashkeel(const char* input)
{
    tiny_utf8::string utf_ar_text = input;
    tiny_utf8::string output;

    for(auto it = utf_ar_text.begin(); it != utf_ar_text.end() ; ++it)
    {
        if(is_tashkeel(*it))
        {
            continue;
        }
        output.append(tiny_utf8::string(*it));
    }
    this->result_ = output.cpp_str();
    return this->result_.c_str();
}

const char* Preprocessor::remove_small(const char* input)
{
    tiny_utf8::string utf_ar_text = input;
    tiny_utf8::string output;

    for(auto it = utf_ar_text.begin(); it != utf_ar_text.end() ; ++it)
    {
        if(is_small(*it))
        {
            continue;
        }
        output.append(tiny_utf8::string(*it));
    }
    this->result_ = output.cpp_str();
    return this->result_.c_str();
}

} // namespace anltk