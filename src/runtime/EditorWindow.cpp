// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <cstdlib>
#include <fstream>
#include <sstream>
#include "defs.h"
#include "EditorWindow.h"
#include "Tmacs.h"

tmacs::EditorWindow::EditorWindow(Tmacs *env, WINDOW *wnd) {
    this->env = env;
    this->js = new JSEngine(this, wnd);
    this->wnd = wnd;

    // Execute ~/.tmacs, if it exists.
    std::ostringstream rcName;

#ifdef WIN32
    rcName << std::getenv("USERPROFILE") << "\\";
#else
    rcName << std::getenv("HOME") << "/";
#endif

    rcName << ".tmacs";

    auto *rcNameStr = rcName.str().c_str();
    std::ifstream ifs(rcNameStr);

    if (ifs) {
        std::stringstream contents;
        contents << ifs.rdbuf();

        auto *err = js->Eval(contents.str().c_str());

        if (err != nullptr) {
            mvwprintw(wnd, 0, 0, "JS Error: %s\n", err);
            wrefresh(wnd);
            getch();
            return;
        }
    }

    // Window stuff
    FindPositions();
    ChangeMode(EDIT);
    wmove(wnd, 0, 0);
    wrefresh(wnd);
}

tmacs::EditorWindow::~EditorWindow() {
    delwin(wnd);
}

tmacs::EditorWindow::Mode tmacs::EditorWindow::GetMode() const {
    return mode;
}

void tmacs::EditorWindow::FindPositions() {
    getmaxyx(wnd, maxY, maxX);
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
        ChangeMode(COMMAND);
    } else {
        waddch(wnd, ch);
    }

    PrintModeName("EDIT");
    wrefresh(wnd);
}

void tmacs::EditorWindow::HandleKeyInCommandMode(chtype ch) {
    auto *name = keyname(ch);

    if (!strcmp(name, "^W") || !strcmp(name, "^w")) {
        // CTRL-W, close the window
        env->Close(this);
    } else {

        if (ch == KEY_ENTER) {
            // Execute the current command

        } else if (ch == 'e' || ch == 'E') {
            // Return to edit mode
            ChangeMode(EDIT);
        }
    }
}

void tmacs::EditorWindow::ChangeMode(tmacs::EditorWindow::Mode newMode) {
    mode = newMode;

    if (mode == EDIT) {
        PrintModeName("EDIT");
    } else {
        PrintModeName(nullptr);
    }
}

void tmacs::EditorWindow::PrintModeName(const char *name) {
    int originalY, originalX;
    getyx(wnd, originalY, originalX);

    // Clear the bottom line
    FindPositions();
    wmove(wnd, maxY, 0);
    wclrtoeol(wnd);
    wmove(wnd, maxY, 0);

    if (name != nullptr) {
        wattron(wnd, A_BOLD);
        wprintw(wnd, "-- ");
        wprintw(wnd, name);
        wprintw(wnd, " --");
        wattroff(wnd, A_BOLD);
    }

    wmove(wnd, originalY, originalX);
    wrefresh(wnd);
}
