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

typedef struct Transliterator Transliterator;
typedef struct Mofaqqet Mofaqqet;
typedef struct Preprocessor Preprocessor;
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
ANLTK_PUBLIC Transliterator* anltk_transliterator_new(Mappings mapping);

/**
 * @brief Releases the Transliterator object
 */
ANLTK_PUBLIC void anltk_transliterator_free(Transliterator*);

/**
 * @brief Convert given input into the pre-specified Mapping using the given Transliterator
 * if a character does not have a conversion, will be left as is. @n
 * note: the returned buffer is owned by the Transliterator* object, remember to free.
 * @param input
 * @return const char* contains the result,
 */
ANLTK_PUBLIC const char* anltk_transliterator_convert(Transliterator*, const char* input);

/**
 * @brief Creates Mofaqqet object
 *
 * @param is_ordinal : eg : الأول , whereas cardinal : واحد
 * @param is_feminine : eg : التاسعة عشرة, vs التاسع عشر
 * @return Mofaqqet*
 */
ANLTK_PUBLIC Mofaqqet* anltk_mofaqqet_new(bool is_ordinal, bool is_feminine);

/**
 * @brief Releases the Mofaqqet object
 */
ANLTK_PUBLIC void anltk_mofaqqet_free(Mofaqqet*);

/**
 * @brief Converest given number to spoken arabic form. @n
 * note: the returned buffer is owned by the Mofaqqet* object, remember to free.
 * @param input number, can be negative or positive
 * @return const char* containing the result
 */
ANLTK_PUBLIC const char* anltk_mofaqqet_tafqeet(Mofaqqet*, long long input);

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

ANLTK_PUBLIC bool anltk_is_tashkeel(const char* input);

ANLTK_PUBLIC bool anltk_is_arabic_alpha(const char* input);

ANLTK_PUBLIC Preprocessor* anltk_preprocessor_new();

ANLTK_PUBLIC const char* anltk_preprocessor_remove_tashkeel(Preprocessor*, const char* input);

ANLTK_PUBLIC void anltk_preprocessor_free(Preprocessor*);

#ifdef __cplusplus
}

#endif

#endif // ANLTK_API_H