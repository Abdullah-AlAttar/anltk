#!/usr/bin/env python3

import os
from cffi import FFI

anltk_root = os.environ.get("ANLTK_ROOT", "../anltk")
cpp_command = f"cpp {anltk_root}/include/anltk/anltk_api.h"

ffibuilder = FFI()
ffibuilder.set_source("anltk.anltk_cffi", None)
ffibuilder.cdef(os.popen(cpp_command).read())

if __name__ == '__main__':
    ffibuilder.compile(verbose=True)
