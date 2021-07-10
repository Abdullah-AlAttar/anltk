#include "anltk.h"
#include "char_maps.h"
#include <iostream>
// #include <tinyutf8/tinyutf8.h>

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
    case Mappings::AR2SBW:
        this->chars_map_ = &arabic_to_safe_buckwalter_;
        break;
    case Mappings::SBW2AR:
        this->chars_map_ = &safe_buckwalter_to_arabic_;
        break;
    default:
        // TODO(abdullah): handle this
        break;
    }
}

const char* Transliterator::convert(string_view_t input)
{

    auto start = input.begin();
    auto end   = input.end();
    while (start < end)
    {
        char_t next = utf8::next(start, end);

        auto node = this->chars_map_->find(next);

        utf8::append(node != this->chars_map_->end() ? node->second : next, this->result_);
    }
    return this->result_.c_str();
}

} // namespace anltk
