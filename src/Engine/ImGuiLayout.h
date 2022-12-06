#pragma once

#include <GLFW/glfw3.h>
#include "Scene.h"
#include "Scenes/Editor/EditorView.h"
#include "Scenes/Editor/Inspector.h"

namespace Napicu {
    class ImGuiLayout {

    private:
        GLFWwindow *glfWwindow;
        Napicu::EditorView editorView;
        Napicu::Inspector inspectorView;

    public:


        ImGuiLayout(GLFWwindow *glfWwindow, Napicu::Select* selectedTexture);

        void initImGui();

        void update(float delta_time, Napicu::Scene *scene);

        void destroy();

        void dockSpace();
    };
}


