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
            EDIT,
            COMMAND
        };

    public:
        explicit EditorWindow(Tmacs *env, WINDOW *wnd);

        ~EditorWindow();

        void HandleKey(chtype ch);


    private:
        std::ostringstream commandBuf;
        Mode mode = EDIT;
        int prev;
        Tmacs *env;
        WINDOW *wnd;

        void HandleKeyInEditMode(chtype ch);

        void HandleKeyInCommandMode(chtype ch);
    };
}

#endif //TMACS_EDITORWINDOW_H
