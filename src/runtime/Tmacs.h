// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef TMACS_EDITOR_H
#define TMACS_EDITOR_H

#include <ncurses.h>
#include <vector>
#include "EditorWindow.h"
#include "Toolbar.h"

namespace tmacs
{
    class Tmacs
    {
    public:
        explicit Tmacs();

        ~Tmacs();

        /**
         * The result of running Tmacs.
         *
         * Typically used as the return value of `main`.
         * @return
         */
        int GetExitCode() const;

        /**
         * Start looping.
         */
        void Begin();

        /**
         * Kill the loop.
         */
        void End(int exitCode = 0);

        /**
         * Create a new window.
         * @param height
         * @param width
         * @param startY
         * @param startX
         * @return
         */
        EditorWindow *NewWindow(int height, int width, int startY = 0, int startX = 0);

        void Close(EditorWindow *wnd);

    private:
        std::vector<EditorWindow *> windows;
        EditorWindow *currentWindow = nullptr;
        int exitCode = 0;
        int maxX, maxY;
        bool running = true;
        Toolbar toolbar;
    };
}

#endif //TMACS_EDITOR_H
