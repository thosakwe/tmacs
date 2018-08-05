// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <algorithm>
#include "Tmacs.h"

tmacs::Tmacs::Tmacs() {
    initscr(); // Init
    raw(); // Disable buffering
    keypad(stdscr, true); // Enable F1, F2, etc.
    noecho();
    getmaxyx(stdscr, maxY, maxX);
    //printw("width: %d, height: %d\n", maxX, maxY);
    refresh();
    //getch();
}

tmacs::Tmacs::~Tmacs() {
    for (auto *wnd : windows) {
        delete wnd;
    }

    endwin(); // End curses
}

int tmacs::Tmacs::GetExitCode() const {
    return exitCode;
}

void tmacs::Tmacs::Begin() {
    // Create a new window, the size of the screen.
    currentWindow = NewWindow(maxY, maxX, 0, 0);

    while (!windows.empty()) {
        currentWindow->HandleKey((chtype) getch());
    }
}

void tmacs::Tmacs::End(int exitCode) {
    running = false;
    this->exitCode = exitCode;
}

tmacs::EditorWindow *tmacs::Tmacs::NewWindow(int height, int width, int startY, int startX) {
    auto *w = newwin(height, width, startY, startX);
    auto *wnd = new EditorWindow(this, w);

    // If an initialization error occurred, delete the window.
    if (wnd->GetMode() == EditorWindow::Mode::NONE) {
        delete wnd;
        return nullptr;
    }

    windows.push_back(wnd);
    return wnd;
}

void tmacs::Tmacs::Close(tmacs::EditorWindow *wnd) {
    windows.erase(std::remove(windows.begin(), windows.end(), wnd), windows.end());
    delete wnd;
}
