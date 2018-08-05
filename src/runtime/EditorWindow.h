// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef TMACS_EDITORWINDOW_H
#define TMACS_EDITORWINDOW_H

#include <ncurses.h>
#include <sstream>

namespace tmacs
{
    class Tmacs;

    class EditorWindow
    {
        enum Mode
        {
            NONE,
            EDIT,
            COMMAND
        };

    public:
        explicit EditorWindow(Tmacs *env, WINDOW *wnd);

        void FindPositions();

        ~EditorWindow();

        void HandleKey(chtype ch);

    private:
        std::ostringstream commandBuf;
        Mode mode = NONE;
        int prev;
        int maxX, maxY;
        Tmacs *env;
        WINDOW *wnd;

        void HandleKeyInEditMode(chtype ch);

        void HandleKeyInCommandMode(chtype ch);

        void ChangeMode(Mode newMode);

        void PrintModeName(const char *name);
    };
}

#endif //TMACS_EDITORWINDOW_H
