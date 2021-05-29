#ifndef ANLTK_H
#define ANLTK_H
#include <string>
#include <map>
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

bool is_tashkeel(char32_t c);

bool is_valid_kalima(const char* input);

} // namespace anltk

#endif
