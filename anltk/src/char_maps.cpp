
#include "anltk/char_maps.h"
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
	{ GAF			   , 	U'G' },
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
	{ GAF			   , 	U'G' },
 };

const std::map<char_t, char_t> safe_buckwalter_to_arabic_= flip_map(arabic_to_safe_buckwalter_);

// clang-format on

const std::array<char_t, 36> alphabet_ = { HAMZA,
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

const std::array<char_t, 8> tashkeel_list_
    = { TANWEEN_FATHA, TANWEEN_DAMMA, TANWEEN_KASRA, FATHA, DAMMA, KASRA, SHADDA, SUKUN };

const std::array<char_t, 3> small_list_ = { SMALL_ALEF, SMALL_WAW, SMALL_YEH };

const std::array<char_t, 10> arqam_
    = { SEFR, WAHED, ETHNAN, THALATHA, ARBA3A, KHAMSA, SETTA, SAB3A, THAMANEYA, TES3A };

#define FUNC_IMPL(prefix, name)                                                                    \
    bool prefix##_##name(char_t c)                                                                 \
    {                                                                                              \
        return c == name;                                                                          \
    }
#define LIFT_IMPL(name) FUNC_IMPL(is, name)

LIFT_IMPL(HAMZA)
LIFT_IMPL(ALEF_MADDA)
LIFT_IMPL(ALEF_HAMZA_ABOVE)
LIFT_IMPL(WAW_HAMZA_ABOVE)
LIFT_IMPL(ALEF_HAMZA_BELOW)
LIFT_IMPL(YEH_HAMZA_ABOVE)
LIFT_IMPL(ALEF_NO_HAMZA)
LIFT_IMPL(BEH)
LIFT_IMPL(TEH_MARBOOTA)
LIFT_IMPL(TEH)
LIFT_IMPL(THEH)
LIFT_IMPL(JEEM)
LIFT_IMPL(HAH)
LIFT_IMPL(KHAH)
LIFT_IMPL(DAL)
LIFT_IMPL(THAL)
LIFT_IMPL(REH)
LIFT_IMPL(ZAIN)
LIFT_IMPL(SEEN)
LIFT_IMPL(SHEEN)
LIFT_IMPL(SAD)
LIFT_IMPL(DAD)
LIFT_IMPL(TAH)
LIFT_IMPL(ZAH)
LIFT_IMPL(AIN)
LIFT_IMPL(GHAIN)
LIFT_IMPL(FEH)
LIFT_IMPL(QAF)
LIFT_IMPL(KAF)
LIFT_IMPL(LAM)
LIFT_IMPL(MEEM)
LIFT_IMPL(NOON)
LIFT_IMPL(HEH)
LIFT_IMPL(WAW)
LIFT_IMPL(ALEF_MAQSURA)
LIFT_IMPL(YEH)
LIFT_IMPL(ALEF_WASLA)
LIFT_IMPL(PEH)
LIFT_IMPL(TCHEH)
LIFT_IMPL(VEH)
LIFT_IMPL(GAF)
LIFT_IMPL(TATWEEL)
LIFT_IMPL(TANWEEN_FATHA)
LIFT_IMPL(TANWEEN_DAMMA)
LIFT_IMPL(TANWEEN_KASRA)
LIFT_IMPL(FATHA)
LIFT_IMPL(DAMMA)
LIFT_IMPL(KASRA)
LIFT_IMPL(SHADDA)
LIFT_IMPL(SUKUN)
LIFT_IMPL(FASLA)
LIFT_IMPL(QUESTION_MARK)
LIFT_IMPL(FASLA_MANKOOTA)
LIFT_IMPL(NOKTATAN)
LIFT_IMPL(NESBA)
LIFT_IMPL(TA3AJJOB)
LIFT_IMPL(KAWS_MAFTOOH)
LIFT_IMPL(KAWS_MAKFOOL)
LIFT_IMPL(DARB)
LIFT_IMPL(JAM3)
LIFT_IMPL(KESMA)
LIFT_IMPL(TAR7)
LIFT_IMPL(YOSAWI)
LIFT_IMPL(NOQTA)
LIFT_IMPL(SEFR)
LIFT_IMPL(WAHED)
LIFT_IMPL(ETHNAN)
LIFT_IMPL(THALATHA)
LIFT_IMPL(ARBA3A)
LIFT_IMPL(KHAMSA)
LIFT_IMPL(SETTA)
LIFT_IMPL(SAB3A)
LIFT_IMPL(THAMANEYA)
LIFT_IMPL(TES3A)
LIFT_IMPL(SMALL_ALEF)
LIFT_IMPL(SMALL_WAW)
LIFT_IMPL(SMALL_YEH)
} // namespace anltk
