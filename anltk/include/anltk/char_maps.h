#ifndef CHAR_MAPS_H
#define CHAR_MAPS_H

#include "anltk/anltk_typedefs.h"
#include <array>
#include <map>
namespace anltk
{
// clang-format off
// alphapet
constexpr char_t HAMZA            = U'\u0621'; // ء	 \u0621
constexpr char_t ALEF_MADDA       = U'\u0622'; // آ	 \u0622
constexpr char_t ALEF_HAMZA_ABOVE = U'\u0623'; // أ	 \u0623
constexpr char_t WAW_HAMZA_ABOVE  = U'\u0624'; // ؤ	 \u0624
constexpr char_t ALEF_HAMZA_BELOW = U'\u0625'; // إ	 \u0625
constexpr char_t YEH_HAMZA_ABOVE  = U'\u0626'; // ئ	 \u0626
constexpr char_t ALEF_NO_HAMZA    = U'\u0627'; // ا	 \u0627
constexpr char_t BEH              = U'\u0628'; // ب	 \u0628
constexpr char_t TEH_MARBOOTA     = U'\u0629'; // ة	 \u0629
constexpr char_t TEH              = U'\u062A'; // ت	 \u062A
constexpr char_t THEH             = U'\u062B'; // ث	 \u062B
constexpr char_t JEEM             = U'\u062C'; // ج	 \u062C
constexpr char_t HAH              = U'\u062D'; // ح	 \u062D
constexpr char_t KHAH             = U'\u062E'; // خ	 \u062E
constexpr char_t DAL              = U'\u062F'; // د	 \u062F
constexpr char_t THAL             = U'\u0630'; // ذ	 \u0630
constexpr char_t REH              = U'\u0631'; // ر	 \u0631
constexpr char_t ZAIN             = U'\u0632'; // ز	 \u0632
constexpr char_t SEEN             = U'\u0633'; // س	 \u0633
constexpr char_t SHEEN            = U'\u0634'; // ش	 \u0634
constexpr char_t SAD              = U'\u0635'; // ص	 \u0635
constexpr char_t DAD              = U'\u0636'; // ض	 \u0636
constexpr char_t TAH              = U'\u0637'; // ط	 \u0637
constexpr char_t ZAH              = U'\u0638'; // ظ	 \u0638
constexpr char_t AIN              = U'\u0639'; // ع	 \u0639
constexpr char_t GHAIN            = U'\u063A'; // غ	 \u063A
constexpr char_t FEH              = U'\u0641'; // ف	 \u0641
constexpr char_t QAF              = U'\u0642'; // ق	 \u0642
constexpr char_t KAF              = U'\u0643'; // ك	 \u0643
constexpr char_t LAM              = U'\u0644'; // ل	 \u0644
constexpr char_t MEEM             = U'\u0645'; // م	 \u0645
constexpr char_t NOON             = U'\u0646'; // ن	 \u0646
constexpr char_t HEH              = U'\u0647'; // ه	 \u0647
constexpr char_t WAW              = U'\u0648'; // و	 \u0648
constexpr char_t ALEF_MAQSURA     = U'\u0649'; // ى	 \u0649
constexpr char_t YEH              = U'\u064A'; // ي	 \u064A

// extras
constexpr char_t ALEF_WASLA = U'\u0671'; // ٱ  \u0671
constexpr char_t PEH        = U'\u067E'; // پ  \u067E
constexpr char_t TCHEH      = U'\u067E'; // چ  \u0686
constexpr char_t VEH        = U'\u06A4'; // ڤ  \u06A4
constexpr char_t GAF        = U'\u06AF'; // گ  \u06AF

// \u064B	ً
// \u064C	ٌ
// \u064D	ٍ
// \u064E	َ
// \u064F	ُ
// \u0650	ِ
// \u0651	ّ
// \u0652	ْ
// \u0670	ٰ

// harakat
constexpr char_t TATWEEL       = U'\u0640'; // 	ـ \u0640
constexpr char_t TANWEEN_FATHA = U'\u064b'; // 	ً  \u064B
constexpr char_t TANWEEN_DAMMA = U'\u064c'; // 	ٌ  \u064C
constexpr char_t TANWEEN_KASRA = U'\u064d'; // 	ٍ  \u064D
constexpr char_t FATHA         = U'\u064e'; // 	َ  \u064E
constexpr char_t DAMMA         = U'\u064f'; // 	ُ  \u064F
constexpr char_t KASRA         = U'\u0650'; // 	ِ  \u0650
constexpr char_t SHADDA        = U'\u0651'; // 	ّ  \u0651
constexpr char_t SUKUN         = U'\u0652'; // 	ْ  \u0652

// symbols
constexpr char_t FASLA          = U'\u060C';
constexpr char_t QUESTION_MARK  = U'\u061F';
constexpr char_t FASLA_MANKOOTA = U'\u060B';
constexpr char_t NOKTATAN       = U'\u003A';
constexpr char_t NESBA          = U'\u0025';
constexpr char_t TA3AJJOB       = U'\u0021';
constexpr char_t KAWS_MAFTOOH   = U'\u0028';
constexpr char_t KAWS_MAKFOOL   = U'\u0029';
constexpr char_t DARB           = U'\u002A';
constexpr char_t JAM3           = U'\u002B';
constexpr char_t KESMA          = U'\u002F';
constexpr char_t TAR7           = U'\u002D';
constexpr char_t YOSAWI         = U'\u003D';
constexpr char_t NOQTA          = U'\u06F0';

// numbers
constexpr char_t SEFR      = U'\u0660';
constexpr char_t WAHED     = U'\u0661';
constexpr char_t ETHNAN    = U'\u0662';
constexpr char_t THALATHA  = U'\u0663';
constexpr char_t ARBA3A    = U'\u0664';
constexpr char_t KHAMSA    = U'\u0665';
constexpr char_t SETTA     = U'\u0666';
constexpr char_t SAB3A     = U'\u0667';
constexpr char_t THAMANEYA = U'\u0668';
constexpr char_t TES3A     = U'\u0669';

// Small Letters
constexpr char_t SMALL_ALEF = U'\u0670';
constexpr char_t SMALL_WAW  = U'\u06E5';
constexpr char_t SMALL_YEH  = U'\u06E6';

const std::map<char_t, char_t> arabic_to_buckwalter_= 
{
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

const  std::map<char_t, char_t> buckwalter_to_arabic_ =
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

const std::map<char_t, char_t> arabic_to_safe_buckwalter_ =
{
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
const std::map<char_t, char_t> safe_buckwalter_to_arabic_ = 
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


const constexpr std::array<char_t, 36> alphabet_ = 
{
	HAMZA,
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
	YEH 
};

const constexpr std::array<char_t, 8> tashkeel_list_
    = { TANWEEN_FATHA, TANWEEN_DAMMA, TANWEEN_KASRA, FATHA, DAMMA, KASRA, SHADDA, SUKUN };

const constexpr std::array<char_t, 3> small_list_ = { SMALL_ALEF, SMALL_WAW, SMALL_YEH };
const constexpr std::array<char_t, 10> arqam_
     = { SEFR, WAHED, ETHNAN, THALATHA, ARBA3A, KHAMSA, SETTA, SAB3A, THAMANEYA, TES3A };

const constexpr std::array<char_t, 14> qamari_
    = { ALEF_NO_HAMZA, BEH, JEEM, HAH, KHAH, AIN, GHAIN, FEH, KAF, QAF, MEEM, HAH, WAW, YEH };

const constexpr std::array<char_t, 14> shmasi_
    = { TEH, THEH, DAL, THAL, REH, ZAIN, SEEN, SHEEN, SAD, DAD, TAH, ZAH, LAM, NOON };


const std::map<char_t, std::string> chars_names_ =
{ 
	{ U'\u0621', "ARABIC LETTER HAMZA" },
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
	{ U'\u06f0', "EXTENDED ARABIC-INDIC DIGIT ZERO" } 
};

} // namespace anltk

#endif