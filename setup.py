import os
import sys
import setuptools
import shutil
import glob
import platform


# Figure out environment for cross-compile
anltk_source = os.getenv("ANLTK_SOURCE", os.path.abspath(os.path.dirname(__file__)))
system = os.environ.get('ANLTK_PLATFORM', platform.system())
architecture = os.environ.get('ANLTK_ARCHITECTURE', platform.architecture()[0])

# Create OS-dependent, but Python-independent wheels.
try:
    from wheel.bdist_wheel import bdist_wheel
except ImportError:
    cmdclass = {}
else:
    class bdist_wheel_tag_name(bdist_wheel):
        def get_tag(self):
            abi = 'none'
            if system == 'Darwin':
                oses = 'macosx_10_6_x86_64'
            elif system == 'Windows' and architecture == '32bit':
                oses = 'win32'
            elif system == 'Windows' and architecture == '64bit':
                oses = 'win_amd64'
            elif system == 'Linux' and architecture == '64bit':
                oses = 'linux_x86_64'
            elif system == 'Linux':
                oses = 'linux_' + architecture
            else:
                raise TypeError("Unknown build environment")
            return 'py3', abi, oses
    cmdclass = {'bdist_wheel': bdist_wheel_tag_name}

with open("README.md", "r") as fh:
    long_description = fh.read()


include_dirs = [os.path.join(anltk_source, 'anltk', 'subprojects', 'pybind11-2.6.1', 'include'),
                os.path.join(anltk_source, 'anltk', 'include'),
                os.path.join(anltk_source, 'anltk', 'third_party', 'utfcpp', 'source')]

library_dirs = []

cflags = ["-std=c++17", "-O3"]
ldflags = []

anltk_src_files = map(str, os.listdir(os.path.join(anltk_source, 'anltk' , 'src')))
anltk_src_cpp = list(filter(lambda x: x.endswith('.cpp'), anltk_src_files))
anltk_src_cpp = list(
    map(lambda x: str(os.path.join(anltk_source, 'anltk', 'src', x)), anltk_src_cpp)
)

anltk_module = setuptools.Extension(
    "anltk",
    sources=[os.path.join(anltk_source , 'python' , 'anltk_py.cpp')] + anltk_src_cpp,
    extra_compile_args=cflags,
    extra_link_args=ldflags,
    include_dirs=include_dirs,
    library_dirs=library_dirs
)


setuptools.setup(
    name="anltk",
    version="0.1.4",
    author="Abdullah Alattar",
    author_email="abdullah.mohammad.alattar@gmail.com",
    description="Arabic language processing toolkit",
    long_description=long_description,
    long_description_content_type="text/markdown",
    url="https://github.com/Abdullah-AlAttar/anltk",
    packages=setuptools.find_packages(),
    cmdclass=cmdclass,
    python_requires='>=3',
    project_urls={
        "Source": "https://github.com/Abdullah-AlAttar/anltk",
    },
    ext_modules=[anltk_module],
    zip_safe=False,
    include_package_data=True
)
