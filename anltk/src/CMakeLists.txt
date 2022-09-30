
set(
	ANLTK_SOURCES
	char_maps.cpp
	transliteratation.cpp
	tafqeet.cpp
	tafqit.cpp
	utils.cpp
	preprocessing.cpp
	tokenization.cpp
	jumla.cpp
	unicode_normalization.cpp
	noise.cpp
)

add_library(
	anltk
	STATIC
	${ANLTK_SOURCES}
)

target_link_libraries(
	anltk
	utf8cpp
	utf8proc
)

target_include_directories(
	anltk
	PUBLIC
	"../include"
)

set_target_properties(
	anltk 
	PROPERTIES 
	CXX_STANDARD 20
)

if (WIN32)
	message(STATUS "HELLO WINDOWS")
	target_compile_definitions(
		anltk
		PUBLIC
		UTF_CPP_CPLUSPLUS=201703L
	)
	target_compile_options(
		anltk 
		PUBLIC
		/utf-8
	)
endif()