
enable_testing()

CPMAddPackage(
	NAME doctest
	GITHUB_REPOSITORY doctest/doctest
	GIT_TAG 2.4.7
)

include(${doctest_SOURCE_DIR}/scripts/cmake/doctest.cmake)


set(
	ANLTK_TEST_TARGETS
	anltk_char_names_test
	anltk_jumla_test
	anltk_preprocessor_test
	anltk_tafqeet_test
	anltk_tafqit_test
	anltk_tokenizer_test
	anltk_transliterator_test
	anltk_unicode_normalization_test
	anltk_utils_test
	anltk_string_utils_test
	anltk_noise_test
)

foreach(test_target ${ANLTK_TEST_TARGETS})

	message(STATUS "Adding test ${test_target}")

	add_executable(
		${test_target}
		${test_target}.cpp doctest_main.cpp
	)
	target_link_libraries(
		${test_target}
		PRIVATE
		doctest::doctest
		anltk
	)

	set_target_properties(
		${test_target} 
		PROPERTIES 
		CXX_STANDARD 20
	)
	if (WIN32)
		target_compile_definitions(
			${test_target} PRIVATE
			UTF_CPP_CPLUSPLUS=201703L
		)
		target_compile_options(
			${test_target} PRIVATE
			/utf-8
		)
	endif()
	doctest_discover_tests(${test_target})

endforeach()