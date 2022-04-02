from typing import Callable, Dict, List, Tuple
import anltk_pybind

from anltk_pybind import AR2BW, BW2AR, AR2SBW, SBW2AR



class TafqitOptions:

    def __init__(self,
                 is_feminine: bool = False,
                 use_comma: bool = False,
                 split_hundred: bool = False,
                 use_miah: bool = False,
                 use_billion: bool = False,
                 has_followup_text: bool = False,
                 is_accusative: bool = False,
                 subjects: List[str] = [],
                 use_legal_form: bool = False) -> None:

        self.is_feminine = is_feminine
        self.use_comma = use_comma
        self.split_hundred = split_hundred
        self.use_miah = use_miah
        self.use_billion = use_billion
        self.has_followup_text = has_followup_text
        self.is_accusative = is_accusative
        self.subjects = subjects
        self.use_legal_form = use_legal_form


def tafqit(num: int, opts: TafqitOptions = TafqitOptions()) -> str:
    """Converts a number into Arabic spoken form
    * {is_feminine}     : "on": Generate string for a Feminine subject (أرقام بصيغة المؤنث).
    *                        The default is the Masculine form.
    * {use_miah}         : "on": Use Mi'ah for Hundreds (مئة بدل مائة). Default is Ma'ah "مائة".
    * {use_comma}        : "on": Insert comma between triplet words.
    * {split_hundred}    : "on": Split number from hundred words (فصل الرقم عن المئة).
                       i.e. ثلاث مائة. Default "No Split" i.e. (ثلاثمائة).
    * {use_billion}     : "on": Use Billions (بليون) instead of Miliard (مليار).
    * {has_followup_text} : "on": Indicates that there will be text to follow the resulting text.
    *                  This permits proper subject name to be added after the resulting text.
    * {is_accusative}           : "on": Text is produced in Accusative/Genitive (جر/نصب) case.
    *                  The default is the Nominative cse (رفع).
    *
    * {subjects}       : An optional array holding the Subject Name to be counted in 4 forms as follows:
    *                  [0] = Deafult Name Singular      (e.g. "كتاب/تفاحة/دينار").
    *                  [1] = Name for 2's (double)      (e.g. "كتابان/تفاحتان/ديناران").
    *                  [2] = Name for plural            (e.g. "كتب/تفاحات/دنانير").
    *                  [3] = Name Singular with Tanween (e.g. "كتابًا/تفاحةً/دينارًا").
    *                  The subject name will be added to the resulting string in acordance
    *                  with the number grammar rules.
    * {use_legal_form}        : "on" Uses the lagal form of output text.
    """
    opts_ = anltk_pybind.TafqitOptionsType()
    opts_.is_feminine = opts.is_feminine
    opts_.use_comma = opts.use_comma
    opts_.split_hundred = opts.split_hundred
    opts_.use_miah = opts.use_miah
    opts_.use_billion = opts.use_billion
    opts_.has_followup_text = opts.has_followup_text
    opts_.is_accusative = opts.is_accusative
    opts_.subjects = opts.subjects
    opts_.use_legal_form = opts.use_legal_form
    return anltk_pybind.tafqit(num, opts_)


def transliterate(text: str, mapping: anltk_pybind.CharMapping) -> str:
    """ Convert between famous characters mapping

    Args:
        text (str): input text
        mapping (anltk_pybind.CharMapping): Mapping type 
            AR2BW : Arabic to buckwalter
            AR2SBW : Arabic to safe buckwalter
            BW2AR: Buckwalter to arabic
            SBW2AR : Safe buckwalter to arabic
    Returns:
        [str]
    Example : 
        `anltk.transliterate("أبجد هوز حطي كلمن سعفص قرشت ثخذ ضظغ", anltk.AR2BW) `\n 
        `'>bjd hwz HTy klmn sEfS qr$t vx* DZg ` 
    """
    return anltk_pybind.transliterate(text, mapping)


def tokenize_words(text: str) -> List[str]:
    return anltk_pybind.tokenize_words(text)


def is_tashkeel(c: str) -> bool:
    return anltk_pybind.is_tashkeel(c)


def is_arabic_alpha(c: str) -> bool:
    return anltk_pybind.is_arabic_alpha(c)


def is_small(c: str) -> bool:
    return anltk_pybind.is_small(c)


def is_indic_digit(c: str) -> bool:
    return anltk_pybind.is_indic_digit(c)


def is_valid_kalima(c: str) -> bool:
    return anltk_pybind.is_valid_kalima(c)


def is_shamsi(c: str) -> bool:
    return anltk_pybind.is_shamsi(c)


def is_qamari(c: str) -> bool:
    return anltk_pybind.is_qamari(c)


def remove_tashkeel(text: str) -> str:
    return anltk_pybind.remove_tashkeel(text)


def remove_small(text: str) -> str:
    return anltk_pybind.remove_small(text)


def remove_non_alpha(text: str, stop_list: str = ' ') -> str:
    return anltk_pybind.remove_non_alpha(text, stop_list)


def remove_non_alpha_and_tashkeel(text: str, stop_list: str = ' ') -> str:
    return anltk_pybind.remove_non_alpha_and_tashkeel(text, stop_list)


def remove_non_alphanumeric(text: str, stop_list: str = ' ') -> str:
    return anltk_pybind.remove_non_alphanumeric(text, stop_list)


def remove_non_alphanumeric_and_tashkeel(text: str,
                                         stop_list: str = ' ') -> str:
    return anltk_pybind.remove_non_alphanumeric_and_tashkeel(text, stop_list)


def remove_kasheeda(text: str) -> str:
    return anltk_pybind.remove_kasheeda(text)


def normalize_hamzat(text: str) -> str:
    return anltk_pybind.normalize_hamzat(text)


def duplicate_shadda_letter(text: str) -> str:
    return anltk_pybind.duplicate_shadda_letter(text)


def remove_if(text: str, stop_list: str, func: Callable) -> str:
    return anltk_pybind.remove_if(text, stop_list, func)


def replace(text: str, chars_map: Dict[str, str]):
    return anltk_pybind.replace(text, chars_map)


def replace_str(text: str, chars_map: Dict[str, str]):
    return anltk_pybind.replace_str(text, chars_map)


def replace_if(text: str, func: Callable, replacement: str) -> str:
    return anltk_pybind.replace_if(text, func, replacement)


def fold_if(text: str, func: Callable) -> str:
    return anltk_pybind.fold_if(text, func)


def fold_white_spaces(text: str) -> str:
    return anltk_pybind.fold_white_spaces(text)


def split(text: str,
          delimeters: str = ' ',
          keep_delimeters: bool = False) -> List[str]:
    return anltk_pybind.split(text, delimeters, keep_delimeters)


def normalize_to_heh(text: str) -> str:
    return anltk_pybind.normalize_to_heh(text)


def normalize_to_teh(text: str) -> str:
    return anltk_pybind.normalize_to_teh(text)


def tokenize_if(text: str, funcs: List[Callable]) -> List[Tuple[int, str]]:
    return anltk_pybind.tokenize_if(text, funcs)


class NoiseGenerator:

    def __init__(self) -> None:
        self.ng = anltk_pybind.NoiseGenerator() # Default random seed

    def set_seed(self, seed: int):
        self.ng.set_seed(seed)

    def swap_adjacent_chars(self, text: str, n: int = 1) -> str:
        return self.ng.swap_adjacent_chars(text, n)

    def insert_random_chars(self, text: str, n: int = 1) -> str:
        return self.ng.insert_random_chars(text, n)
    
    def remove_random_chars(self, text:str, n : int = 1) -> str:
        return self.ng.remove_random_chars(text, n)

    def replace_random_chars(self, text:str, n : int = 1) -> str:
        return self.ng.replace_random_chars(text, n)

    def join_random_words(self, text:str, n : int = 1) -> str:
        return self.ng.join_random_words(text, n)
    
    def swap_random_words(self, text:str, n : int = 1) -> str:
        return self.ng.swap_random_words(text, n) 