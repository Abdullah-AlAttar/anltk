#ifndef ANLTK_HPP
#define ANLTK_HPP

#include "anltk/anltk_typedefs.h"
#include "anltk/char_maps.h"
#include <deque>
#include <functional>
#include <list>
#include <map>
#include <vector>

namespace anltk
{

enum class CharMapping
{
	AR2BW,
	BW2AR,
	AR2SBW,
	SBW2AR
};

/**
 * @brief Convert given input into the pre-specified Mapping using the given Transliterator
 * if a character does not have a conversion, will be left as is. @n
 * @param input string
 * @return std::string
 */
std::string transliterate(string_view_t input, CharMapping mapping);

/**
 * @brief Converest given number to spoken arabic form. @n
 * @param input number, can be negative or positive
 * @return std::string
 * */
std::string tafqeet(long long number, bool is_ordinal = false, bool is_feminine = false);
/**
 * @brief Removes all tashkeel from the given arabic text,
 * the tashkeel list is { TANWEEN_FATHA, TANWEEN_DAMMA, TANWEEN_KASRA, FATHA, DAMMA, KASRA, SHADDA,
 * SUKUN }
 * */
std::string remove_tashkeel(string_view_t input);
/**
 * @brief Removes small tashkeel from the given arabic text
 * the small list is { SMALL_ALEF '\u0670',  SMALL_WAW : '\u06E5', SMALL_YEH : '\u06E6'
 */
std::string remove_small(string_view_t input);

/**
 * @brief Removes non alphapet 28 characters from the given arabic text
 * @param input
 * @param stop_list strings containing list of characters that won't be removed. each one should be
 * a single character
 */
std::string remove_non_alpha(string_view_t input, string_view_t stop_list);
/**
 * @brief Removes non alphapet 28 characters from the given arabic text plus 9 digits(both Indic and
 * English)
 * @param input
 * @param stop_list strings containing list of characters that won't be removed. each one should be
 * a single character
 */
std::string remove_non_alphanumeric(string_view_t input, string_view_t stop_list);
/**
 * @brief Removes non alphapet 28 characters from the given arabic text plus 9 digits(both Indic and
 * English) plus tashkeel list is { TANWEEN_FATHA, TANWEEN_DAMMA, TANWEEN_KASRA, FATHA, DAMMA,
 * KASRA, SHADDA, SUKUN }
 * @param input
 * @param stop_list strings containing list of characters that won't be removed. each one should be
 * a single character
 */
std::string remove_non_alphanumeric_and_tashkeel(string_view_t input, string_view_t stop_list);
/**
 * @brief Removes Kasheesa AKA Tatweel‬
 */
std::string remove_kasheeda(string_view_t input);

/**
 * @brief Replaces Hamzaat forms ‫ء‬, ,‫آ‬ ‫ؤ‬, ‫ئ‬, ‫ئ‬ with ‫أ‬
 */
std::string normalize_hamzat(string_view_t input);
/**
 * @brief Duplicates the shadda letter
 * eg : الشّمس becomes الششمس
 */
std::string duplicate_shadda_letter(string_view_t input);

// std::string extract_root(string_view_t input);
std::string remove_if(string_view_t input, string_view_t stop_list,
                      const std::function<bool(char_t)>& func);

std::string fold_if(string_view_t input, const std::function<bool(char_t, char_t)>& func);

std::string fold_white_spaces(string_view_t input);

std::string replace(string_view_t input, std::map<char_t, char_t> chars_maps);

std::string replace_str(string_view_t input,
                        std::map<string_view_t, string_view_t> replacement_map);

std::string replace_if(string_view_t input, const std::function<bool(char_t)>& func, char_t replacement);


bool is_tashkeel(char_t c);

bool is_arabic_alpha(char_t c);

bool is_valid_kalima(string_view_t input);

bool is_small(char_t c);

bool is_indic_digit(char_t c);

bool is_digit(char_t c);

bool is_shamsi(char_t c);

bool is_qamari(char_t c);

vector_t<std::string> tokenize_words(string_view_t input);

vector_t<std::string> split(string_view_t input, string_view_t delimeters = " ",
                            bool keep_delimeters = false);

#ifndef BUILDING_PYBIND11

enum class NormalizeMode
{
	NFD,
	NFC,
	NFKD,
	NFKC
};

std::string normalize_unicode(const std::string& input, NormalizeMode mode);

#endif

class Harf;
class Kalima;
class Jumla;

class Harf
{
	anltk::char_t m_c;
	Kalima* m_kalima = nullptr;
	Harf* m_prev     = nullptr;
	Harf* m_next     = nullptr;

public:
	Harf(char32_t c);

	static Harf create(char_t c);

	anltk::char_t c();

	friend std::ostream& operator<<(std::ostream& os, const Harf& h);

	std::string to_string() const;

	Harf* next();

	Harf* prev();

	Harf* next() const;

	Harf* prev() const;

	void set_next(Harf* next);

	void set_prev(Harf* prev);

	Kalima* kalima();

	void set_kalima(Kalima* kalima);

	bool operator==(std::string_view str) const noexcept;

	bool operator==(anltk::char_t c) const noexcept;
};

class Kalima
{
public:
	using container_t      = std::list<Harf>;
	using iterator_t       = typename container_t::iterator;
	using const_iterator_t = typename container_t::const_iterator;

private:
	container_t m_huroof;
	Kalima* m_next = nullptr;
	Kalima* m_prev = nullptr;
	std::string m_text;

public:
	Kalima(anltk::string_view_t text);

	iterator_t begin();

	iterator_t end();

	const_iterator_t begin() const;

	const_iterator_t end() const;

	Harf* first();

	Harf* last();

	Kalima* next();

	Kalima* prev();

	void set_next(Kalima* next);

	void set_prev(Kalima* prev);

	std::string to_string();

	size_t size() const;

	bool operator==(std::string_view str) const noexcept;

	friend std::ostream& operator<<(std::ostream& os, const Kalima& kalima);
};

class Jumla
{
public:
	using container_t      = std::list<Kalima>;
	using iterator_t       = typename container_t::iterator;
	using const_iterator_t = typename container_t::const_iterator;

private:
	container_t m_kalimat;
	std::string m_text;

public:
	Jumla(anltk::string_view_t text);

	Kalima* first();

	Kalima* last();

	iterator_t begin();

	iterator_t end();

	const_iterator_t begin() const;

	const_iterator_t end() const;

	size_t size() const;

	std::string to_string();

	bool operator==(std::string_view str) const noexcept;

	friend std::ostream& operator<<(std::ostream& os, const Jumla& jumla);
};

// Incomplete, do not use
std::string rafal_stem(
    const std::string& word,
    const std::vector<std::string>& stop_words
    = { "ابا‬",          "‫ابو‬",       "‫ابي‬",       "‫احد‬",
        "‫اخا‬",       "‫اخر‬",       "‫اخو‬",       "‫اخي‬",
        "‫اذا‬",       "‫اال‬",       "‫االن‬",     "‫التي‬",
        "‫الذي‬",     "‫الذين‬",   "‫اللتان‬", "‫اللتين‬",
        "‫اللذان‬", "حول‬",          "‫حيث‬",       "‫حين‬",
        "‫خالل‬",     "‫دون‬",       "‫ذا‬",         "‫ذات‬",
        "‫ذلك‬",       "‫ذو‬",         "‫ذي‬",         "‫رغم‬",
        "‫شيء‬",       "‫صار‬",       "‫صبح‬",       "‫صبر‬",
        "‫ضحى‬",       "‫ضد‬",         "‫لذلك‬",     "‫لعل‬",
        "‫لكن‬",       "‫لم‬",         "‫لماذا‬",   "‫لن‬",
        "‫له‬",         "‫لو‬",         "‫ليت‬",       "‫ليس‬",
        "‫ما‬",         "‫ماانفك‬", "‫مابرح‬",   "‫ماذا‬",
        "‫مازال‬",   "‫مافتئ‬",   "‫مايزال‬", "‫متى‬",
        "‫مساء‬",     "‫مسي‬",       "‫مع‬",         "‫مما‬",
        "‫من‬",         "‫منذ‬",       "‫نحو‬",       "‫نفس‬",
        "‫هؤالء‬",   "‫هذا‬",       "‫هذه‬",       "‫هل‬",
        "‫هن‬",         "‫هنا‬",       "‫هو‬",         "‫هي‬",
        "‫هما‬",       "‫هم‬",         "‫وسط‬",       "‫يكون‬",
        "‫يلي‬",       "‫يمكن‬",     "‫يوم‬",       "‫ضمن‬",
        "‫ظل‬",         "‫عل‬",         "‫على‬",       "‫عن‬",
        "‫عند‬",       "‫عين‬",       "‫غير‬",       "‫ف‬",
        "‫فقط‬",       "‫في‬",         "‫فيما‬",     "‫قبل‬",
        "‫قد‬",         "‫ك‬",           "‫كان‬",       "‫كذلك‬",
        "‫كل‬",         "‫كم‬",         "‫كون‬",       "‫كي‬",
        "‫كيف‬",       "‫ل‬",           "‫ال‬",         "‫الزال‬",
        "‫السيما‬", "‫لدي‬",       "‫اليزال‬", "‫اللذين‬",
        "‫الي‬",       "‫اليوم‬",   "‫اما‬",       "‫امام‬",
        "‫امس‬",       "‫ان‬",         "‫او‬",         "‫اول‬",
        "‫اين‬",       "‫اي‬",         "‫ب‬",           "‫بات‬",
        "‫بان‬",       "‫بد‬",         "‫بدل‬",       "‫بعد‬",
        "‫بعض‬",       "‫بل‬",         "‫بيت‬",       "‫بين‬",
        "‫تحت‬",       "‫تكون‬",     "‫تلك‬",       "‫ثم‬",
        "‫جدا‬",       "‫حالي‬",     "‫حتى‬" },
    const std::vector<std::string>& prefixes
    = { "بال", "فال", "كال", "ال", "لل", "وال", "و", "س", "ف" },
    const std::vector<std::string>& suffixes
    = { "هما", "كما", "ات", "يه", "ته", "ان", "ون",  "ين", "هم", "هن",
        "ها",  "نا",  "وا", "كم", "كن", "ني", "وني", "تم", "ه",  "ي" },
    const std::vector<std::string>& patterns
    = { "يفعل",    "فاعل",    "فعلى",     "فعلة",     "تفعل",     "فعول",    "فعيل ",   "فعال",
        "يفعلون",  "مفعل",    "أفعل",     "فاعلة",    "فاعول",    "فعلاء",   "فعلان",   "فعولة",
        "فعيلة",   "فعلية",   "فعائل",    "فعالي",    "فعالة",    "فعواعل",  "فعالل",   "افعال",
        "افعلة",   "تفعلة",   "تفعيل",    "مفعال",    "مفعيل",    "مفعول",   "مفعلة",   "مفاعل",
        "مفتعل ",  "متفعل",   "منفعل",    "مفعلل",    " فعللة",   "فعلانة",  "تفعيلة",  "افتعال",
        "انفعال",  "إفعالي",  "إفعالا",   "أفعلاء",   "أفعلية",   "فاعولة",  "فعلولة",  "فعالية",
        "مستفعل",  "مفاعلة",  "مفاعيل",   "منفعلة",   "مفعلية",   "مفعولة",  "مفتعلة",  "متفعلة",
        "مفعللة",  "تفاعيل",  "استفعال",  "انفعالة",  "إفتعالة",  "افتعالي", "أفعالية", "مستفعلة",
        "مفعولية", "متفاعلة", "إستفعالي", "افتعالية", "استفعالية" });

std::u32string to_32string(string_view_t input);

#define FUNC_DECL(prefix, name) bool prefix##_##name(char_t c);
#define LIFT_DECL(name) FUNC_DECL(is, name)

LIFT_DECL(HAMZA)
LIFT_DECL(ALEF_MADDA)
LIFT_DECL(ALEF_HAMZA_ABOVE)
LIFT_DECL(WAW_HAMZA_ABOVE)
LIFT_DECL(ALEF_HAMZA_BELOW)
LIFT_DECL(YEH_HAMZA_ABOVE)
LIFT_DECL(ALEF_NO_HAMZA)
LIFT_DECL(BEH)
LIFT_DECL(TEH_MARBOOTA)
LIFT_DECL(TEH)
LIFT_DECL(THEH)
LIFT_DECL(JEEM)
LIFT_DECL(HAH)
LIFT_DECL(KHAH)
LIFT_DECL(DAL)
LIFT_DECL(THAL)
LIFT_DECL(REH)
LIFT_DECL(ZAAY)
LIFT_DECL(SEEN)
LIFT_DECL(SHEEN)
LIFT_DECL(SAD)
LIFT_DECL(DAD)
LIFT_DECL(TAH)
LIFT_DECL(ZAH)
LIFT_DECL(AIN)
LIFT_DECL(GHAIN)
LIFT_DECL(FEH)
LIFT_DECL(QAF)
LIFT_DECL(KAF)
LIFT_DECL(LAM)
LIFT_DECL(MEEM)
LIFT_DECL(NOON)
LIFT_DECL(HEH)
LIFT_DECL(WAW)
LIFT_DECL(ALEF_MAQSURA)
LIFT_DECL(YEH)
LIFT_DECL(ALEF_WASLA)
LIFT_DECL(PEH)
LIFT_DECL(TCHEH)
LIFT_DECL(VEH)
LIFT_DECL(GAF)
LIFT_DECL(TATWEEL)
LIFT_DECL(TANWEEN_FATHA)
LIFT_DECL(TANWEEN_DAMMA)
LIFT_DECL(TANWEEN_KASRA)
LIFT_DECL(FATHA)
LIFT_DECL(DAMMA)
LIFT_DECL(KASRA)
LIFT_DECL(SHADDA)
LIFT_DECL(SUKUN)
LIFT_DECL(FASLA)
LIFT_DECL(QUESTION_MARK)
LIFT_DECL(FASLA_MANKOOTA)
LIFT_DECL(NOKTATAN)
LIFT_DECL(NESBA)
LIFT_DECL(TA3AJJOB)
LIFT_DECL(KAWS_MAFTOOH)
LIFT_DECL(KAWS_MAKFOOL)
LIFT_DECL(DARB)
LIFT_DECL(JAM3)
LIFT_DECL(KESMA)
LIFT_DECL(TAR7)
LIFT_DECL(YOSAWI)
LIFT_DECL(NOQTA)
LIFT_DECL(SEFR)
LIFT_DECL(WAHED)
LIFT_DECL(ETHNAN)
LIFT_DECL(THALATHA)
LIFT_DECL(ARBA3A)
LIFT_DECL(KHAMSA)
LIFT_DECL(SETTA)
LIFT_DECL(SAB3A)
LIFT_DECL(THAMANEYA)
LIFT_DECL(TES3A)
LIFT_DECL(SMALL_ALEF)
LIFT_DECL(SMALL_WAW)
LIFT_DECL(SMALL_YEH)

} // namespace anltk

#endif
