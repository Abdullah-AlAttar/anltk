project('anltk', 'c', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++17'])


host_system = host_machine.system()

if host_system == 'windows'
  # add_global_link_arguments('/utf-8', language : 'cpp')
  add_global_arguments('/utf-8', language : 'cpp')
endif

CXX = meson.get_compiler('cpp')


pybind11_dep = dependency('pybind11', fallback : ['pybind11', 'pybind11_dep'])

utfcpp_dep = declare_dependency(
    include_directories : include_directories('./third_party/utfcpp/source')
)

subdir('./third_party/MemMap')

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
  dependencies: [utfcpp_dep, memap_dep],
)

anltk_dep = declare_dependency(
  include_directories: include_directories('.', './include'),
  link_with : anltk_lib,
  dependencies : [utfcpp_dep, memap_dep]
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

