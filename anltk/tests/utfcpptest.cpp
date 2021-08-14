#include "anltk/anltk.hpp"
#include <functional>
#include <iostream>
#include <string>
#include <utf8.h>

std::string foo(std::string input, const std::vector<std::function<anltk::char_t(anltk::char_t)>>& ops)
{
    anltk::string_t result;
    auto start = input.begin();
    auto end   = input.end();

    while (start < end)
    {
         anltk::char_t next = utf8::next(start, end);
         for (const auto& op : ops)
         {

         }
    } 
    return " what";
}

int main()
{

    auto res = foo("بسم الله", { [](anltk::char_t c) { return c == 'ب' ? 'ت' : c; } });


    std::cout << res << std::endl;

    std::string ar_text = "أبجد هوز حطي كلمن سعفص قرشت ثخذ ضظغ";

    std::cout << anltk::transliterate(ar_text, anltk::CharMapping::AR2BW) << '\n';
    // >bjd hwz HTy klmn sEfS qr$t vx* DZg

    std::string text = "فَرَاشَةٌ مُلَوَّنَةٌ تَطِيْرُ في البُسْتَانِ، حُلْوَةٌ مُهَنْدَمَةٌ تُدْهِشُ الإِنْسَانَ.";

    std::cout << anltk::remove_tashkeel(text) << '\n';
    // فراشة ملونة تطير في البستان، حلوة مهندمة تدهش الإنسان.

    // Third paramters is a stop_list, charactres in this list won't be removed
    std::cout << anltk::remove_non_alpha(text, " ") << '\n';
    // فراشة ملونة تطير في البستان حلوة مهندمة تدهش الإنسان
}