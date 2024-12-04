cmake_minimum_required(VERSION 3.15)
project(maurilib
    LANGUAGES CXX
    DESCRIPTION "mauriba's collection of C++ code snippets and utility functions"
    VERSION 0.0.0
)

# Allows Clangd LSP to understand include directories for this project
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

add_subdirectory(src)
add_subdirectory(samples)
