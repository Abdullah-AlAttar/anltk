#ifndef ANLTK_H
#define ANLTK_H
#include <string>
#include <map>
#include <tinyutf8/tinyutf8.h>



namespace anltk
{
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
    std::string result_;
    const std::map<char32_t, char32_t> * chars_map_;
};

class Mofaqqet
{
public:
    Mofaqqet(bool is_ordinal, bool is_feminine);
    ~Mofaqqet() = default;
    const char* tafqeet(long long number);

private:
    std::string result_;
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
    const char* remove_non_alpha(const char* input, const char* stop_list, const char* separator);
private:
    std::string result_;
};

bool is_tashkeel(const char* input);

bool is_tashkeel(char32_t c);

bool is_arabic_alpha(const char* input);

bool is_arabic_alpha(char32_t c);

bool is_valid_kalima(const char* input);

bool is_small(char32_t c);

bool is_small(const char* input);


template<typename Func>
tiny_utf8::string remove_if(const tiny_utf8::string& input, Func && f)
{
    tiny_utf8::string output;
    for(auto it = input.begin(); it != input.end() ; ++it)
    {
        if(f(*it))
        {
            continue;
        }
        output.append(tiny_utf8::string(*it));
    }
    return output;
}
} // namespace anltk

#endif
