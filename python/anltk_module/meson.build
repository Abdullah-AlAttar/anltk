# Python bindings for ANLTK using pybind11

py = import('python').find_installation(pure: false)
pybind11_dep = dependency('pybind11', version: '>=2.11.0')

# Python extension module
py.extension_module(
    'anltk_pybind',
    sources: [
        'anltk/pybind/anltk_pybind.cpp',
    ],
    dependencies: [
        pybind11_dep,
        anltk_dep,
    ],
    install: true,
    subdir: 'anltk',
)

# Install pure Python files
py.install_sources(
    [
        'anltk/__init__.py',
        'anltk/anltk.py',
        'anltk/version.py',
    ],
    subdir: 'anltk',
    preserve_path: false,
)

# Install constants subpackage
py.install_sources(
    [
        'anltk/constants/__init__.py',
        'anltk/constants/constants.py',
    ],
    subdir: 'anltk/constants',
    preserve_path: false,
)

# Install tests subpackage (optional, can be removed if you don't want to ship tests)
py.install_sources(
    [
        'anltk/tests/dummy.py',
        'anltk/tests/utils_tests.py',
    ],
    subdir: 'anltk/tests',
    preserve_path: false,
)
