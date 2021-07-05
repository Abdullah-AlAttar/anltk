project('anltk', 'c', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++17'])


CXX = meson.get_compiler('cpp')


utfcpp_dep = declare_dependency(
    include_directories : include_directories('./third_party/utfcpp/source')
)

subdir('./third_party/MemMap')

subdir('src')

anltk_cpp_args = ['-DBUILDING_ANLTK']

anltk_lib = library('anltk', 
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
  dependencies : [CXX.find_library('dl'), utfcpp_dep, memap_dep]
)


subdir('tests')


# Make this library usable from the system's
# package manager.
install_headers('./include/anltk/anltk_api.h', subdir : 'anltk')


pkg_mod = import('pkgconfig')

pkg_mod.generate(
  name : 'ANLTK',
  filebase : 'anltk',
  description : 'Arabic Natural Language Toolkit (ANLTK)',
  subdirs : 'anltk',
  libraries : anltk_lib,
  version : meson.project_version(),
)

