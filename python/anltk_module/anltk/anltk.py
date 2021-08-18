
from typing import List
import anltk_pybind

from .version import __version__

from enum import Enum

from anltk_pybind import AR2BW, BW2AR, AR2SBW, SBW2AR


def tafqeet(num: int, is_ordinal: bool = False,  is_feminine: bool = False):
    return anltk_pybind.tafqeet(num, is_ordinal, is_feminine)


def transliterate(text: str, mapping: anltk_pybind.CharMapping):
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


def remove_non_alpha(
    text: str, stop_list: str = ' ') -> str: return anltk_pybind.remove_non_alpha(text, stop_list)


def remove_non_alphanumeric(
        text: str, stop_list: str = ' ') -> str:
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
