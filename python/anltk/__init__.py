
import os
import sys

from .anltk_cffi import ffi as _ffi


def open_dll():
    dlldir = os.path.abspath(os.path.dirname(__file__))
    if sys.platform == 'win32':
        os.environ["PATH"] = dlldir + os.pathsep + os.environ['PATH']
        if hasattr(os, 'add_dll_directory'):
            os.add_dll_directory(dlldir)
        return _ffi.dlopen(os.path.join(dlldir, "libanltk.dll"))
    elif sys.platform == 'linux':
        return _ffi.dlopen(os.path.join(dlldir, "libanltk.so"))
    elif sys.platform == 'darwin':
        return _ffi.dlopen(os.path.join(dlldir, "libanltk.dyld"))
    else:
        raise TypeError(
            "Unsupported platform, only windows, linux, darwin are supported")


_c = open_dll()

CM_AR2BW: int = _c.CM_AR2BW
CM_BW2AR: int = _c.CM_BW2AR


class Transliterator:

    def __init__(self, mapping):
        self._ttor = _c.anltk_transliterator_new(mapping)

    def __del__(self):
        _c.anltk_transliterator_free(self._ttor)

    def convert(self, input: str) -> str:
        return _ffi.string(
            _c.anltk_transliterator_convert(self._ttor, input.encode('utf-8'))
        ).decode('utf-8')


class Mofaqqet:

    def __init__(self,  is_ordinal: bool,  is_feminine: bool):
        self._mof = _c.anltk_mofaqqet_new(is_ordinal, is_feminine)

    def __del__(self):
        _c.anltk_mofaqqet_free(self._mof)

    def tafqeet(self, number: int) -> str:
        return _ffi.string(
            _c.anltk_mofaqqet_tafqeet(self._mof, number)
        ).decode('utf-8')


class Preprocessor:

    def __init__(self):
        self._handle = _c.anltk_preprocessor_new()

    def __del__(self):
        _c.anltk_preprocessor_free(self._handle)

    def remove_tashkeel(self, input: str) -> str:
        return _ffi.string(
            _c.anltk_preprocessor_remove_tashkeel(self._handle, input.encode('utf-8'))
        ).decode('utf-8')
    def remove_small(self, input: str) -> str:
        return _ffi.string(
            _c.anltk_preprocessor_remove_small(self._handle, input.encode('utf-8'))
        ).decode('utf-8')



def ar_to_bw(text: str) -> str:
    mapping = CM_AR2BW
    ttor = Transliterator(mapping)
    return ttor.convert(text)


def bw_to_ar(text: str) -> str:
    mapping = CM_BW2AR
    ttor = Transliterator(mapping)
    return ttor.convert(text)


def tafqeet(number: int, is_ordinal: bool = False, is_feminine: bool = False) -> str:
    mof = Mofaqqet(is_ordinal, is_feminine)
    return mof.tafqeet(number)


def is_valid_kalima(input_text: str) -> bool:
    return _c.anltk_is_valid_kalima(input_text.encode('utf-8'))


def is_tashkeel(input_text: str) -> bool:
    return _c.anltk_is_tashkeel(input_text.encode('utf-8'))


def is_arabic_alpha(input_text: str) -> bool:
    return _c.anltk_is_arabic_alpha(input_text.encode('utf-8'))

def remove_tashkeel(input_text : str) -> str:
    p = Preprocessor()
    return p.remove_tashkeel(input_text)

def remove_small(input_text : str) -> str:
    p = Preprocessor()
    return p.remove_small(input_text)