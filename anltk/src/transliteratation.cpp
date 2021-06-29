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
    this->result_ = input;
    for (auto it = this->result_.begin(); it != this->result_.end(); ++it)
    {
        auto node = this->chars_map_->find(*it);
        
        if (node != this->chars_map_->end())
        {
            *it = node->second;
        }
    }
    return this->result_.c_str();
}

} // namespace anltk
