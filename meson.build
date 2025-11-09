project('anltk', 'c', 'cpp',
  version : run_command('python3', '-c', 
    'exec(open("python/anltk_module/anltk/version.py").read()); print(__version__)',
    check: true).stdout().strip(),
  default_options : ['warning_level=3', 'cpp_std=c++17'])


host_system = host_machine.system()

CXX = meson.get_compiler('cpp')

message(CXX.get_id())
if host_system == 'windows' and CXX.get_id() == 'msvc'
  # add_global_link_arguments('/utf-8', language : 'cpp')
  add_global_arguments('/utf-8', language : 'cpp')
  add_global_arguments('/DUTF_CPP_CPLUSPLUS=201703L', language : 'cpp')
endif


subdir('anltk')

# Python bindings (for pip install / meson-python builds)
# This will only be active when building through meson-python
if get_option('python_bindings')
  subdir('python/anltk_module')
endif