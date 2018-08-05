include(ExternalProject)
include(ProcessorCount)
ProcessorCount(NUM_CORES)

# LuaJIT
ExternalProject_Add(luajit
        GIT_REPOSITORY "https://github.com/LuaJIT/LuaJIT.git"
        GIT_SHALLOW 1
        GIT_TAG b025b01
        CONFIGURE_COMMAND ""
        BUILD_COMMAND make -C <SOURCE_DIR> -j ${NUM_CORES} PREFIX=<BINARY_DIR>
        INSTALL_COMMAND make install -C <SOURCE_DIR> PREFIX=<BINARY_DIR>)

ExternalProject_Get_Property(luajit binary_dir)

include_directories(${binary_dir}/include/luajit-2.0)
link_directories(${binary_dir}/lib)

add_executable(tmacs
        runtime/defs.h
        runtime/EditorWindow.cpp runtime/EditorWindow.h
        runtime/runtime.h
        runtime/Tmacs.cpp runtime/Tmacs.h
        runtime/Toolbar.cpp runtime/Toolbar.h
        main.cpp)

find_library(LUAJIT luajit)
target_link_libraries(tmacs ${CURSES_LIBRARIES} ${LUAJIT})
add_dependencies(tmacs luajit)

install(TARGETS tmacs RUNTIME DESTINATION bin)