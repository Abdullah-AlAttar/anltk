# Migration from setup.py to Meson-Python

## Overview

The project has been migrated from using `setuptools` with a manual `setup.py` to using `meson-python` as the build backend. This eliminates the need to manually list and compile all C++ source files in Python code.

## What Changed

### Before (setup.py approach)
- ❌ Manually listed all C++ source files in `setup.py`
- ❌ Had to filter out specific files (like `unicode_normalization.cpp`)
- ❌ Duplicate build logic between Meson (for C++) and setuptools (for Python)
- ❌ Had to manually specify include directories, compile flags, etc.
- ❌ Required maintaining `MANIFEST.in` for source distribution
- ❌ Old pybind11 version (2.9.2)

### After (meson-python approach)
- ✅ Single source of truth: Meson build system
- ✅ Reuses existing `anltk_dep` from `anltk/src/meson.build`
- ✅ No duplicate C++ file lists
- ✅ Cleaner separation: C++ build logic stays in Meson
- ✅ Modern pybind11 (>=2.11.0)
- ✅ Simpler and more maintainable

## File Changes

### 1. `pyproject.toml` - Updated build system
```toml
[build-system]
requires = ["meson-python", "pybind11>=2.11.0"]
build-backend = "mesonpy"

[project]
name = "anltk"
dynamic = ["version"]  # Version extracted from version.py
# ... rest of metadata
```

### 2. `python/anltk_module/meson.build` - NEW
Defines the Python extension module:
- Uses pybind11 dependency
- Links against existing `anltk_dep` (all C++ code)
- Installs Python source files
- Installs the compiled extension module

### 3. `meson.build` (root) - Updated
- Now extracts version from `python/anltk_module/anltk/version.py`
- Conditionally builds Python bindings with `python_bindings` option
- Automatically enabled when building through pip/meson-python

### 4. `meson_options.txt` - Added option
```meson
option('python_bindings', type : 'boolean', value : false, 
       description : 'Build Python bindings (enabled automatically by meson-python)')
```

### 5. `setup.py` - Can be REMOVED (deprecated)
The file is no longer needed! Meson-python handles everything.

## How to Build

### Development Installation (Editable)
```bash
# Install in editable mode
pip install -e . -v

# Or with specific meson options
pip install -e . --config-settings=setup-args="-Dbuild_tests=false" -v
```

### Build Wheel
```bash
# Build wheel in dist/
pip install build
python -m build

# Or using pip directly
pip wheel . -v
```

### Local Build with Meson (C++ only)
```bash
# Build C++ library without Python bindings
meson setup build --buildtype=release -Dbuild_tests=true -Dpython_bindings=false
meson compile -C build

# Build with Python bindings (if you want to test locally)
meson setup build_with_python --buildtype=release -Dpython_bindings=true
meson compile -C build_with_python
```

### Install from Source
```bash
pip install .
```

## Advantages of This Approach

### 1. **No Manual File Listing**
The C++ source files are already defined in `anltk/src/meson.build`. The Python extension simply links against the `anltk_dep` dependency which includes everything.

### 2. **Single Build System**
```
Old way: Meson (C++) + setuptools (Python) = 2 build systems
New way: Meson (everything) via meson-python = 1 build system
```

### 3. **Automatic Dependency Handling**
Meson automatically tracks:
- All C++ source dependencies
- Header dependencies
- Third-party libraries (utfcpp, utf8proc)
- Compile flags and include paths

### 4. **Better Cross-Platform Support**
Meson has excellent cross-platform support and meson-python inherits this, making it easier to build wheels for:
- Linux (manylinux wheels)
- macOS (universal2 wheels)
- Windows (MSVC)

### 5. **Cleaner Project Structure**
```
anltk/
├── meson.build              # C++ library build
├── pyproject.toml          # Python package metadata
└── python/
    └── anltk_module/
        ├── meson.build     # Python extension build
        └── anltk/
            ├── __init__.py
            ├── anltk.py
            ├── version.py
            └── pybind/
                └── anltk_pybind.cpp
```

## Version Management

Version is managed in a single place:
```python
# python/anltk_module/anltk/version.py
__version__ = "1.0.4"
```

Both Meson and the Python package automatically use this version.

## CI/CD Updates

For GitHub Actions workflows building wheels, update to:

```yaml
- name: Build wheels
  uses: pypa/cibuildwheel@v2.16
  env:
    CIBW_BUILD: cp3{8,9,10,11,12}-*
```

Or for manual builds:
```yaml
- name: Install dependencies
  run: pip install build meson-python pybind11

- name: Build wheel
  run: python -m build
```

## Migration Checklist

- [x] Update `pyproject.toml` to use meson-python
- [x] Create `python/anltk_module/meson.build`
- [x] Update root `meson.build` with Python bindings option
- [x] Add `python_bindings` option to `meson_options.txt`
- [x] Extract version dynamically from `version.py`
- [ ] Test local installation: `pip install -e . -v`
- [ ] Test wheel build: `python -m build`
- [ ] Update CI/CD workflows
- [ ] Delete `setup.py` (once everything works)
- [ ] Delete `MANIFEST.in` (not needed with meson-python)

## Troubleshooting

### Issue: "Could not find pybind11"
```bash
pip install pybind11
# or
conda install pybind11
```

### Issue: "meson-python not found"
```bash
pip install meson-python
```

### Issue: Version extraction fails
Check that `python3` is in PATH and can import the version module.

### Issue: Need to rebuild
```bash
pip uninstall anltk
pip install -e . -v --force-reinstall --no-cache-dir
```

## References

- [Meson-Python Documentation](https://meson-python.readthedocs.io/)
- [Pybind11 Meson Integration](https://pybind11.readthedocs.io/en/stable/compiling.html#modules-with-meson-python)
- [Scientific Python Development Guide](https://learn.scientific-python.org/development/guides/packaging-compiled/)
