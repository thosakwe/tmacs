cmake_minimum_required(VERSION 3.0)
project(tmacs)

set(CMAKE_CXX_STANDARD 11)
set(CURSES_NEED_NCURSES TRUE)

# Find includes
find_package(Curses REQUIRED)
find_path(LIBJIT_INCLUDE_DIR jit/jit.h)
find_path(ANTLR4_INCLUDE_DIR antlr4-runtime/antlr4-runtime.h)
include_directories(${CURSES_INCLUDE_DIR})
include_directories(${LIBJIT_INCLUDE_DIR})
include_directories(${ANTLR4_INCLUDE_DIR}/antlr4-runtime)

# Find necessary libraries
find_library(LIBJIT jit)
find_library(ANTLR4 antlr4-runtime)

add_subdirectory(src)
