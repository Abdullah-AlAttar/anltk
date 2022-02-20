
#include "anltk/char_maps.h"
#include <iostream>
#include <map>
namespace anltk
{

// clang-format off
const std::map<char_t , char_t> arabic_to_buckwalter_ = {
	{ HAMZA            ,	U'\'' } ,
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

const std::map<char_t , char_t> buckwalter_to_arabic_ = 
{
	{ U'\'' , HAMZA },
	{ U'|' , ALEF_MADDA },
	{ U'>' , ALEF_HAMZA_ABOVE },
	{ U'&' , WAW_HAMZA_ABOVE },
	{ U'<' , ALEF_HAMZA_BELOW },
	{ U'}' , YEH_HAMZA_ABOVE },
	{ U'A' , ALEF_NO_HAMZA },
	{ U'b' , BEH },
	{ U'p' , TEH_MARBOOTA },
	{ U't' , TEH },
	{ U'v' , THEH },
	{ U'j' , JEEM },
	{ U'H' , HAH },
	{ U'x' , KHAH },
	{ U'd' , DAL },
	{ U'*' , THAL },
	{ U'r' , REH },
	{ U'z' , ZAIN },
	{ U's' , SEEN },
	{ U'$' , SHEEN },
	{ U'S' , SAD },
	{ U'D' , DAD },
	{ U'T' , TAH },
	{ U'Z' , ZAH },
	{ U'E' , AIN },
	{ U'g' , GHAIN },
	{ U'_' , TATWEEL },
	{ U'f' , FEH },
	{ U'q' , QAF },
	{ U'k' , KAF },
	{ U'l' , LAM },
	{ U'm' , MEEM },
	{ U'n' , NOON },
	{ U'h' , HEH },
	{ U'w' , WAW },
	{ U'Y' , ALEF_MAQSURA },
	{ U'y' , YEH },
	{ U'F' , TANWEEN_FATHA },
	{ U'N' , TANWEEN_DAMMA },
	{ U'K' , TANWEEN_KASRA },
	{ U'a' , FATHA },
	{ U'u' , DAMMA },
	{ U'i' , KASRA },
	{ U'~' , SHADDA },
	{ U'o' , SUKUN },
	{ U'`' , SMALL_ALEF },
	{ U'{' , ALEF_WASLA },
	{ U'P' , PEH },
	{ U'J' , TCHEH },
	{ U'V' , VEH },
	{ U'G' , GAF }
 };

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

const std::map<char_t, char_t> safe_buckwalter_to_arabic_= 
{
	{ U'C' , HAMZA} ,
	{ U'M', ALEF_MADDA },
	{ U'O', ALEF_HAMZA_ABOVE },
	{ U'W', WAW_HAMZA_ABOVE },
	{ U'I', ALEF_HAMZA_BELOW },
	{ U'Q', YEH_HAMZA_ABOVE },
	{ U'A', ALEF_NO_HAMZA },
	{ U'b', BEH },
	{ U'p', TEH_MARBOOTA },
	{ U't', TEH },
	{ U'v', THEH },
	{ U'j', JEEM },
	{ U'H', HAH },
	{ U'x', KHAH },
	{ U'd', DAL },
	{ U'V', THAL },
	{ U'r', REH },
	{ U'z', ZAIN },
	{ U's', SEEN },
	{ U'c', SHEEN },
	{ U'S', SAD },
	{ U'D', DAD },
	{ U'T', TAH },
	{ U'Z', ZAH },
	{ U'E', AIN },
	{ U'g', GHAIN },
	{ U'_', TATWEEL },
	{ U'f', FEH },
	{ U'q', QAF },
	{ U'k', KAF },
	{ U'l', LAM },
	{ U'm', MEEM },
	{ U'n', NOON },
	{ U'h', HEH },
	{ U'w', WAW },
	{ U'Y', ALEF_MAQSURA },
	{ U'y', YEH },
	{ U'F', TANWEEN_FATHA },
	{ U'N', TANWEEN_DAMMA },
	{ U'K', TANWEEN_KASRA },
	{ U'a', FATHA },
	{ U'u', DAMMA },
	{ U'i', KASRA },
	{ U'~', SHADDA },
	{ U'o', SUKUN },
	{ U'e', SMALL_ALEF },
	{ U'L', ALEF_WASLA },
	{ U'P', PEH },
	{ U'J', TCHEH },
	{ U'B', VEH },
	{ U'G', GAF },
 };


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

extern const std::array<char_t, 14> qamari_
    = { ALEF_NO_HAMZA, BEH, JEEM, HAH, KHAH, AIN, GHAIN, FEH, KAF, QAF, MEEM, HAH, WAW, YEH };

extern const std::array<char_t, 14> shmasi_
    = { TEH, THEH, DAL, THAL, REH, ZAIN, SEEN, SHEEN, SAD, DAD, TAH, ZAH, LAM, NOON };

extern const std::map<char_t, std::string> chars_names_
    = { { U'\u0621', "ARABIC LETTER HAMZA" },
	    { U'\u0622', "ARABIC LETTER ALEF WITH MADDA ABOVE" },
	    { U'\u0623', "ARABIC LETTER ALEF WITH HAMZA ABOVE" },
	    { U'\u0624', "ARABIC LETTER WAW WITH HAMZA ABOVE" },
	    { U'\u0625', "ARABIC LETTER ALEF WITH HAMZA BELOW" },
	    { U'\u0626', "ARABIC LETTER YEH WITH HAMZA ABOVE" },
	    { U'\u0627', "ARABIC LETTER ALEF" },
	    { U'\u0628', "ARABIC LETTER BEH" },
	    { U'\u0629', "ARABIC LETTER TEH MARBUTA" },
	    { U'\u062a', "ARABIC LETTER TEH" },
	    { U'\u062b', "ARABIC LETTER THEH" },
	    { U'\u062c', "ARABIC LETTER JEEM" },
	    { U'\u062d', "ARABIC LETTER HAH" },
	    { U'\u062e', "ARABIC LETTER KHAH" },
	    { U'\u062f', "ARABIC LETTER DAL" },
	    { U'\u0630', "ARABIC LETTER THAL" },
	    { U'\u0631', "ARABIC LETTER REH" },
	    { U'\u0632', "ARABIC LETTER ZAIN" },
	    { U'\u0633', "ARABIC LETTER SEEN" },
	    { U'\u0634', "ARABIC LETTER SHEEN" },
	    { U'\u0635', "ARABIC LETTER SAD" },
	    { U'\u0636', "ARABIC LETTER DAD" },
	    { U'\u0637', "ARABIC LETTER TAH" },
	    { U'\u0638', "ARABIC LETTER ZAH" },
	    { U'\u0639', "ARABIC LETTER AIN" },
	    { U'\u063a', "ARABIC LETTER GHAIN" },
	    { U'\u0641', "ARABIC LETTER FEH" },
	    { U'\u0642', "ARABIC LETTER QAF" },
	    { U'\u0643', "ARABIC LETTER KAF" },
	    { U'\u0644', "ARABIC LETTER LAM" },
	    { U'\u0645', "ARABIC LETTER MEEM" },
	    { U'\u0646', "ARABIC LETTER NOON" },
	    { U'\u0647', "ARABIC LETTER HEH" },
	    { U'\u0648', "ARABIC LETTER WAW" },
	    { U'\u0649', "ARABIC LETTER ALEF MAKSURA" },
	    { U'\u064a', "ARABIC LETTER YEH" },
	    { U'\u064b', "ARABIC FATHATAN" },
	    { U'\u064c', "ARABIC DAMMATAN" },
	    { U'\u064d', "ARABIC KASRATAN" },
	    { U'\u064e', "ARABIC FATHA" },
	    { U'\u064f', "ARABIC DAMMA" },
	    { U'\u0650', "ARABIC KASRA" },
	    { U'\u0651', "ARABIC SHADDA" },
	    { U'\u0652', "ARABIC SUKUN" },
	    { U'\u0640', "ARABIC TATWEEL" },
	    { U'\u0670', "ARABIC LETTER SUPERSCRIPT ALEF" },
	    { U'\u06e5', "ARABIC SMALL WAW" },
	    { U'\u06e6', "ARABIC SMALL YEH" },
	    { U'\u0660', "ARABIC-INDIC DIGIT ZERO" },
	    { U'\u0661', "ARABIC-INDIC DIGIT ONE" },
	    { U'\u0662', "ARABIC-INDIC DIGIT TWO" },
	    { U'\u0663', "ARABIC-INDIC DIGIT THREE" },
	    { U'\u0664', "ARABIC-INDIC DIGIT FOUR" },
	    { U'\u0665', "ARABIC-INDIC DIGIT FIVE" },
	    { U'\u0666', "ARABIC-INDIC DIGIT SIX" },
	    { U'\u0667', "ARABIC-INDIC DIGIT SEVEN" },
	    { U'\u0668', "ARABIC-INDIC DIGIT EIGHT" },
	    { U'\u0669', "ARABIC-INDIC DIGIT NINE" },
	    { U'\u0671', "ARABIC LETTER ALEF WASLA" },
	    { U'\u067e', "ARABIC LETTER PEH" },
	    { U'\u067e', "ARABIC LETTER PEH" },
	    { U'\u06a4', "ARABIC LETTER VEH" },
	    { U'\u06af', "ARABIC LETTER GAF" },
	    { U'\u060c', "ARABIC COMMA" },
	    { U'\u061f', "ARABIC QUESTION MARK" },
	    { U'\u060b', "AFGHANI SIGN" },
	    { U'\u003a', "COLON" },
	    { U'\u0025', "PERCENT SIGN" },
	    { U'\u0021', "EXCLAMATION MARK" },
	    { U'\u0028', "LEFT PARENTHESIS" },
	    { U'\u0029', "RIGHT PARENTHESIS" },
	    { U'\u002a', "ASTERISK" },
	    { U'\u002b', "PLUS SIGN" },
	    { U'\u002f', "SOLIDUS" },
	    { U'\u002d', "HYPHEN-MINUS" },
	    { U'\u003d', "EQUALS SIGN" },
	    { U'\u06f0', "EXTENDED ARABIC-INDIC DIGIT ZERO" } };

std::string char_name(char_t c)
{
	auto name = chars_names_.find(c);
	return name == chars_names_.end() ? "<unk>" : name->second;
}

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
