


doctest_dep = dependency('doctest', fallback : ['doctest', 'doctest_dep'])

test_files = [
    'anltk_char_names_test.cpp',
    'anltk_jumla_test.cpp',
    'anltk_preprocessor_test.cpp',
    # 'anltk_stemming_test.cpp',
    'anltk_tafqeet_test.cpp',
    'anltk_tafqit_test.cpp',
    'anltk_tokenizer_test.cpp',
    'anltk_transliterator_test.cpp',
    'anltk_unicode_normalization_test.cpp',
    'anltk_utils_test.cpp',
]

foreach test_file : test_files
    message(test_file.substring(0, -4))
    exe = executable(
        test_file.substring(0, -4),
        sources : [test_file, 'doctest_main.cpp'],
        dependencies : [anltk_dep, doctest_dep]
    )
    test(test_file.substring(0, -4), exe)

endforeach


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
