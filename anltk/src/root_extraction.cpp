#include "anltk/anltk.hpp"

namespace anltk
{

const char* Preprocessor::extract_root(string_view_t input)
{
    // Normalization
    input = normalize_hamzat(input);
    input = duplicate_shadda_letter(input);
    input = remove_non_alphanumeric_and_tashkeel(input, " ");
    input = remove_kasheeda(input);

    return NULL;
}
} // namespace anltk