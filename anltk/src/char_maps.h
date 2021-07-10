#ifndef CHAR_MAPS_H
#define CHAR_MAPS_H

#include "anltk_typedefs.h"
#include <array>
#include <map>

namespace anltk
{

// alphapet
constexpr char_t HAMZA            = U'\u0621'; // \u0621	ء
constexpr char_t ALEF_MADDA       = U'\u0622'; // \u0622	آ
constexpr char_t ALEF_HAMZA_ABOVE = U'\u0623'; // \u0623	أ
constexpr char_t WAW_HAMZA_ABOVE  = U'\u0624'; // \u0624	ؤ 
constexpr char_t ALEF_HAMZA_BELOW = U'\u0625'; // \u0625	إ
constexpr char_t YEH_HAMZA_ABOVE  = U'\u0626'; // \u0626	ئ
constexpr char_t ALEF_NO_HAMZA    = U'\u0627'; // \u0627	ا
constexpr char_t BEH              = U'\u0628'; // \u0628	ب
constexpr char_t TEH_MARBOOTA     = U'\u0629'; // \u0629	ة
constexpr char_t TEH              = U'\u062A'; // \u062A	ت
constexpr char_t THEH             = U'\u062B'; // \u062B	ث
constexpr char_t JEEM             = U'\u062C'; // \u062C	ج
constexpr char_t HAH              = U'\u062D'; // \u062D	ح
constexpr char_t KHAH             = U'\u062E'; // \u062E	خ
constexpr char_t DAL              = U'\u062F'; // \u062F	د
constexpr char_t THAL             = U'\u0630'; // \u0630	ذ
constexpr char_t REH              = U'\u0631'; // \u0631	ر
constexpr char_t ZAIN             = U'\u0632'; // \u0632	ز
constexpr char_t SEEN             = U'\u0633'; // \u0633	س
constexpr char_t SHEEN            = U'\u0634'; // \u0634	ش
constexpr char_t SAD              = U'\u0635'; // \u0635	ص
constexpr char_t DAD              = U'\u0636'; // \u0636	ض
constexpr char_t TAH              = U'\u0637'; // \u0637	ط
constexpr char_t ZAH              = U'\u0638'; // \u0638	ظ
constexpr char_t AIN              = U'\u0639'; // \u0639	ع
constexpr char_t GHAIN            = U'\u063A'; // \u063A	غ
constexpr char_t FEH              = U'\u0641'; // \u0641	ف
constexpr char_t QAF              = U'\u0642'; // \u0642	ق
constexpr char_t KAF              = U'\u0643'; // \u0643	ك
constexpr char_t LAM              = U'\u0644'; // \u0644	ل
constexpr char_t MEEM             = U'\u0645'; // \u0645	م
constexpr char_t NOON             = U'\u0646'; // \u0646	ن
constexpr char_t HEH              = U'\u0647'; // \u0647	ه
constexpr char_t WAW              = U'\u0648'; // \u0648	و
constexpr char_t ALEF_MAQSURA     = U'\u0649'; // \u0649	ى
constexpr char_t YEH              = U'\u064A'; // \u064A	ي

// extras
constexpr char_t ALEF_WASLA = U'\u0671'; // \u0671	ٱ
constexpr char_t PEH 		= U'\u067E'; // \u067E	پ
constexpr char_t TCHEH		= U'\u067E'; // \u0686	چ
constexpr char_t VEH		= U'\u06A4'; // \u06A4	ڤ
constexpr char_t GAF		= U'\u06AF'; // \u06AF	گ

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
constexpr char_t TATWEEL       = U'\u0640'; // \u0640	ـ
constexpr char_t TANWEEN_FATHA = U'\u064b';
constexpr char_t TANWEEN_DAMMA = U'\u064c';
constexpr char_t TANWEEN_KASRA = U'\u064d';
constexpr char_t FATHA         = U'\u064e';
constexpr char_t DAMMA         = U'\u064f';
constexpr char_t KASRA         = U'\u0650';
constexpr char_t SHADDA        = U'\u0651';
constexpr char_t SUKUN         = U'\u0652';

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


extern const std::map<char_t, char_t> arabic_to_buckwalter_;
extern const std::map<char_t, char_t> buckwalter_to_arabic_;

extern const std::map<char_t, char_t> arabic_to_safe_buckwalter_;
extern const std::map<char_t, char_t> safe_buckwalter_to_arabic_;


extern const std::array<char_t, 37> alphabet_;

extern const std::array<char_t, 9> tashkeel_list_;
extern const std::array<char_t, 3> small_list_;
extern const std::array<char_t, 10> digits_;

} // namespace anltk

#endif