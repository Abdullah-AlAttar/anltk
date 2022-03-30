
anltk_sources = files([
    'char_maps.cpp',
    'transliteratation.cpp',
    'tafqeet.cpp',
    'tafqit.cpp',
    'utils.cpp',
    'preprocessing.cpp',
    'tokenization.cpp',
    'jumla.cpp',
    # 'stemming.cpp',
    'unicode_normalization.cpp',
    'noise.cpp'
])


anltk_cpp_args = []

anltk_lib = static_library('anltk', 
  include_directories: include_directories('.', '../include'),
  sources : anltk_sources,
  install : true,
  cpp_args : anltk_cpp_args,
  gnu_symbol_visibility : 'hidden',
  dependencies: [utfcpp_dep, utf8proc_dep],
)

anltk_dep = declare_dependency(
  include_directories: include_directories('.', '../include'),
  link_with : anltk_lib,
  dependencies : [utfcpp_dep, utf8proc_dep]
)
