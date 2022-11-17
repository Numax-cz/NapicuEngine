

#include "Console.h"

namespace Napicu {

    void Console::Log(std::string msg) {
        std::cout << "[NAPICUENGINE]" << " - " << msg << std::endl;
    }

    void Console::Info(std::string info) {
        std::cout << "[NAPICUENGINE - Info]" << " - " << info << std::endl;
    }

    void Console::Error(std::string error) {
        std::cerr << "[NAPICUENGINE - Error]" << " - " << error << std::endl;
    }
}