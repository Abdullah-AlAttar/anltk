![example workflow](https://github.com/Abdullah-AlAttar/anltk/actions/workflows/c-cpp.yml/badge.svg)

# Arabic Natural Language Toolkit (ANLTK)

ANLTK is a set of Arabic natural language processing tools. developed with focus on performance.

## ANLTK is a C++ library, with python bindings.

## Building
Note: Currently only tested on Linux  
The Library depends on https://github.com/nemtrif/utfcpp.git, which is cloned automatically.  
you also need a modern C++ Compiler, which supports C++17
also meson and ninja needs to be installed.  
simply with pip
```bash
pip3 install meson
pip3 install ninja
```

```bash
git clone --recurse-submodules https://github.com/Abdullah-AlAttar/anltk.git \
    && cd anltk/anltk \
    && meson build --default-library=shared --buildtype=release -Dbuild_tests=false \
    && cd build \
    && ninja \
    && cd ../../python \
    && python3 setup.py install
```

## Usage Examples:

### C API :
```c
#include "anltk/anltk_api.h"
#include <stdio.h>

int main()
{
    ANLTK_Transliterator* ttor = anltk_transliterator_new(CM_AR2BW);

    const char* ar_text = "أبجد هوز حطي كلمن سعفص قرشت ثخذ ضظغ";

    printf("%s\n", anltk_transliterator_convert(ttor, ar_text));
    // >bjd hwz HTy klmn sEfS qr$t vx* DZg
    anltk_transliterator_free(ttor);

    const char* text = "فَرَاشَةٌ مُلَوَّنَةٌ تَطِيْرُ في البُسْتَانِ، حُلْوَةٌ مُهَنْدَمَةٌ تُدْهِشُ الإِنْسَانَ.";

    ANLTK_Preprocessor* pr = anltk_preprocessor_new();

    printf("%s\n" , anltk_preprocessor_remove_tashkeel(pr, text) );
    // فراشة ملونة تطير في البستان، حلوة مهندمة تدهش الإنسان.  

    // Third paramters is a stop_list, charactres in this list won't be removed
    printf("%s\n" , anltk_preprocessor_remove_non_alpha(pr, text, " ") );
    // فراشة ملونة تطير في البستان حلوة مهندمة تدهش الإنسان
    
    anltk_preprocessor_free(pr);
}


```

### Python API

```python
import anltk


ar = "أبجد هوز حطي كلمن سعفص قرشت ثخذ ضظغ"
bw = anltk.ar_to_bw(ar)
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
| anltk c-api      | 3.507 seconds |   |   |   
| python (camel_tools)  | 23.46 seconds |   |   |   
### **Processing the file line by line:**

| Method           | Time          |   |   |   
|------------------|---------------|---|---|
| anltk python-api | 9.636 seconds |   |   |   
| anltk c-api      | 3.601 seconds |   |   |   
| python (camel_tools)   | 22.37 seconds |   |   |   