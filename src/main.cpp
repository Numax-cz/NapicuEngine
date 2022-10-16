#include <iostream>
#include <crtdbg.h>
#include "Engine/window.h"
#include "Engine/Utils/Console.h"
#include "Engine/Object/Object.h"
#include "array"

int main() {

    Napicu::Window *window = new Napicu::Window("window", 1280, 720);

    window->Run();

    return 0;

}