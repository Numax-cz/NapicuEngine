

#ifndef OPENGL_WINDOW_H
#define OPENGL_WINDOW_H

#include <iostream>
#include <GLFW/glfw3.h>

namespace Napicu
{
    class Window
    {
    private:
        GLFWwindow* window;
        std::string title;
        int width;
        int height;





    public:
        Window(std::string title, int width, int height);
        void Run();



    protected:
        void Loop();
        void Init();
    };

}


#endif //OPENGL_WINDOW_H
