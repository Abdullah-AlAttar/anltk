#include "anltk.h"
#include "char_maps.h"
#include <iostream>
#include <tinyutf8/tinyutf8.h>

namespace anltk
{

Transliterator::Transliterator(Mappings mapping)
{
    switch (mapping)
    {
    case Mappings::AR2BW:
        this->chars_map_ = &arabic_to_buckwalter_;
        break;
    case Mappings::BW2AR:
        this->chars_map_ = &buckwalter_to_arabic_;
        break;
    default:
        // TODO(abdullah): handle this
        break;
    }
}

const char* Transliterator::convert(const char* input)
{
    string_t utf_ar_text = input;
    string_t utf_bw_text = utf_ar_text;

    for (size_t i = 0; i < utf_ar_text.length(); ++i)
    {
        const auto& rune = utf_ar_text[i];

        auto node = this->chars_map_->find(rune);

        utf_bw_text[i] = (node == this->chars_map_->cend()) ? rune : node->second;
    }
    
    this->result_ = utf_bw_text.cpp_str();
    return this->result_.c_str();
}

} // namespace anltk
