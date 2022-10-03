#include <iostream>
#include <crtdbg.h>
#include "Engine/window.h"
#include "Engine/Utils/Console.h"
#include "Engine/Object.h"

int main(){

    Napicu::Window* window = new Napicu::Window("window", 1280, 720);

    window->Run();

    Napicu::Object* object = new Napicu::Object("xd");

    //Napicu::Console::Info("Hello, world!");



    return 0;

}