#ifndef ANLTK_HPP
#define ANLTK_HPP




// clang-format off
#if defined _WIN32 || defined __CYGWIN__
  #ifdef BUILDING_ANLTK
    #define ANLTK_PUBLIC __declspec(dllexport)
  #else
    #define ANLTK_PUBLIC __declspec(dllimport)
  #endif
#else
  #ifdef BUILDING_ANLTK
      #define ANLTK_PUBLIC __attribute__ ((visibility ("default")))
  #else
      #define ANLTK_PUBLIC
  #endif
#endif
// clang-format on



#include <deque>
#include <map>
#include <vector>

#include "anltk/anltk_typedefs.h"
#include "anltk/char_maps.h"
#include "utf8.h"
namespace anltk
{

using string_t      = std::string;
using string_view_t = std::string_view;
using char_t        = char32_t;

enum class CharMapping
{
    AR2BW,
    BW2AR,
    AR2SBW,
    SBW2AR
};


// /**
//  * @brief Convert given input into the pre-specified Mapping using the given Transliterator
//  * if a character does not have a conversion, will be left as is. @n
//  * note: the returned buffer is owned by the Transliterator* object, remember to free.
//  * @param input
//  * @return const char* contains the result,
ANLTK_PUBLIC string_t transliterate(string_view_t input, CharMapping mapping);


ANLTK_PUBLIC string_t tafqeet(long long number, bool is_ordinal = false, bool is_feminine = false);
class Mofaqqet
{
public:
    Mofaqqet(bool is_ordinal = false, bool is_feminine = false);
    ~Mofaqqet() = default;
    const char* tafqeet(long long number);

    const string_t& result() const;
    string_t& result();

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
    const char* remove_tashkeel(string_view_t input);
    const char* remove_small(string_view_t input);
    const char* remove_non_alpha(string_view_t input, string_view_t stop_list);
    const char* remove_non_alphanumeric(string_view_t input, string_view_t stop_list);
    const char* remove_non_alphanumeric_and_tashkeel(string_view_t input, string_view_t stop_list);
    const char* remove_kasheeda(string_view_t input);
    const char* normalize_hamzat(string_view_t input);
    const char* duplicate_shadda_letter(string_view_t input);
    const char* extract_root(string_view_t input);

private:
    string_t result_;
};

bool is_tashkeel_impl(string_view_t input);

bool is_tashkeel(char_t c);

bool is_arabic_alpha_impl(string_view_t input);

bool is_arabic_alpha(char_t c);

bool is_valid_kalima(string_view_t input);

bool is_small(char_t c);

bool is_small_impl(string_view_t input);

bool is_indic_digit(char_t c);

bool is_digit(char_t c);

std::u32string to_32string(string_view_t input);

class Tokenizer
{
public:
    Tokenizer()  = default;
    ~Tokenizer() = default;

    const std::vector<const char*>& tokenize_words(string_view_t input);

private:
    std::vector<const char*> result_;
    std::vector<std::string> holder_;
};

#define FUNC_DECL(prefix, name) bool prefix##_##name(char_t c);
#define LIFT_DECL(name) FUNC_DECL(is, name)

LIFT_DECL(HAMZA)
LIFT_DECL(ALEF_MADDA)
LIFT_DECL(ALEF_HAMZA_ABOVE)
LIFT_DECL(WAW_HAMZA_ABOVE)
LIFT_DECL(ALEF_HAMZA_BELOW)
LIFT_DECL(YEH_HAMZA_ABOVE)
LIFT_DECL(ALEF_NO_HAMZA)
LIFT_DECL(BEH)
LIFT_DECL(TEH_MARBOOTA)
LIFT_DECL(TEH)
LIFT_DECL(THEH)
LIFT_DECL(JEEM)
LIFT_DECL(HAH)
LIFT_DECL(KHAH)
LIFT_DECL(DAL)
LIFT_DECL(THAL)
LIFT_DECL(REH)
LIFT_DECL(ZAIN)
LIFT_DECL(SEEN)
LIFT_DECL(SHEEN)
LIFT_DECL(SAD)
LIFT_DECL(DAD)
LIFT_DECL(TAH)
LIFT_DECL(ZAH)
LIFT_DECL(AIN)
LIFT_DECL(GHAIN)
LIFT_DECL(FEH)
LIFT_DECL(QAF)
LIFT_DECL(KAF)
LIFT_DECL(LAM)
LIFT_DECL(MEEM)
LIFT_DECL(NOON)
LIFT_DECL(HEH)
LIFT_DECL(WAW)
LIFT_DECL(ALEF_MAQSURA)
LIFT_DECL(YEH)
LIFT_DECL(ALEF_WASLA)
LIFT_DECL(PEH)
LIFT_DECL(TCHEH)
LIFT_DECL(VEH)
LIFT_DECL(GAF)
LIFT_DECL(TATWEEL)
LIFT_DECL(TANWEEN_FATHA)
LIFT_DECL(TANWEEN_DAMMA)
LIFT_DECL(TANWEEN_KASRA)
LIFT_DECL(FATHA)
LIFT_DECL(DAMMA)
LIFT_DECL(KASRA)
LIFT_DECL(SHADDA)
LIFT_DECL(SUKUN)
LIFT_DECL(FASLA)
LIFT_DECL(QUESTION_MARK)
LIFT_DECL(FASLA_MANKOOTA)
LIFT_DECL(NOKTATAN)
LIFT_DECL(NESBA)
LIFT_DECL(TA3AJJOB)
LIFT_DECL(KAWS_MAFTOOH)
LIFT_DECL(KAWS_MAKFOOL)
LIFT_DECL(DARB)
LIFT_DECL(JAM3)
LIFT_DECL(KESMA)
LIFT_DECL(TAR7)
LIFT_DECL(YOSAWI)
LIFT_DECL(NOQTA)
LIFT_DECL(SEFR)
LIFT_DECL(WAHED)
LIFT_DECL(ETHNAN)
LIFT_DECL(THALATHA)
LIFT_DECL(ARBA3A)
LIFT_DECL(KHAMSA)
LIFT_DECL(SETTA)
LIFT_DECL(SAB3A)
LIFT_DECL(THAMANEYA)
LIFT_DECL(TES3A)
LIFT_DECL(SMALL_ALEF)
LIFT_DECL(SMALL_WAW)
LIFT_DECL(SMALL_YEH)

} // namespace anltk

#endif
