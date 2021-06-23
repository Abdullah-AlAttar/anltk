

#include "anltk/anltk_api.h"
#include "anltk.h"

Transliterator* anltk_transliterator_new(Mappings mapping)
{
    return reinterpret_cast<Transliterator*>(
        new anltk::Transliterator(static_cast<anltk::Mappings>(mapping)));
}

void anltk_transliterator_free(Transliterator* ttor)
{
    delete reinterpret_cast<anltk::Transliterator*>(ttor);
}

const char* anltk_transliterator_convert(Transliterator* ttor, const char* input)
{
    return (reinterpret_cast<anltk::Transliterator*>(ttor))->convert(input);
}

Mofaqqet* anltk_mofaqqet_new(bool is_ordinal, bool is_feminine)
{
    return reinterpret_cast<Mofaqqet*>(new anltk::Mofaqqet(is_ordinal, is_feminine));
}

void anltk_mofaqqet_free(Mofaqqet* mof)
{
    delete reinterpret_cast<anltk::Mofaqqet*>(mof);
}

const char* anltk_mofaqqet_tafqeet(Mofaqqet* mof, long long input)
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

Preprocessor* anltk_preprocessor_new()
{
    return reinterpret_cast<Preprocessor*>(new anltk::Preprocessor());
}

const char* anltk_preprocessor_remove_tashkeel(Preprocessor* preprocessor, const char* input)
{
    return (reinterpret_cast<anltk::Preprocessor*>(preprocessor))->remove_tashkeel(input);
}

const char* anltk_preprocessor_remove_small(Preprocessor* preprocessor, const char* input)
{
    return (reinterpret_cast<anltk::Preprocessor*>(preprocessor))->remove_small(input);
}

const char* anltk_preprocessor_remove_non_alpha(Preprocessor* preprocessor,
                                                             const char* input,
                                                             const char* stop_list)

{
    return (reinterpret_cast<anltk::Preprocessor*>(preprocessor))
        ->remove_non_alpha(input, stop_list);
}
const char* anltk_preprocessor_remove_non_alphanumeric(Preprocessor*preprocessor, const char* input, const char* stop_list)
{
    return (reinterpret_cast<anltk::Preprocessor*>(preprocessor))
        ->remove_non_alphanumeric(input, stop_list);
}


void anltk_preprocessor_free(Preprocessor* preprocessor)
{
    delete reinterpret_cast<anltk::Preprocessor*>(preprocessor);
}