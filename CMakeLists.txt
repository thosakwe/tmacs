cmake_minimum_required(VERSION 3.0)
project(tmacs)

set(CMAKE_CXX_STANDARD 11)
set(CURSES_NEED_NCURSES TRUE)

# Find includes
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_subdirectory(src)
