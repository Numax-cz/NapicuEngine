#pragma once


#ifndef OPENGL_CONSOLE_H
#define OPENGL_CONSOLE_H
#include <iostream>

namespace Napicu{
    struct Console {
        static void Log(std::string msg);
        static void Info(std::string info);
        static void Error(std::string error);
    };
}


#endif //OPENGL_CONSOLE_H
