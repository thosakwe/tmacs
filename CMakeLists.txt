cmake_minimum_required(VERSION 3.0)
project(tmacs)

set(CMAKE_CXX_STANDARD 11)
set(CURSES_NEED_NCURSES TRUE)
set(TMACS tmacs)

# Find includes
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
include_directories(third_party/dukglue/include)

add_subdirectory(src)
add_subdirectory(third_party)
