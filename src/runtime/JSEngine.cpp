// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <ncurses.h>
#include "JSEngine.h"

tmacs::JSEngine::JSEngine(tmacs::EditorWindow *window, WINDOW* wnd) {
    this->window = window;
    ctx = duk_create_heap_default();

    if (!ctx) {
        mvwprintw(wnd, 0, 0, "Error: Could not initialize Duktape engine.");
        wrefresh(wnd);
        getch();
        return;
    }

    // Push native functions

}

tmacs::JSEngine::~JSEngine() {
    duk_destroy_heap(ctx);
}

const char *tmacs::JSEngine::Eval(const char *text) {
    duk_push_string(ctx, text);

    if (duk_peval(ctx) != 0) {
        return duk_safe_to_string(ctx, -1);
    } else {
        return nullptr;
    }
}
