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
Note: Currently only tested on Linux  
The Library depends on https://github.com/nemtrif/utfcpp.git, which is cloned automatically.  
you also need a modern C++ Compiler, which supports C++17
also meson and ninja needs to be installed.  
simply with pip
```bash
pip install meson
pip install ninja
```

```bash
git clone --recurse-submodules https://github.com/Abdullah-AlAttar/anltk.git \
    && cd anltk/anltk \
    && meson build --buildtype=release -Dbuild_tests=false \
    && cd build \
    && ninja \
    && cd ../../python \
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



## Benchmarks

Processing a file containing 2499995 line, 563522705 characters. the task is to remove diacritics.

### **Reading entire file into a string then a single call to remove_tashkeel:**


| Method           | Time          |   |   |   
|------------------|---------------|---|---|
| anltk python-api | 5.001 seconds |   |   |   
| anltk cpp-api      | 3.507 seconds |   |   |   
| python (camel_tools)  | 23.46 seconds |   |   |   
### **Processing the file line by line:**

| Method           | Time          |   |   |   
|------------------|---------------|---|---|
| anltk python-api | 7.636 seconds |   |   |   
| anltk cpp-api      | 3.601 seconds |   |   |   
| python (camel_tools)   | 22.37 seconds |   |   |   