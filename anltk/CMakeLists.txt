


CPMAddPackage("gh:JuliaStrings/utf8proc@2.7.0")

CPMAddPackage("gh:nemtrif/utfcpp@3.2.1")


add_subdirectory(src)


if (ANLTK_BUILD_TESTS)
	add_subdirectory(tests)
endif()


if (ANLTK_BUILD_BIN)
	add_subdirectory(bin)
endif()

if (ANLTK_BUILD_FUZZ)
	add_subdirectory(fuzz_test)
endif()



