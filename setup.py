import os
import setuptools
import platform
import pybind11
from pybind11.setup_helpers import Pybind11Extension, build_ext

# Figure out environment for cross-compile
anltk_source = os.getenv("ANLTK_SOURCE",
                         os.path.abspath(os.path.dirname(__file__)))            
system = os.environ.get('ANLTK_PLATFORM', platform.system())

with open("README.md", "r", encoding='utf-8') as fh:
    long_description = fh.read()


def _get_project_version():
    version_path = os.path.join(anltk_source, "python", "anltk_module",
                                "anltk", "version.py")
    version = {}
    with open(version_path, encoding="utf-8") as fp:
        exec(fp.read(), version)
    return version["__version__"]


include_dirs = [
    pybind11.get_include(),
    os.path.join(anltk_source, 'anltk', 'include'),
    os.path.join(anltk_source, 'subprojects', 'utfcpp', 'source')
]

cflags = ['-O3']
ldflags = []

if system == 'Windows':
    cflags = ['/O2', '/utf-8']

anltk_src_files = map(str,
                      os.listdir(os.path.join(anltk_source, 'anltk', 'src')))
anltk_src_cpp = list(filter(lambda x: x.endswith('.cpp'), anltk_src_files))
anltk_src_cpp.remove('unicode_normalization.cpp')
anltk_src_cpp = list(
    map(lambda x: str(os.path.join(anltk_source, 'anltk', 'src', x)),
        anltk_src_cpp))

anltk_pybind_module_cpp = os.path.join(anltk_source, 'python', 'anltk_module',
                                       'anltk', 'pybind', 'anltk_pybind.cpp')
ext_modules = [
    Pybind11Extension("anltk_pybind",
                      sources=anltk_src_cpp + [anltk_pybind_module_cpp],
                      extra_compile_args=cflags,
                      cxx_std=17,
                      extra_link_args=ldflags,
                      include_dirs=include_dirs,
                      define_macros=[("UTF_CPP_CPLUSPLUS", "201703L"),
                                     ("BUILDING_PYBIND11", "1")])
]

setuptools.setup(
    name="anltk",
    version=_get_project_version(),
    author="Abdullah Alattar",
    author_email="abdullah.mohammad.alattar@gmail.com",
    description="Arabic language processing toolkit",
    long_description=long_description,
    long_description_content_type="text/markdown",
    url="https://github.com/Abdullah-AlAttar/anltk",
    cmdclass={"build_ext": build_ext},
    python_requires='>=3',
    project_urls={
        "Source": "https://github.com/Abdullah-AlAttar/anltk",
    },
    ext_modules=ext_modules,
    zip_safe=False,
    include_package_data=False,
    package_dir={str(''): str('python/anltk_module')},
    packages=[str('anltk'),
              str('anltk.constants'),
              str('anltk.tests')],
    classifiers=[
        'Development Status :: 4 - Beta',
        'Intended Audience :: Developers',
        'Intended Audience :: Science/Research',
        'Programming Language :: Python :: 3',
        'Topic :: Software Development',
        'Topic :: Scientific/Engineering',
        'Topic :: Scientific/Engineering :: Artificial Intelligence',
        'Natural Language :: Arabic',
        'Operating System :: Microsoft :: Windows',
        'Operating System :: POSIX',
        'Operating System :: Unix',
        'Operating System :: MacOS',
    ],
    keywords=['NLP', 'Arabic', 'python', 'arabic', 'c++'])
