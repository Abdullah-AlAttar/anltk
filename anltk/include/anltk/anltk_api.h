#ifndef ANLTK_API_H
#define ANLTK_API_H

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

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

typedef struct ANLTK_Transliterator ANLTK_Transliterator;
typedef struct ANLTK_Mofaqqet ANLTK_Mofaqqet;
typedef struct ANLTK_Preprocessor ANLTK_Preprocessor;
typedef enum
{
    CM_AR2BW,
    CM_BW2AR
} Mappings;

/**
 * @brief Creates Transliterator with specific mapping
 *
 * @param mapping : mapping type
 * @return Transliterator* object
 */
ANLTK_PUBLIC ANLTK_Transliterator* anltk_transliterator_new(Mappings mapping);

/**
 * @brief Releases the Transliterator object
 */
ANLTK_PUBLIC void anltk_transliterator_free(ANLTK_Transliterator*);

/**
 * @brief Convert given input into the pre-specified Mapping using the given Transliterator
 * if a character does not have a conversion, will be left as is. @n
 * note: the returned buffer is owned by the Transliterator* object, remember to free.
 * @param input
 * @return const char* contains the result,
 */
ANLTK_PUBLIC const char* anltk_transliterator_convert(ANLTK_Transliterator*, const char* input);

/**
 * @brief Creates Mofaqqet object
 *
 * @param is_ordinal : eg : الأول , whereas cardinal : واحد
 * @param is_feminine : eg : التاسعة عشرة, vs التاسع عشر
 * @return Mofaqqet*
 */
ANLTK_PUBLIC ANLTK_Mofaqqet* anltk_mofaqqet_new(bool is_ordinal, bool is_feminine);

/**
 * @brief Releases the Mofaqqet object
 */
ANLTK_PUBLIC void anltk_mofaqqet_free(ANLTK_Mofaqqet*);

/**
 * @brief Converest given number to spoken arabic form. @n
 * note: the returned buffer is owned by the Mofaqqet* object, remember to free.
 * @param input number, can be negative or positive
 * @return const char* containing the result
 */
ANLTK_PUBLIC const char* anltk_mofaqqet_tafqeet(ANLTK_Mofaqqet*, long long input);

/**
 * @brief Check wether the input is a valid arabic word
 * by valid means :
 *  1- Contains no spaces. @n
 *  2- Is not empty. @n
 *  3- Doesn't have double shadda. @n
 *  4- Doesn't coutain ئ or ؤ at the start of the word. @n.
 *  5- Doesn't contain ة or ى before the last character. @n
 * @param input
 * @return bool
 */
ANLTK_PUBLIC bool anltk_is_valid_kalima(const char* input);

/**
 * @brief Check wether a character is a valid tashkeel from the following list
 * { TANWEEN_FATHA, TANWEEN_DAMMA, TANWEEN_KASRA, FATHA, DAMMA, KASRA, SHADDA, SUKUN }
 *
 * @param input : should be a single arabic character.
 * @return ANLTK_PUBLIC
 */

ANLTK_PUBLIC bool anltk_is_tashkeel(const char* input);

/**
 * @brief Checks wether a character is from the alphabet
 *
 * @param input : should be a single arabic character. will return false if empty or more than 1
 * @return ANLTK_PUBLIC
 */
ANLTK_PUBLIC bool anltk_is_arabic_alpha(const char* input);
/**
 * @brief creates preprocessor
 *
 * @return ANLTK_PUBLIC*
 */
ANLTK_PUBLIC ANLTK_Preprocessor* anltk_preprocessor_new();

/**
 * @brief Removes all tashkeel from the given arabic text,
 * the tashkeel list is { TANWEEN_FATHA, TANWEEN_DAMMA, TANWEEN_KASRA, FATHA, DAMMA, KASRA, SHADDA,
 * SUKUN }
 * @param input
 * @return ANLTK_PUBLIC const*
 */
ANLTK_PUBLIC const char* anltk_preprocessor_remove_tashkeel(ANLTK_Preprocessor*, const char* input);
/**
 * @brief Removes small tashkeel from the given arabic text
 * the small list is { SMALL_ALEF '\u0670',  SMALL_WAW : '\u06E5', SMALL_YEH : '\u06E6' }
 * @param input
 * @return ANLTK_PUBLIC const*
 */
ANLTK_PUBLIC const char* anltk_preprocessor_remove_small(ANLTK_Preprocessor*, const char* input);

/**
 * @brief Removes non alphapet 28 characters from the given arabic text
 * @param input
 * @param stop_list strings containing list of characters that won't be removed. each one should be
 * a single character
 * @return const char*
 */
ANLTK_PUBLIC const char* anltk_preprocessor_remove_non_alpha(ANLTK_Preprocessor*, const char* input,
                                                             const char* stop_list);

/**
 * @brief Removes non alphapet 28 characters from the given arabic text plus 9 digits(both Indic and
 * English)
 * @param input
 * @param stop_list strings containing list of characters that won't be removed. each one should be
 * a single character
 * @return const char*
 */
ANLTK_PUBLIC const char* anltk_preprocessor_remove_non_alphanumeric(ANLTK_Preprocessor*,
                                                                    const char* input,
                                                                    const char* stop_list);

/**
 * @brief Removes non alphapet 28 characters from the given arabic text plus 9 digits(both Indic and
 * English) plus tashkeel list is { TANWEEN_FATHA, TANWEEN_DAMMA, TANWEEN_KASRA, FATHA, DAMMA,
 * KASRA, SHADDA, SUKUN }
 * @param input
 * @param stop_list strings containing list of characters that won't be removed. each one should be
 * a single character
 * @return const char*
 */
ANLTK_PUBLIC const char*
anltk_preprocessor_remove_non_alphanumeric_and_tashkeel(ANLTK_Preprocessor*, const char* input,
                                                        const char* stop_list);

/**
 * @brief Replaces Hamzaat forms ‫ء‬, ,‫آ‬ ‫ؤ‬, ‫ئ‬, ‫ئ‬ with ‫أ‬
 * 
 * @param input 
 * @return  const char*  
 */
ANLTK_PUBLIC const char*
anltk_preprocessor_normalize_hamzat(ANLTK_Preprocessor*, const char* input);

/**
 * @brief Removes Kasheesa AKA Tatweel‬
 * 
 * @param input 
 * @return  const char*  
 */
ANLTK_PUBLIC const char*
anltk_preprocessor_remove_kasheeda(ANLTK_Preprocessor*, const char* input);


/**
 * @brief Duplicates the shadda letter
 * eg : الشّمس becomes الششمس
 * @param input 
 * @return  const char* 
 */
ANLTK_PUBLIC const char*
anltk_preprocessor_duplicate_shadda_letter(ANLTK_Preprocessor*, const char* input);


/**
 * @brief Extract word roots
 * @param input a single word  
 * @return  const char* 
 */
ANLTK_PUBLIC const char*
anltk_preprocessor_extract_root(ANLTK_Preprocessor*, const char* input);

/**
 * @brief Releases the preprocessor
 *
 * @return ANLTK_PUBLIC
 */
ANLTK_PUBLIC void anltk_preprocessor_free(ANLTK_Preprocessor*);

#ifdef __cplusplus
}

#endif

#endif // ANLTK_API_H
