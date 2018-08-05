add_executable(tmacs
        runtime/defs.h
        runtime/EditorWindow.cpp runtime/EditorWindow.h
        runtime/runtime.h
        runtime/Tmacs.cpp runtime/Tmacs.h
        runtime/Toolbar.cpp runtime/Toolbar.h
        main.cpp)
target_link_libraries(tmacs ${CURSES_LIBRARIES} ${LIBJIT} ${ANTLR4})

install(TARGETS tmacs RUNTIME DESTINATION bin)