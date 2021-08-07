import os
import sys
import setuptools
import shutil
import glob
import platform


# Figure out environment for cross-compile
anltk_source = os.getenv("ANLTK_SOURCE", os.path.abspath(os.path.join(os.path.dirname(__file__), "../anltk")))
system = os.environ.get('ANLTK_PLATFORM', platform.system())
architecture = os.environ.get('ANLTK_ARCHITECTURE', platform.architecture()[0])

# Copy precompmilled librariesa
print(os.path.join(anltk_source, "build/lib*"))
for lib_path in glob.glob(os.path.join(anltk_source, "build/lib*so*")):
    if os.path.isfile(lib_path):
        print ("Adding library", lib_path)
        shutil.copy(lib_path, "anltk")

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


include_dirs = [os.path.join(anltk_source, 'subprojects', 'pybind11-2.6.1', 'include'),
                os.path.join(anltk_source, 'include'),
                os.path.join(anltk_source, 'third_party', 'utfcpp', 'source')]
library_dirs = [os.path.join(anltk_source, 'build')]
cflags = ["-std=c++17"]
ldflags = []

print(include_dirs)


ctranslate2_module = setuptools.Extension(
    "anltk",
    sources=["anltk_py.cpp"],
    extra_compile_args=cflags,
    extra_link_args=ldflags,
    include_dirs=include_dirs,
    library_dirs=library_dirs,
    libraries=["anltk"],
)


setuptools.setup(
    name="anltk",
    version="0.1.1",
    author="Abdullah Alattar",
    author_email="abdullah.mohammad.alattar@gmail.com",
    description="Arabic language processing toolkit",
    long_description=long_description,
    long_description_content_type="text/markdown",
    # url="",
    packages=setuptools.find_packages(),
    package_data = {'anltk': ['*.so', '*.dll', '*.dyld']},
    include_package_data=True,
    cmdclass=cmdclass,
    python_requires='>=3',
    ext_modules=[ctranslate2_module],
)
