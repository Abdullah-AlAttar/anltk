
from typing import Callable, Dict, List
import anltk_pybind


from anltk_pybind import AR2BW, BW2AR, AR2SBW, SBW2AR


def tafqeet(num: int, is_ordinal: bool = False,  is_feminine: bool = False) -> str:
    """Converts a number into Arabic spoken form

    Args:
        num (int): input number
        is_ordinal (bool, optional): الأول if True, واحد if false. Defaults to False.
        is_feminine (bool, optional): الخامسة if True, الخامس if False. Defaults to False.

    Returns:
        [str]
    Example: 
        `anltk.tafqeet(1934)  ` \n
        `'ألف و تسعمئة و أربعة و ثلاثون'` 

    """
    return anltk_pybind.tafqeet(num, is_ordinal, is_feminine)


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


def remove_non_alphanumeric(text: str, stop_list: str = ' ') -> str:
    return anltk_pybind.remove_non_alphanumeric(text, stop_list)


def remove_non_alphanumeric_and_tashkeel(
        text: str, stop_list: str = ' ') -> str:
    return anltk_pybind.remove_non_alphanumeric_and_tashkeel(text, stop_list)


def remove_kasheeda(text: str) -> str:
    return anltk_pybind.remove_kasheeda(text)


def normalize_hamzat(text: str) -> str:
    return anltk_pybind.normalize_hamzat(text)


def duplicate_shadda_letter(text: str) -> str:
    return anltk_pybind.duplicate_shadda_letter(text)


def remove_if(text: str, stop_list: str, func : Callable) -> str:
    return anltk_pybind.remove_if(text, stop_list, func)


def replace(text : str, chars_map : Dict[str, str]):
    return anltk_pybind.replace(text, chars_map)

def replace_str(text : str, chars_map : Dict[str, str]):
    return anltk_pybind.replace_str(text, chars_map)