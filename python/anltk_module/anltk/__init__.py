

from . import constants
from .version import __version__
from .anltk import \
    tafqeet, \
    transliterate, \
    tokenize_words, \
    is_tashkeel, \
    is_arabic_alpha, \
    is_small, \
    is_indic_digit, \
    is_shamsi, \
    is_qamari, \
    remove_tashkeel, \
    remove_small, \
    remove_non_alpha, \
    remove_non_alphanumeric, \
    remove_non_alphanumeric_and_tashkeel, \
    remove_kasheeda, \
    normalize_hamzat, \
    duplicate_shadda_letter, \
    remove_if, \
    replace, \
    replace_str
