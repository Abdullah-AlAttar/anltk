cmake_minimum_required(VERSION 3.14)

# Note: update this to your new project's name and version
project(
  anltk
  VERSION 1.0
  LANGUAGES CXX
)


if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
  message(
    FATAL_ERROR
      "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there."
  )
endif()


include(cmake/CPM.cmake)

CPMAddPackage(
  NAME CPMLicenses.cmake 
  GITHUB_REPOSITORY cpm-cmake/CPMLicenses.cmake
  VERSION 0.0.5
)


add_subdirectory(anltk)

