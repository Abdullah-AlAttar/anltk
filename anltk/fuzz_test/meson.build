

test_files = [
    'remove_diac_fuzz.cpp',
    'split_fuzz.cpp',
]

foreach test_file : test_files
    target_name = test_file.substring(0, -4)

    exe = executable(
        target_name,
        sources : [test_file],
        dependencies : [anltk_dep]
    )
    test(target_name, exe)

endforeach