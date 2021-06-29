#ifndef ANLTK_H
#define ANLTK_H
#include <map>
#include <string>
#include <tinyutf8/tinyutf8.h>

namespace anltk
{


using string_t = tiny_utf8::string;
// using string_t = std::u32string;

enum class Mappings
{
    AR2BW,
    BW2AR
};
class Transliterator
{
public:
    Transliterator(Mappings);
    ~Transliterator() = default;
    const char* convert(const char*);

private:
    string_t result_;
    const std::map<char32_t, char32_t>* chars_map_;
};

class Mofaqqet
{
public:
    Mofaqqet(bool is_ordinal, bool is_feminine);
    ~Mofaqqet() = default;
    const char* tafqeet(long long number);

private:
    string_t result_;
    bool is_ordinal_;
    bool is_feminine_;
};

class Preprocessor
{
public:
    Preprocessor();
    ~Preprocessor() = default;
    const char* remove_tashkeel(const char* input);
    const char* remove_small(const char* input);
    const char* remove_non_alpha(const char* input, const char* stop_list);
    const char* remove_non_alphanumeric(const char* input, const char* stop_list);
    const char* remove_non_alphanumeric_and_tashkeel(const char* input, const char* stop_list);

private:
    string_t result_;
};

bool is_tashkeel(const char* input);

bool is_tashkeel(char32_t c);

bool is_arabic_alpha(const char* input);

bool is_arabic_alpha(char32_t c);

bool is_valid_kalima(const char* input);

bool is_small(char32_t c);

bool is_small(const char* input);

bool is_indic_digit(char32_t c);

template <typename Func>
void erase_if(string_t& input, Func&& f)
{
    input.erase(std::remove_if(input.begin(), input.end(), f), input.end());
    return;

    // string_t output;
    // for (auto it = input.begin(); it != input.end(); ++it)
    // {
    //     if (f(*it))
    //     {
    //         continue;
    //     }
    //     output += *it;
    // }
    // input = std::move(output);
}
} // namespace anltk

#endif
