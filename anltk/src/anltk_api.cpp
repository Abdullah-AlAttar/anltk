

#include "anltk/anltk_api.h"
#include "anltk.h"

ANLTK_Transliterator* anltk_transliterator_new(Mappings mapping)
{
    return reinterpret_cast<ANLTK_Transliterator*>(
        new anltk::Transliterator(static_cast<anltk::Mappings>(mapping)));
}

void anltk_transliterator_free(ANLTK_Transliterator* ttor)
{
    delete reinterpret_cast<anltk::Transliterator*>(ttor);
}

const char* anltk_transliterator_convert(ANLTK_Transliterator* ttor, const char* input)
{
    return (reinterpret_cast<anltk::Transliterator*>(ttor))->convert(input);
}

ANLTK_Mofaqqet* anltk_mofaqqet_new(bool is_ordinal, bool is_feminine)
{
    return reinterpret_cast<ANLTK_Mofaqqet*>(new anltk::Mofaqqet(is_ordinal, is_feminine));
}

void anltk_mofaqqet_free(ANLTK_Mofaqqet* mof)
{
    delete reinterpret_cast<anltk::Mofaqqet*>(mof);
}

const char* anltk_mofaqqet_tafqeet(ANLTK_Mofaqqet* mof, long long input)
{
    return (reinterpret_cast<anltk::Mofaqqet*>(mof))->tafqeet(input);
}

bool anltk_is_valid_kalima(const char* input)
{
    return anltk::is_valid_kalima(input);
}

bool anltk_is_tashkeel(const char* input)
{
    return anltk::is_tashkeel(input);
}
bool anltk_is_arabic_alpha(const char* input)
{
    return anltk::is_arabic_alpha(input);
}

ANLTK_Preprocessor* anltk_preprocessor_new()
{
    return reinterpret_cast<ANLTK_Preprocessor*>(new anltk::Preprocessor());
}

const char* anltk_preprocessor_remove_tashkeel(ANLTK_Preprocessor* preprocessor, const char* input)
{
    return (reinterpret_cast<anltk::Preprocessor*>(preprocessor))->remove_tashkeel(input);
}

const char* anltk_preprocessor_remove_small(ANLTK_Preprocessor* preprocessor, const char* input)
{
    return (reinterpret_cast<anltk::Preprocessor*>(preprocessor))->remove_small(input);
}

const char* anltk_preprocessor_remove_non_alpha(ANLTK_Preprocessor* preprocessor, const char* input,
                                                const char* stop_list)

{
    return (reinterpret_cast<anltk::Preprocessor*>(preprocessor))
        ->remove_non_alpha(input, stop_list);
}
const char* anltk_preprocessor_remove_non_alphanumeric(ANLTK_Preprocessor* preprocessor,
                                                       const char* input, const char* stop_list)
{
    return (reinterpret_cast<anltk::Preprocessor*>(preprocessor))
        ->remove_non_alphanumeric(input, stop_list);
}

const char*
anltk_preprocessor_remove_non_alphanumeric_and_tashkeel(ANLTK_Preprocessor* preprocessor,
                                                        const char* input, const char* stop_list)
{
    return (reinterpret_cast<anltk::Preprocessor*>(preprocessor))
        ->remove_non_alphanumeric_and_tashkeel(input, stop_list);
}

const char* anltk_preprocessor_normalize_hamzat(ANLTK_Preprocessor* preprocessor, const char* input)
{
    return (reinterpret_cast<anltk::Preprocessor*>(preprocessor))
        ->normalize_hamzat(input);
}

const char* anltk_preprocessor_remove_kasheeda(ANLTK_Preprocessor* preprocessor, const char* input)
{
    return (reinterpret_cast<anltk::Preprocessor*>(preprocessor))
        ->remove_kasheeda(input);
}

const char* anltk_preprocessor_duplicate_shadda_letter(ANLTK_Preprocessor* preprocessor,
                                                       const char* input)
{
    return (reinterpret_cast<anltk::Preprocessor*>(preprocessor))
        ->duplicate_shadda_letter(input);
}

void anltk_preprocessor_free(ANLTK_Preprocessor* preprocessor)
{
    delete reinterpret_cast<anltk::Preprocessor*>(preprocessor);
}
