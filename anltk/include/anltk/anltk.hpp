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

namespace anltk
{



enum class CharMapping
{
    AR2BW,
    BW2AR,
    AR2SBW,
    SBW2AR
};

/**
 * @brief Convert given input into the pre-specified Mapping using the given Transliterator
 * if a character does not have a conversion, will be left as is. @n
 * @param input string
 * @return std::string
 */
ANLTK_PUBLIC string_t transliterate(string_view_t input, CharMapping mapping);

/**
 * @brief Converest given number to spoken arabic form. @n
 * @param input number, can be negative or positive
 * @return std::string
 * */
ANLTK_PUBLIC string_t tafqeet(long long number, bool is_ordinal = false, bool is_feminine = false);
/**
 * @brief Removes all tashkeel from the given arabic text,
 * the tashkeel list is { TANWEEN_FATHA, TANWEEN_DAMMA, TANWEEN_KASRA, FATHA, DAMMA, KASRA, SHADDA, SUKUN }
 * */ 
ANLTK_PUBLIC string_t remove_tashkeel(string_view_t input);
/**
 * @brief Removes small tashkeel from the given arabic text
 * the small list is { SMALL_ALEF '\u0670',  SMALL_WAW : '\u06E5', SMALL_YEH : '\u06E6' 
 */
ANLTK_PUBLIC string_t remove_small(string_view_t input);

/**
 * @brief Removes non alphapet 28 characters from the given arabic text
 * @param input
 * @param stop_list strings containing list of characters that won't be removed. each one should be
 * a single character
*/
ANLTK_PUBLIC string_t remove_non_alpha(string_view_t input, string_view_t stop_list);
/**
 * @brief Removes non alphapet 28 characters from the given arabic text plus 9 digits(both Indic and
 * English)
 * @param input
 * @param stop_list strings containing list of characters that won't be removed. each one should be
 * a single character
 */
ANLTK_PUBLIC string_t remove_non_alphanumeric(string_view_t input, string_view_t stop_list);
/**
 * @brief Removes non alphapet 28 characters from the given arabic text plus 9 digits(both Indic and
 * English) plus tashkeel list is { TANWEEN_FATHA, TANWEEN_DAMMA, TANWEEN_KASRA, FATHA, DAMMA,
 * KASRA, SHADDA, SUKUN }
 * @param input
 * @param stop_list strings containing list of characters that won't be removed. each one should be
 * a single character
 */
ANLTK_PUBLIC string_t remove_non_alphanumeric_and_tashkeel(string_view_t input, string_view_t stop_list);
/**
 * @brief Removes Kasheesa AKA Tatweel‬
 */
ANLTK_PUBLIC string_t remove_kasheeda(string_view_t input);

/**
 * @brief Replaces Hamzaat forms ‫ء‬, ,‫آ‬ ‫ؤ‬, ‫ئ‬, ‫ئ‬ with ‫أ‬
 */
ANLTK_PUBLIC string_t normalize_hamzat(string_view_t input);
/**
 * @brief Duplicates the shadda letter
 * eg : الشّمس becomes الششمس
 */
ANLTK_PUBLIC string_t duplicate_shadda_letter(string_view_t input);

// ANLTK_PUBLIC string_t extract_root(string_view_t input);


ANLTK_PUBLIC bool is_tashkeel(char_t c);

ANLTK_PUBLIC bool is_arabic_alpha(char_t c);

ANLTK_PUBLIC bool is_valid_kalima(string_view_t input);

ANLTK_PUBLIC bool is_small(char_t c);

ANLTK_PUBLIC bool is_indic_digit(char_t c);

ANLTK_PUBLIC bool is_digit(char_t c);


ANLTK_PUBLIC vector_t<string_t> tokenize_words(string_view_t input);


std::u32string to_32string(string_view_t input);


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
