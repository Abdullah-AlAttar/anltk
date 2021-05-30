


doctest_dep = dependency('doctest', fallback : ['doctest', 'doctest_dep'])

exe = executable(
    'anltk_test',
    sources : ['anltk_test.cpp', 'doctest_main.cpp'],
    dependencies : [anltk_dep, doctest_dep]
)

test('anltk_test', exe)


exe = executable(
    'tafqeet_test',
    sources : ['anltk_tafqeet_test.cpp', 'doctest_main.cpp'],
    dependencies : [anltk_dep, doctest_dep]
)

test('tafqeet_test', exe)



exe = executable(
    'anltk_test_c_api',
    sources : ['anltk_test.c'],
    dependencies : [anltk_dep]
)

test('anltk_test_c_api', exe)


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