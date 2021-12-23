![example workflow](https://github.com/Abdullah-AlAttar/anltk/actions/workflows/c-cpp.yml/badge.svg)

# Arabic Natural Language Toolkit (ANLTK)

ANLTK is a set of Arabic natural language processing tools. developed with focus on performance.

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
git clone --recurse-submodules https://github.com/Abdullah-AlAttar/anltk.git \
    && cd anltk/ \
    && meson build --buildtype=release -Dbuild_tests=false \
    && cd build \
    && ninja \
    && cd ../ \
    && python3 setup.py install
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
