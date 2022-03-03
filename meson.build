project('anltk', 'c', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++20'])


host_system = host_machine.system()

CXX = meson.get_compiler('cpp')

message(CXX.get_id())
if host_system == 'windows' and CXX.get_id() == 'msvc'
  # add_global_link_arguments('/utf-8', language : 'cpp')
  add_global_arguments('/utf-8', language : 'cpp')
  add_global_arguments('/DUTF_CPP_CPLUSPLUS=201703L', language : 'cpp')
endif


subdir('anltk')