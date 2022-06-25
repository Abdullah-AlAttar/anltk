#ifndef ANLTK_HPP
#define ANLTK_HPP

#include "anltk/anltk_typedefs.h"
#include "anltk/char_maps.h"
#include <functional>
#include <list>
#include <map>
#include <random>
#include <vector>
namespace anltk
{

#define NO_DISCARD [[nodiscard]]

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
NO_DISCARD
std::string transliterate(string_view_t input, CharMapping mapping);

/**
 * @brief Converest given number to spoken arabic form. \n
 * @param input number, can be negative or positive
 * @param is_ordinal bool. default: false, Cardinal vs Ordinal form, eg : واحد vs الأول
 * @param is_feminine bool. default : false, Generate string for a Feminine subject (أرقام بصيغة
 * @return std::string
 * */
NO_DISCARD
// [[deprecated("Replaced by tafqit, will be removed soon")]]
std::string tafqeet(long long number, bool is_ordinal = false, bool is_feminine = false);

struct TafqitOptions
{
	bool is_feminine                  = false;
	bool use_comma                    = false;
	bool split_hundred                = false;
	bool use_miah                     = false;
	bool use_billion                  = false;
	bool has_followup_text            = false;
	bool is_accusative                = false;
	std::vector<std::string> subjects = {};
	bool use_legal_form               = false;
};
// Ported from https://github.com/MohsenAlyafei/tafqit, check it for full documentation.
NO_DISCARD
std::string tafqit(long long number, TafqitOptions opts = {});
/**
 * @brief Removes all tashkeel from the given arabic text,
 * the tashkeel list is { TANWEEN_FATHA, TANWEEN_DAMMA, TANWEEN_KASRA, FATHA, DAMMA, KASRA, SHADDA,
 * SUKUN }
 * */
NO_DISCARD
std::string remove_tashkeel(string_view_t input);
/**
 * @brief Removes small tashkeel from the given arabic text
 * the small list is { SMALL_ALEF '\u0670',  SMALL_WAW : '\u06E5', SMALL_YEH : '\u06E6'
 */
NO_DISCARD
std::string remove_small(string_view_t input);

/**
 * @brief Removes non alphapet 28 characters from the given arabic text
 * @param input
 * @param stop_list strings containing list of characters that won't be removed. each one should be
 * a single character
 */
NO_DISCARD
std::string remove_non_alpha(string_view_t input, string_view_t stop_list);

/**
 * @brief Removes non alphapet 28 characters plus tashkeel from the given arabic text
 * @param input
 * @param stop_list strings containing list of characters that won't be removed. each one should be
 * a single character
 */
NO_DISCARD
std::string remove_non_alpha_and_tashkeel(string_view_t input, string_view_t stop_list);

/**
 * @brief Removes non alphapet 28 characters from the given arabic text plus 9 digits(both Indic and
 * English)
 * @param input
 * @param stop_list strings containing list of characters that won't be removed. each one should be
 * a single character
 */
NO_DISCARD
std::string remove_non_alphanumeric(string_view_t input, string_view_t stop_list);
/**
 * @brief Removes non alphapet 28 characters from the given arabic text plus 9 digits(both Indic and
 * English) plus tashkeel list is { TANWEEN_FATHA, TANWEEN_DAMMA, TANWEEN_KASRA, FATHA, DAMMA,
 * KASRA, SHADDA, SUKUN }
 * @param input
 * @param stop_list strings containing list of characters that won't be removed. each one should be
 * a single character
 */
NO_DISCARD
std::string remove_non_alphanumeric_and_tashkeel(string_view_t input, string_view_t stop_list);
/**
 * @brief Removes Kasheesa AKA Tatweel ‬
 */
NO_DISCARD
std::string remove_kasheeda(string_view_t input);

/**
 * @brief Replaces Hamzaat forms أ, آ, إ with أ
 */
NO_DISCARD
std::string normalize_hamzat(string_view_t input);

/**
 * @brief Replaces ه with ة, only at the end of the words
 */
NO_DISCARD
std::string normalize_to_teh(string_view_t input);

/**
 * @brief Replaces ة with ه
 */
NO_DISCARD
std::string normalize_to_heh(string_view_t input);

/**
 *
 * @brief Duplicates the shadda letter
 * eg : الشّمس becomes الششمس
 */
NO_DISCARD
std::string duplicate_shadda_letter(string_view_t input);

/**
 *
 * @brief Removes characters from input that matches the functor, if that character in the stop_list
 * it won't be removed
 */
NO_DISCARD
std::string remove_if(string_view_t input, string_view_t stop_list,
                      const std::function<bool(char_t)>& func);

/**
 *
 * @brief Removes The second character, if it matches the condition
 */
NO_DISCARD
std::string fold_if(string_view_t input, const std::function<bool(char_t, char_t)>& func);
/**
 *
 * @brief Removes consecutive whitespaces, and converts all white-spaces to space ' '
 */
NO_DISCARD
std::string fold_white_spaces(string_view_t input);

/**
 *
 * @brief Basic Char replacement algorithm, Note: use python builtin function, as it is more
 * efficient
 */
NO_DISCARD
std::string replace(string_view_t input, std::map<char_t, char_t> chars_maps);

/**
 *
 * @brief Basic String replacement algorithm, Note: use python builtin function, as it is more
 * efficient
 */
NO_DISCARD
std::string replace_str(string_view_t input,
                        std::map<string_view_t, string_view_t> replacement_map);
/**
 *
 * @brief Replace a character if it matches a condition
 */
NO_DISCARD
std::string replace_if(string_view_t input, const std::function<bool(char_t)>& func,
                       char_t replacement);

bool is_tashkeel(char_t c);

bool is_arabic_alpha(char_t c);

bool is_valid_kalima(string_view_t input);

bool is_small(char_t c);

bool is_indic_digit(char_t c);

bool is_digit(char_t c);

bool is_shamsi(char_t c);

bool is_qamari(char_t c);

/**
 *
 * @brief Split input into tokens, Each Arabic word is a token.
 */
NO_DISCARD
vector_t<std::string> tokenize_words(string_view_t input);

/**
 *
 * @brief Split input into tokens, if they satisfy the input functors,
 * the result contains the functor index that made the match, and the corresponding token, -1 if it
 * matches nothing.
 */
NO_DISCARD
std::vector<std::pair<int, std::string>>
tokenize_if(string_view_t input, const std::vector<std::function<bool(char_t)>>& funcs);

/**
 *
 * @brief Basic split algorithm, Note: use Pythons builtin split,
 * @param keep_delimeters: keep the delimeters that we split on.
 */
NO_DISCARD
vector_t<std::string> split(string_view_t input, string_view_t delimeters = " ",
                            bool keep_delimeters = false);

NO_DISCARD
vector_t<std::string> split_on(string_view_t input, string_view_t delimeters,
                               int max_word_per_line);

std::string char_name(char_t c);

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

class NoiseGenerator
{
public:
	NoiseGenerator();
	std::string swap_adjacent_chars(string_view_t input, size_t n = 1);
	std::string insert_random_chars(string_view_t input, size_t n = 1);
	std::string remove_random_chars(string_view_t input, size_t n = 1);
	std::string replace_random_chars(string_view_t input, size_t n = 1);
	std::string join_random_words(string_view_t input, size_t n = 1);
	std::string swap_random_words(string_view_t input, size_t n = 1);
	void set_seed(int seed);

private:
	std::random_device rd;
	std::mt19937 gen;
};

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
	explicit Harf(char32_t c);

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
	explicit Kalima(anltk::string_view_t text);

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

	std::string to_string() const;

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
	explicit Jumla(anltk::string_view_t text);

	Kalima* first();

	Kalima* last();

	iterator_t begin();

	iterator_t end();

	const_iterator_t begin() const;

	const_iterator_t end() const;

	size_t size() const;

	std::string to_string() const;

	bool operator==(std::string_view str) const noexcept;

	friend std::ostream& operator<<(std::ostream& os, const Jumla& jumla);
};

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
LIFT_DECL(ZAIN)
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
LIFT_DECL(FATHATAN)
LIFT_DECL(DAMMATAN)
LIFT_DECL(KASRATAN)
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
