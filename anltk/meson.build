



utfcpp_dep = dependency('utfcpp', fallback : ['utfcpp', 'utfcpp_dep'])


utf8proc_dep = dependency('utf8proc', fallback : ['utf8proc', 'utf8proc_dep'])

# subdir('./third_party/MemMap')

subdir('src')
anltk_cpp_args = []
# if get_option('default_library') == 'shared'
#   anltk_cpp_args = ['-DBUILDING_ANLTK']
# endif

anltk_lib = static_library('anltk', 
  include_directories: include_directories('.', './include' , './src'),
  sources : anltk_sources,
  install : true,
  cpp_args : anltk_cpp_args,
  gnu_symbol_visibility : 'hidden',
  dependencies: [utfcpp_dep, utf8proc_dep],
)

anltk_dep = declare_dependency(
  include_directories: include_directories('.', './include'),
  link_with : anltk_lib,
  dependencies : [utfcpp_dep, utf8proc_dep]
)

if get_option('build_tests')
  subdir('tests')
endif
  # subdir('tests')

# Make this library usable from the system's
# package manager.
install_headers('./include/anltk/anltk.hpp', subdir : 'anltk')


pkg_mod = import('pkgconfig')

pkg_mod.generate(
  name : 'ANLTK',
  filebase : 'anltk',
  description : 'Arabic Natural Language Toolkit (ANLTK)',
  subdirs : 'anltk',
  libraries : anltk_lib,
  version : meson.project_version(),
)

