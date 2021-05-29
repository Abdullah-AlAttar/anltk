#include "anltk/anltk_api.h"
#include <stdio.h>

int main()
{
    Transliterator* ttor = anltk_transliterator_new(CM_AR2BW);

    const char* ar_text = "أبجد هوز حطي كلمن سعفص قرشت ثخذ ضظغ";

    const char* bw_text = anltk_transliterator_convert(ttor, ar_text);
    printf("%s\n", bw_text);
    anltk_transliterator_free(ttor);
}