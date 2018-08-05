// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef TMACS_JSENGINE_H
#define TMACS_JSENGINE_H

#include "duktape.h"

namespace tmacs
{
    class EditorWindow;

    class JSEngine
    {
    public:
        explicit JSEngine(EditorWindow *window, WINDOW* wnd);

        ~JSEngine();

        const char *Eval(const char *text);

    private:
        duk_context *ctx;
        EditorWindow *window;
    };
}

#endif //TMACS_JSENGINE_H
