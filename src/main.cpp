// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "runtime/runtime.h"

int main() {
    tmacs::Tmacs env;
    env.Begin();
    return env.GetExitCode();
}