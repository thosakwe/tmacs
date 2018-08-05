include(ExternalProject)
include(ProcessorCount)
ProcessorCount(NUM_CORES)

add_executable(${TMACS}
        runtime/defs.h
        runtime/duk_config.h
        runtime/duktape.c runtime/duktape.h
        runtime/EditorWindow.cpp runtime/EditorWindow.h
        runtime/runtime.h
        runtime/Tmacs.cpp runtime/Tmacs.h
        runtime/Toolbar.cpp runtime/Toolbar.h
        main.cpp runtime/JSEngine.cpp runtime/JSEngine.h)

target_link_libraries(${TMACS} ${CURSES_LIBRARIES} dukglue)
install(TARGETS ${TMACS} RUNTIME DESTINATION bin)