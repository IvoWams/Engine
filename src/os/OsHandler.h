#pragma once

#ifndef ENGINE_OS_OSHANDLER_H
#define ENGINE_OS_OSHANDLER_H

#include "WindowHandle.h"

namespace engine::os
{
    class OsHandler
    {
        public:
            virtual WindowHandle* createWindow() = 0;
            virtual void destroyWindow(WindowHandle*) = 0;
    };
}

#endif