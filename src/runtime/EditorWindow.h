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
#include "JSEngine.h"

namespace tmacs
{
    class Tmacs;

    class EditorWindow
    {

    public:
        enum Mode
        {
            NONE,
            EDIT,
            COMMAND
        };

        explicit EditorWindow(Tmacs *env, WINDOW *wnd);

        Mode GetMode() const;

        void FindPositions();

        ~EditorWindow();

        void HandleKey(chtype ch);

    private:
        std::ostringstream commandBuf;
        JSEngine *js;
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
