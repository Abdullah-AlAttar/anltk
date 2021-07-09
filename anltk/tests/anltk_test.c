#include "anltk/anltk_api.h"
#include <stdio.h>

int main()
{
    ANLTK_Transliterator* ttor = anltk_transliterator_new(CM_AR2BW);

    const char* ar_text = "أبجد هوز حطي كلمن سعفص قرشت ثخذ ضظغ";

    printf("%s\n", anltk_transliterator_convert(ttor, ar_text));
    // >bjd hwz HTy klmn sEfS qr$t vx* DZg
    anltk_transliterator_free(ttor);

    const char* text = "فَرَاشَةٌ مُلَوَّنَةٌ تَطِيْرُ في البُسْتَانِ، حُلْوَةٌ مُهَنْدَمَةٌ تُدْهِشُ الإِنْسَانَ.";

    ANLTK_Preprocessor* pr = anltk_preprocessor_new();

    printf("%s\n" , anltk_preprocessor_remove_tashkeel(pr, text) );
    // فراشة ملونة تطير في البستان، حلوة مهندمة تدهش الإنسان.  

    // Third paramters is a stop_list, charactres in this list won't be removed
    printf("%s\n" , anltk_preprocessor_remove_non_alpha(pr, text, " ") );
    // فراشة ملونة تطير في البستان حلوة مهندمة تدهش الإنسان
    
    anltk_preprocessor_free(pr);
}
