


doctest_dep = dependency('doctest', fallback : ['doctest', 'doctest_dep'])



exe = executable(
    'anltk_transliterator_test',
    sources : ['anltk_transliterator_test.cpp', 'doctest_main.cpp'],
    dependencies : [anltk_dep, doctest_dep]
)

test('anltk_transliterator_test', exe)

exe = executable(
    'tafqeet_test',
    sources : ['anltk_tafqeet_test.cpp', 'doctest_main.cpp'],
    dependencies : [anltk_dep, doctest_dep]
)

test('tafqeet_test', exe)




exe = executable(
    'anltk_utils_test',
    sources : ['anltk_utils_test.cpp', 'doctest_main.cpp'],
    dependencies : [anltk_dep, doctest_dep]
)

test('anltk_utils_test', exe)



exe = executable(
    'anltk_preprocessor_test',
    sources : ['anltk_preprocessor_test.cpp', 'doctest_main.cpp'],
    dependencies : [anltk_dep, doctest_dep]
)

test('anltk_preprocessor_test', exe)


exe = executable(
    'dumm',
    sources : ['dummy.cpp'],
    dependencies : [anltk_dep]
)





exe = executable(
    'utfcpptest',
    sources : ['utfcpptest.cpp', anltk_sources],
    include_directories : include_directories('../src','../include'),
    dependencies : [anltk_dep]
)


exe = executable(
    'anltk_tokenizer_test',
    sources : ['anltk_tokenizer_test.cpp', 'doctest_main.cpp'],
    dependencies : [anltk_dep, doctest_dep]
)

test('anltk_tokenizer_test', exe)


exe = executable(
    'anltk_jumla_test',
    sources : ['anltk_jumla_test.cpp', 'doctest_main.cpp'],
    dependencies : [anltk_dep, doctest_dep]
)

test('anlntk_jumla_test', exe)




exe = executable(
    'anltk_unicode_normalization_test',
    sources : ['anltk_unicode_normalization_test.cpp', 'doctest_main.cpp'],
    dependencies : [anltk_dep, doctest_dep]
)

test('anltk_unicode_normalization_test', exe)


# exe = executable(
#     'anltk_stemming_test',
#     sources : ['anltk_stemming_test.cpp', 'doctest_main.cpp'],
#     dependencies : [anltk_dep, doctest_dep]
# )

# test('anltk_stemming_test', exe)