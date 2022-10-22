#pragma once
#include <GLFW/glfw3.h>


namespace Napicu {
    class ImGuiLayout{

    private:
        GLFWwindow* glfWwindow;



    public:


        ImGuiLayout(GLFWwindow *glfWwindow);
        void initImGui();
        void update();
        void render();
        void destroy();
    };
}


