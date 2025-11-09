



utfcpp_dep = dependency('utfcpp', fallback : ['utfcpp', 'utfcpp_dep'])

# Force utf8proc to build as static library
# The custom overlay in subprojects/packagefiles/utf8proc sets install: false
utf8proc_dep = dependency('utf8proc', 
  fallback : ['utf8proc', 'utf8proc_dep'],
  default_options: ['default_library=static']
)

# subdir('./third_party/MemMap')

subdir('src')

argparse_dep = declare_dependency(
  include_directories : include_directories('./third_party/argeparse/include')
)

if get_option('build_tests')
  subdir('tests')
endif

if get_option('build_bin')
  subdir('bin')
endif

if get_option('build_fuzz')
  subdir('fuzz_test')
endif

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

