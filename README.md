![example workflow](https://github.com/Abdullah-AlAttar/anltk/actions/workflows/c-cpp.yml/badge.svg)
![example workflow](https://github.com/Abdullah-AlAttar/anltk/actions/workflows/wheels.yml/badge.svg)
[![PyPI version](https://badge.fury.io/py/anltk.svg)](https://badge.fury.io/py/anltk)
[![License](https://img.shields.io/badge/License-Boost_1.0-lightblue.svg)](https://www.boost.org/LICENSE_1_0.txt)
# Arabic Natural Language Toolkit (ANLTK)

ANLTK is a set of Arabic natural language processing tools. developed with focus on simplicity and performance.

## ANLTK is a C++ library, with python bindings.

## Installation

for python :
```
pip install anltk
```
## Building
Note: Currently only tested on Linux, prebuilt python wheels are available for Linux, Windows, Macos on [pypi](https://pypi.org/project/anltk/)
### Dependencies: 
* [utfcpp](https://github.com/nemtrif/utfcpp.git), automatically downloaded.
* [utf8proc](https://github.com/JuliaStrings/utf8proc), automatically downlaoded.
* C++ Compiler that supports c++17.
* Python3, [meson](https://mesonbuild.com/), [ninja](https://ninja-build.org/)
```bash
pip install meson
pip install ninja
```

```bash
git clone https://github.com/Abdullah-AlAttar/anltk.git \
    && cd anltk/ \
    && meson build --buildtype=release -Dbuild_tests=false \
    && cd build \
    && ninja \
    && cd ../ \
    && pip install -e .
```

## Usage Examples:

### C++ API :
```c++
#include "anltk/anltk.hpp"
#include <iostream>
#include <string>

int main()
{

    std::string ar_text = "أبجد هوز حطي كلمن سعفص قرشت ثخذ ضظغ";

    std::cout << anltk::transliterate(ar_text, anltk::CharMapping::AR2BW) << '\n';
    // >bjd hwz HTy klmn sEfS qr$t vx* DZg

    std::string text = "فَرَاشَةٌ مُلَوَّنَةٌ تَطِيْرُ في البُسْتَانِ، حُلْوَةٌ مُهَنْدَمَةٌ تُدْهِشُ الإِنْسَانَ.";

    std::cout << anltk::remove_tashkeel(text) << '\n';
    // فراشة ملونة تطير في البستان، حلوة مهندمة تدهش الإنسان.

    // Third paramters is a stop_list, charactres in this list won't be removed
    std::cout << anltk::remove_non_alpha(text, " ") << '\n';
    // فراشة ملونة تطير في البستان حلوة مهندمة تدهش الإنسان

    anltk::TafqitOptions opts;
    std::cout<< anltk::tafqit(15000120, opts) <<'\n';
    // خمسة عشر مليونًا ومائة وعشرون
}

```

### Python API

```python
import anltk


ar = "أبجد هوز حطي كلمن سعفص قرشت ثخذ ضظغ"
bw = anltk.transliterate(ar, anltk.AR2BW)
print(bw)
# >bjd hwz HTy klmn sEfS qr$t vx* DZg

print(anltk.remove_tashkeel("فَرَاشَةٌ مُلَوَّنَةٌ تَطِيْرُ في البُسْتَانِ، حُلْوَةٌ مُهَنْدَمَةٌ تُدْهِشُ الإِنْسَانَ."))

# فراشة ملونة تطير في البستان، حلوة مهندمة تدهش الإنسان.

print(anltk.tafqit(15000120))
# خمسة عشر مليونًا ومائة وعشرون
```

**For list of features see [Features.md](Features.md)**


## Benchmarks

Processing a file containing 500000 Line, 6787731 Word, 112704541 Character. the task is to remove diacritics / transliterate to buckwalter



### **Buckwatler transliteration**

| Method           | Time          |   |   |   
|------------------|---------------|---|---|
| anltk python-api | 1.379 seconds |   |   |   
| python [camel_tools](https://github.com/CAMeL-Lab/camel_tools)  | 11.46 seconds |   |   |   
### **Remove Diacritics**

| Method           | Time          |   |   |   
|------------------|---------------|---|---|
| anltk python-api | 0.989 seconds |   |   |   
| python [camel_tools](https://github.com/CAMeL-Lab/camel_tools)   | 4.892 seconds |   |   |   
