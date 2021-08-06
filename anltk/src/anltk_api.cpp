

#include "anltk/anltk_api.h"
#include "anltk/anltk.hpp"

#include <iostream>



bool anltk_is_valid_kalima(const char* input)
{
    return anltk::is_valid_kalima(input);
}

bool anltk_is_tashkeel(const char* input)
{
    return anltk::is_tashkeel_impl(input);
}
bool anltk_is_arabic_alpha(const char* input)
{
    return anltk::is_arabic_alpha_impl(input);
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
    return (reinterpret_cast<anltk::Preprocessor*>(preprocessor))->normalize_hamzat(input);
}

const char* anltk_preprocessor_remove_kasheeda(ANLTK_Preprocessor* preprocessor, const char* input)
{
    return (reinterpret_cast<anltk::Preprocessor*>(preprocessor))->remove_kasheeda(input);
}

const char* anltk_preprocessor_duplicate_shadda_letter(ANLTK_Preprocessor* preprocessor,
                                                       const char* input)
{
    return (reinterpret_cast<anltk::Preprocessor*>(preprocessor))->duplicate_shadda_letter(input);
}

// const char* anltk_preprocessor_extract_root(ANLTK_Preprocessor* preprocessor, const char* input)
// {
//     return (reinterpret_cast<anltk::Preprocessor*>(preprocessor))->extract_root(input);
// }

void anltk_preprocessor_free(ANLTK_Preprocessor* preprocessor)
{
    delete reinterpret_cast<anltk::Preprocessor*>(preprocessor);
}

