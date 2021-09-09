project('anltk', 'c', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++17'])


host_system = host_machine.system()



if host_system == 'windows'
  # add_global_link_arguments('/utf-8', language : 'cpp')
  add_global_arguments('/utf-8', language : 'cpp')
  add_global_arguments('/DUTF_CPP_CPLUSPLUS=201703L', language : 'cpp')
endif



CXX = meson.get_compiler('cpp')


# pybind11_dep = dependency('pybind11', fallback : ['pybind11', 'pybind11_dep'])


subdir('anltk')