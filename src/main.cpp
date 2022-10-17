#include <iostream>
#include "Engine/window.h"

int main() {

    Napicu::Window *window = new Napicu::Window("window", 1280, 720);

    window->Run();

    return 0;

}