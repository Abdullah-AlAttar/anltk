
#include "char_maps.h"
#include <map>

namespace anltk
{

std::map<char_t, char_t> flip_map(const std::map<char_t, char_t>& other)
{
    std::map<char_t, char_t> output;
    for (const auto& item : other)
        output[item.second] = item.first;
    return output;
}

// clang-format off
const std::map<char_t , char_t> arabic_to_buckwalter_ = {
	{ HAMZA            ,	U'‘' } ,
	{ ALEF_MADDA       ,	U'|' },
	{ ALEF_HAMZA_ABOVE ,	U'>' },
	{ WAW_HAMZA_ABOVE  ,	U'&' },
	{ ALEF_HAMZA_BELOW ,	U'<' },
	{ YEH_HAMZA_ABOVE  ,	U'}' },
	{ ALEF_NO_HAMZA    ,	U'A' },
	{ BEH              ,	U'b' },
	{ TEH_MARBOOTA     ,	U'p' },
	{ TEH              ,	U't' },
	{ THEH             ,	U'v' },
	{ JEEM             ,	U'j' },
	{ HAH              ,	U'H' },
	{ KHAH             ,	U'x' },
	{ DAL              ,	U'd' },
	{ THAL             ,	U'*' },
	{ REH              ,	U'r' },
	{ ZAIN             ,	U'z' },
	{ SEEN             ,	U's' },
	{ SHEEN            ,	U'$' },
	{ SAD              ,	U'S' },
	{ DAD              ,	U'D' },
	{ TAH              ,	U'T' },
	{ ZAH              ,	U'Z' },
	{ AIN              ,	U'E' },
	{ GHAIN            ,	U'g' },
	{ TATWEEL          ,	U'_' },
	{ FEH              ,	U'f' },
	{ QAF              ,	U'q' },
	{ KAF              ,	U'k' },
	{ LAM              ,	U'l' },
	{ MEEM             ,	U'm' },
	{ NOON             ,	U'n' },
	{ HEH              ,	U'h' },
	{ WAW              ,	U'w' },
	{ ALEF_MAQSURA     ,	U'Y' },
	{ YEH 			   ,	U'y' },
	{ TANWEEN_FATHA    ,	U'F' },
	{ TANWEEN_DAMMA    ,	U'N' },
	{ TANWEEN_KASRA    ,	U'K' },
	{ FATHA            ,	U'a' },
	{ DAMMA            ,	U'u' },
	{ KASRA            ,	U'i' },
	{ SHADDA           ,	U'~' },
	{ SUKUN            ,	U'o' },
	{ SMALL_ALEF 	   ,    U'`' },
	{ ALEF_WASLA	   ,    U'{' },
	{ PEH			   , 	U'P' },
	{ TCHEH   		   , 	U'J' },
	{ VEH			   , 	U'V' },
	{ QAF			   , 	U'G' },
 };

const std::map<char_t , char_t> buckwalter_to_arabic_ = flip_map(arabic_to_buckwalter_);

const std::map<char_t , char_t> arabic_to_safe_buckwalter_ = {
	{ HAMZA            ,	U'C' } ,
	{ ALEF_MADDA       ,	U'M' },
	{ ALEF_HAMZA_ABOVE ,	U'O' },
	{ WAW_HAMZA_ABOVE  ,	U'W' },
	{ ALEF_HAMZA_BELOW ,	U'I' },
	{ YEH_HAMZA_ABOVE  ,	U'Q' },
	{ ALEF_NO_HAMZA    ,	U'A' },
	{ BEH              ,	U'b' },
	{ TEH_MARBOOTA     ,	U'p' },
	{ TEH              ,	U't' },
	{ THEH             ,	U'v' },
	{ JEEM             ,	U'j' },
	{ HAH              ,	U'H' },
	{ KHAH             ,	U'x' },
	{ DAL              ,	U'd' },
	{ THAL             ,	U'V' },
	{ REH              ,	U'r' },
	{ ZAIN             ,	U'z' },
	{ SEEN             ,	U's' },
	{ SHEEN            ,	U'c' },
	{ SAD              ,	U'S' },
	{ DAD              ,	U'D' },
	{ TAH              ,	U'T' },
	{ ZAH              ,	U'Z' },
	{ AIN              ,	U'E' },
	{ GHAIN            ,	U'g' },
	{ TATWEEL          ,	U'_' },
	{ FEH              ,	U'f' },
	{ QAF              ,	U'q' },
	{ KAF              ,	U'k' },
	{ LAM              ,	U'l' },
	{ MEEM             ,	U'm' },
	{ NOON             ,	U'n' },
	{ HEH              ,	U'h' },
	{ WAW              ,	U'w' },
	{ ALEF_MAQSURA     ,	U'Y' },
	{ YEH 			   ,	U'y' },
	{ TANWEEN_FATHA    ,	U'F' },
	{ TANWEEN_DAMMA    ,	U'N' },
	{ TANWEEN_KASRA    ,	U'K' },
	{ FATHA            ,	U'a' },
	{ DAMMA            ,	U'u' },
	{ KASRA            ,	U'i' },
	{ SHADDA           ,	U'~' },
	{ SUKUN            ,	U'o' },
	{ SMALL_ALEF 	   ,    U'e' },
	{ ALEF_WASLA	   ,    U'L' },
	{ PEH			   , 	U'P' },
	{ TCHEH   		   , 	U'J' },
	{ VEH			   , 	U'B' },
	{ QAF			   , 	U'G' },
 };

const std::map<char_t, char_t> safe_buckwalter_to_arabic_= flip_map(arabic_to_safe_buckwalter_);

// clang-format on

const std::array<char_t, 37> alphabet_ = { HAMZA,
                                           ALEF_MADDA,
                                           ALEF_HAMZA_ABOVE,
                                           WAW_HAMZA_ABOVE,
                                           ALEF_HAMZA_BELOW,
                                           YEH_HAMZA_ABOVE,
                                           ALEF_NO_HAMZA,
                                           BEH,
                                           TEH_MARBOOTA,
                                           TEH,
                                           THEH,
                                           JEEM,
                                           HAH,
                                           KHAH,
                                           DAL,
                                           THAL,
                                           REH,
                                           ZAIN,
                                           SEEN,
                                           SHEEN,
                                           SAD,
                                           DAD,
                                           TAH,
                                           ZAH,
                                           AIN,
                                           GHAIN,
                                           FEH,
                                           QAF,
                                           KAF,
                                           LAM,
                                           MEEM,
                                           NOON,
                                           HEH,
                                           WAW,
                                           ALEF_MAQSURA,
                                           YEH };

const std::array<char_t, 9> tashkeel_list_
    = { TANWEEN_FATHA, TANWEEN_DAMMA, TANWEEN_KASRA, FATHA, DAMMA, KASRA, SHADDA, SUKUN };

const std::array<char_t, 3> small_list_ = { SMALL_ALEF, SMALL_WAW, SMALL_YEH };

const std::array<char_t, 10> digits_
    = { SEFR, WAHED, ETHNAN, THALATHA, ARBA3A, KHAMSA, SETTA, SAB3A, THAMANEYA, TES3A };
} // namespace anltk
