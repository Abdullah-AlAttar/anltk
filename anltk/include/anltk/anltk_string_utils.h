#ifndef ANLTK_STRING_UTILS_H
#define ANLTK_STRING_UTILS_H

#include <algorithm>
#include <string>

namespace anltk
{

template <typename T>
inline bool ends_with(std::basic_string_view<T> s, std::basic_string_view<T> suffix)
{
	return std::mismatch(suffix.rbegin(), suffix.rend(), s.rbegin()).first == suffix.rend();
}

template <typename T>
inline bool ends_with(const T* s, const T* suffix)
{
	return ends_with<T>(std::basic_string_view<T>(s), std::basic_string_view<T>(suffix));
}

template <typename T>
inline bool ends_with(const std::basic_string<T>& s, const std::basic_string<T>& suffix)
{
	return std::mismatch(suffix.rbegin(), suffix.rend(), s.rbegin()).first == suffix.rend();
}

template <typename T>
inline bool starts_with(std::basic_string_view<T> s, std::basic_string_view<T> prefix)
{
	return std::mismatch(prefix.begin(), prefix.end(), s.begin()).first == prefix.end();
}

template <typename T>
inline bool starts_with(const std::basic_string<T>& s, const std::basic_string<T>& prefix)
{
	return std::mismatch(prefix.begin(), prefix.end(), s.begin()).first == prefix.end();
}

template <typename T>
inline bool starts_with(const T* s, const T* prefix)
{
	return starts_with<T>(std::basic_string_view<T>(s), std::basic_string_view<T>(prefix));
}

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