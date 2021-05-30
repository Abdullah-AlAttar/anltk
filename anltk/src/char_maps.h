#ifndef CHAR_MAPS_H
#define CHAR_MAPS_H

#include <array>
#include <map>

namespace anltk
{

// alphapet
constexpr char32_t HAMZA            = U'\u0621'; // ء
constexpr char32_t ALEF_MADDA       = U'\u0622';
constexpr char32_t ALEF_HAMZA_ABOVE = U'\u0623';
constexpr char32_t WAW_HAMZA_ABOVE  = U'\u0624';
constexpr char32_t ALEF_HAMZA_BELOW = U'\u0625';
constexpr char32_t YEH_HAMZA_ABOVE  = U'\u0626';
constexpr char32_t ALEF_NO_HAMZA    = U'\u0627';
constexpr char32_t BEH              = U'\u0628';
constexpr char32_t TEH_MARBOOTA     = U'\u0629';
constexpr char32_t TEH              = U'\u062A';
constexpr char32_t THEH             = U'\u062B';
constexpr char32_t JEEM             = U'\u062C';
constexpr char32_t KHAH             = U'\u062E';
constexpr char32_t HAH              = U'\u062D';
constexpr char32_t DAL              = U'\u062F';
constexpr char32_t THAL             = U'\u0630';
constexpr char32_t REH              = U'\u0631';
constexpr char32_t ZAIN             = U'\u0632';
constexpr char32_t SEEN             = U'\u0633';
constexpr char32_t SHEEN            = U'\u0634';
constexpr char32_t SAD              = U'\u0635';
constexpr char32_t DAD              = U'\u0636';
constexpr char32_t TAH              = U'\u0637';
constexpr char32_t ZAH              = U'\u0638';
constexpr char32_t AIN              = U'\u0639';
constexpr char32_t GHAIN            = U'\u063A';
constexpr char32_t FEH              = U'\u0641';
constexpr char32_t QAF              = U'\u0642';
constexpr char32_t KAF              = U'\u0643';
constexpr char32_t LAM              = U'\u0644';
constexpr char32_t MEEM             = U'\u0645';
constexpr char32_t NOON             = U'\u0646';
constexpr char32_t HEH              = U'\u0647';
constexpr char32_t WAW              = U'\u0648';
constexpr char32_t ALEF_MAQSURA     = U'\u0649';
constexpr char32_t YEH              = U'\u064A';

// harakat
constexpr char32_t TATWEEL       = U'\u0640';
constexpr char32_t TANWEEN_FATHA = U'\u064b';
constexpr char32_t TANWEEN_DAMMA = U'\u064c';
constexpr char32_t TANWEEN_KASRA = U'\u064d';
constexpr char32_t FATHA         = U'\u064e';
constexpr char32_t DAMMA         = U'\u064f';
constexpr char32_t KASRA         = U'\u0650';
constexpr char32_t SHADDA        = U'\u0651';
constexpr char32_t SUKUN         = U'\u0652';

// symbols
constexpr char32_t FASLA          = U'\u060C';
constexpr char32_t QUESTION_MARK  = U'\u061F';
constexpr char32_t FASLA_MANKOOTA = U'\u060B';
constexpr char32_t NOKTATAN       = U'\u003A';
constexpr char32_t NESBA          = U'\u0025';
constexpr char32_t TA3AJJOB       = U'\u0021';
constexpr char32_t KAWS_MAFTOOH   = U'\u0028';
constexpr char32_t KAWS_MAKFOOL   = U'\u0029';
constexpr char32_t DARB           = U'\u002A';
constexpr char32_t JAM3           = U'\u002B';
constexpr char32_t KESMA          = U'\u002F';
constexpr char32_t TAR7           = U'\u002D';
constexpr char32_t YOSAWI         = U'\u003D';
constexpr char32_t NOQTA          = U'\u06F0';

// numbers
constexpr char32_t SEFR      = U'\u0660';
constexpr char32_t WAHED     = U'\u0661';
constexpr char32_t ETHNAN    = U'\u0662';
constexpr char32_t THALATHA  = U'\u0663';
constexpr char32_t ARBA3A    = U'\u0664';
constexpr char32_t KHAMSA    = U'\u0665';
constexpr char32_t SETTA     = U'\u0666';
constexpr char32_t SAB3A     = U'\u0667';
constexpr char32_t THAMANEYA = U'\u0668';
constexpr char32_t TES3A     = U'\u0669';

// Small Letters
constexpr char32_t SMALL_ALEF = U'\u0670';
constexpr char32_t SMALL_WAW  = U'\u06E5';
constexpr char32_t SMALL_YEH  = U'\u06E6';

extern const std::map<char32_t, char32_t> arabic_to_buckwalter_;
extern const std::map<char32_t, char32_t> buckwalter_to_arabic_;

extern const std::array<char32_t, 37> alphabet_;
extern const std::array<char32_t, 9> tashkeel_list_;
extern const std::array<char32_t, 3> small_list_;


} // namespace anltk

#endif