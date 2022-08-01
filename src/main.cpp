#include <iostream>

#include "Engine/window.h"
#include "Engine/Utils/Console.h"


int main(){

    Napicu::Window* window = new Napicu::Window("window", 1280, 720);

    window->Run();
    

    //Napicu::Console::Info("Hello, world!");



    return 0;

}