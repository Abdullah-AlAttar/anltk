# Include-What-You-Use (IWYU) Configuration

## What is IWYU?

Include-What-You-Use (IWYU) is a tool that analyzes C/C++ source files and suggests which headers should be included and which can be removed. It helps maintain clean, minimal header dependencies and faster compilation times.

## Installation

### Ubuntu/Debian
```bash
sudo apt-get install iwyu
```

### Arch Linux
```bash
sudo pacman -S include-what-you-use
```

### macOS (Homebrew)
```bash
brew install include-what-you-use
```

### From Source
```bash
git clone https://github.com/include-what-you-use/include-what-you-use.git
cd include-what-you-use
git checkout clang_16  # Match your clang version
mkdir build && cd build
cmake -G "Unix Makefiles" -DCMAKE_PREFIX_PATH=/usr/lib/llvm-16 ..
make
sudo make install
```

## Running IWYU Locally

### Method 1: Direct on Single File
```bash
include-what-you-use -std=c++17 \
  -I./anltk/include \
  -I./subprojects/utfcpp/source \
  -I./subprojects/utf8proc-2.10.0 \
  anltk/src/noise.cpp
```

### Method 2: Using compile_commands.json (Recommended)
```bash
# Generate compile_commands.json with meson
cd build
meson compile --ninja

# Run IWYU on all files
iwyu_tool.py -p . | tee iwyu_output.txt

# Apply suggestions automatically (use with caution!)
fix_includes.py < iwyu_output.txt
```

### Method 3: Run on Specific Files
```bash
# Check a specific file
iwyu_tool.py -p build anltk/src/noise.cpp

# Check all source files in a directory
find anltk/src -name "*.cpp" | xargs -I {} iwyu_tool.py -p build {}
```

## IWYU Mappings

The `.iwyu_mappings` file tells IWYU about special include relationships in your project:

```yaml
# Map UTF8 library includes
{ include: ["<utf8.h>", "public", "<utf8/checked.h>", "private"] }
{ include: ["<utf8.h>", "public", "<utf8/unchecked.h>", "private"] }

# Map project headers
{ include: ["\"anltk/anltk.hpp\"", "public", "\"anltk/char_maps.h\"", "private"] }
```

## Common IWYU Pragmas

Add these comments in your code to control IWYU behavior:

```cpp
// Keep an include that IWYU wants to remove:
#include <map>  // IWYU pragma: keep

// Export a header (useful in main header file):
#include "anltk/char_maps.h"  // IWYU pragma: export

// Declare forward declaration is sufficient:
class MyClass;  // IWYU pragma: keep

// Don't suggest replacing with forward declaration:
#include "my_class.h"  // IWYU pragma: no_forward_declare MyClass
```

## Integration with CI/CD

Add to your GitHub Actions workflow:

```yaml
- name: Install IWYU
  run: sudo apt-get install -y iwyu

- name: Check includes
  run: |
    cd build
    iwyu_tool.py -p . | tee iwyu_output.txt
    # Fail if there are suggestions (optional)
    grep -q "should add these lines:" iwyu_output.txt && exit 1 || exit 0
```

## Tips

1. **Start small**: Run IWYU on one file at a time initially
2. **Review carefully**: Not all suggestions are correct, especially with templates
3. **Use pragmas**: Mark intentional includes with `// IWYU pragma: keep`
4. **Update incrementally**: Fix one module at a time, don't try to fix everything at once

## Common Issues

- **Template errors**: IWYU can be confused by template-heavy code
- **Pybind11**: May suggest removing includes that are needed for Python bindings
- **Third-party headers**: May suggest changes to library code - ignore these

## Resources

- [IWYU Documentation](https://include-what-you-use.org/)
- [IWYU GitHub](https://github.com/include-what-you-use/include-what-you-use)
