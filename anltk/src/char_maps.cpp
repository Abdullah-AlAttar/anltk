
#include "char_maps.h"
#include <map>

namespace anltk
{
// clang-format off
const std::map<char32_t , char32_t> arabic_to_buckwalter_ = {
	{ HAMZA            ,	U'\''},
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
	{ TATWEEL          ,	U'_' },
	{ TANWEEN_FATHA    ,	U'F' },
	{ TANWEEN_DAMMA    ,	U'N' },
	{ TANWEEN_KASRA    ,	U'K' },
	{ FATHA            ,	U'a' },
	{ DAMMA            ,	U'u' },
	{ KASRA            ,	U'i' },
	{ SHADDA           ,	U'~' },
	{ SUKUN            ,	U'o' }
 };

const std::map<char32_t , char32_t> buckwalter_to_arabic_ = {
	{	U'\''	,	HAMZA            },
	{	U'|'	,	ALEF_MADDA       },
	{	U'>'	,	ALEF_HAMZA_ABOVE },
	{	U'&'	,	WAW_HAMZA_ABOVE  },
	{	U'<'	,	ALEF_HAMZA_BELOW },
	{	U'}'	,	YEH_HAMZA_ABOVE  },
	{	U'A'	,	ALEF_NO_HAMZA    },
	{	U'b'	,	BEH              },
	{	U'p'	,	TEH_MARBOOTA     },
	{	U't'	,	TEH              },
	{	U'v'	,	THEH             },
	{	U'j'	,	JEEM             },
	{	U'H'	,	HAH              },
	{	U'x'	,	KHAH             },
	{	U'd'	,	DAL              },
	{	U'*'	,	THAL             },
	{	U'r'	,	REH              },
	{	U'z'	,	ZAIN             },
	{	U's'	,	SEEN             },
	{	U'$'	,	SHEEN            },
	{	U'S'	,	SAD              },
	{	U'D'	,	DAD              },
	{	U'T'	,	TAH              },
	{	U'Z'	,	ZAH              },
	{	U'E'	,	AIN              },
	{	U'g'	,	GHAIN            },
	{	U'f'	,	FEH              },
	{	U'q'	,	QAF              },
	{	U'k'	,	KAF              },
	{	U'l'	,	LAM              },
	{	U'm'	,	MEEM             },
	{	U'n'	,	NOON             },
	{	U'h'	,	HEH              },
	{	U'w'	,	WAW              },
	{	U'Y'	,	ALEF_MAQSURA      },
	{	U'y'	,	YEH    },
	{	U'_'	,	TATWEEL          },
	{	U'F'	,	TANWEEN_FATHA    },
	{	U'N'	,	TANWEEN_DAMMA     },
	{	U'K'	,	TANWEEN_KASRA    },
	{	U'a'	,	FATHA            },
	{	U'u'	,	DAMMA            },
	{	U'i'	,	KASRA            },
	{	U'~'	,	SHADDA           },
	{	U'o'	,	SUKUN            }

 };
// clang-format on

const std::array<char32_t, 37> alphabet_ = { HAMZA,
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

const std::array<char32_t, 9> tashkeel_list_
    = { TANWEEN_FATHA, TANWEEN_DAMMA, TANWEEN_KASRA, FATHA, DAMMA, KASRA, SHADDA, SUKUN };

const std::array<char32_t, 3> small_list_ = { SMALL_ALEF, SMALL_WAW, SMALL_YEH };

const std::array<char32_t, 10> digits_
    = { SEFR, WAHED, ETHNAN, THALATHA, ARBA3A, KHAMSA, SETTA, SAB3A, THAMANEYA, TES3A };
} // namespace anltk
