#ifndef ANLTK_STRING_UTILS_H
#define ANLTK_STRING_UTILS_H

#include <algorithm>
#include <string>

namespace anltk
{


template <typename T>
inline void rtrim(std::basic_string<T>& s)
{
	s.erase(std::find_if(s.rbegin(), s.rend(), [](T ch) { return !std::isspace(ch); }).base(),
	        s.end());
}

template <typename T>
inline void ltrim(std::basic_string<T>& s)
{
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](T ch) { return !std::isspace(ch); }));
}
template <typename T>
inline void trim(std::basic_string<T>& s)
{
	ltrim(s);
	rtrim(s);
}

} // namespace anltk

#endif