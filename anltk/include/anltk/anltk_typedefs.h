#ifndef ANLTK_TYPEDEFS_H
#define ANLTK_TYPEDEFS_H
#include <string>
#include <string_view>
#include <vector>
namespace anltk
{
using string_t      = std::string;
using string_view_t = std::string_view;
using char_t        = char32_t;
template <typename T>
using vector_t = std::vector<T>;
} // namespace anltk
#endif