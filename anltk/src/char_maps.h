#ifndef CHAR_MAPS_H
#define CHAR_MAPS_H

#include "anltk_typedefs.h"
#include <array>
#include <map>

namespace anltk
{

// alphapet
constexpr char_t HAMZA            = U'\u0621'; // ء
constexpr char_t ALEF_MADDA       = U'\u0622';
constexpr char_t ALEF_HAMZA_ABOVE = U'\u0623';
constexpr char_t WAW_HAMZA_ABOVE  = U'\u0624';
constexpr char_t ALEF_HAMZA_BELOW = U'\u0625';
constexpr char_t YEH_HAMZA_ABOVE  = U'\u0626';
constexpr char_t ALEF_NO_HAMZA    = U'\u0627';
constexpr char_t BEH              = U'\u0628';
constexpr char_t TEH_MARBOOTA     = U'\u0629';
constexpr char_t TEH              = U'\u062A';
constexpr char_t THEH             = U'\u062B';
constexpr char_t JEEM             = U'\u062C';
constexpr char_t KHAH             = U'\u062E';
constexpr char_t HAH              = U'\u062D';
constexpr char_t DAL              = U'\u062F';
constexpr char_t THAL             = U'\u0630';
constexpr char_t REH              = U'\u0631';
constexpr char_t ZAIN             = U'\u0632';
constexpr char_t SEEN             = U'\u0633';
constexpr char_t SHEEN            = U'\u0634';
constexpr char_t SAD              = U'\u0635';
constexpr char_t DAD              = U'\u0636';
constexpr char_t TAH              = U'\u0637';
constexpr char_t ZAH              = U'\u0638';
constexpr char_t AIN              = U'\u0639';
constexpr char_t GHAIN            = U'\u063A';
constexpr char_t FEH              = U'\u0641';
constexpr char_t QAF              = U'\u0642';
constexpr char_t KAF              = U'\u0643';
constexpr char_t LAM              = U'\u0644';
constexpr char_t MEEM             = U'\u0645';
constexpr char_t NOON             = U'\u0646';
constexpr char_t HEH              = U'\u0647';
constexpr char_t WAW              = U'\u0648';
constexpr char_t ALEF_MAQSURA     = U'\u0649';
constexpr char_t YEH              = U'\u064A';

// harakat
constexpr char_t TATWEEL       = U'\u0640';
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

extern const std::array<char_t, 37> alphabet_;

extern const std::array<char_t, 9> tashkeel_list_;
extern const std::array<char_t, 3> small_list_;
extern const std::array<char_t, 10> digits_;

} // namespace anltk

#endif