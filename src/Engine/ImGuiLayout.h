#pragma once

#include <GLFW/glfw3.h>
#include "Scene.h"

namespace Napicu {
    class ImGuiLayout {

    private:
        GLFWwindow *glfWwindow;


    public:


        ImGuiLayout(GLFWwindow *glfWwindow);

        void initImGui();

        void update(Napicu::Scene *scene);

        void destroy();

        void dockSpace();
    };
}


