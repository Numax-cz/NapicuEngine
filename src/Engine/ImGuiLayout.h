#pragma once
#include <GLFW/glfw3.h>


namespace Napicu {
    class ImGuiLayout{

    private:
        GLFWwindow* glfWwindow = nullptr;



    public:


        ImGuiLayout(GLFWwindow *glfWwindow);
        void initImGui();
        void newFrame();
        void update();
        void render();
        void destroy();
    };
}


