

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