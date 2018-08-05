// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "defs.h"
#include "EditorWindow.h"

tmacs::EditorWindow::EditorWindow(Tmacs *env, WINDOW *wnd) {
    this->env = env;
    this->wnd = wnd;
    box(wnd, 0, 0);
}

tmacs::EditorWindow::~EditorWindow() {
    delwin(wnd);
}

void tmacs::EditorWindow::HandleKey(chtype ch) {
    if (mode == EDIT) {
        HandleKeyInEditMode(ch);
    } else if (mode == COMMAND) {
        HandleKeyInCommandMode(ch);
    }

    prev = ch;
}

void tmacs::EditorWindow::HandleKeyInEditMode(chtype ch) {
    if (ch == KEY_ESC) {
        // Switch to command mode
        mode = COMMAND;
    } else {
        waddch(wnd, ch);
    }

    wrefresh(wnd);
}

void tmacs::EditorWindow::HandleKeyInCommandMode(chtype ch) {
    if (ch == KEY_ENTER) {
        // Execute the current command

    } else if (ch == 'e' || ch == 'E') {
        // Return to edit mode
        mode = EDIT;
    }
}
