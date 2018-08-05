add_executable(tmacs
        runtime/runtime.h
        runtime/Tmacs.cpp runtime/Tmacs.h
        main.cpp)
target_link_libraries(tmacs ${CURSES_LIBRARIES} ${LIBJIT} ${ANTLR4})