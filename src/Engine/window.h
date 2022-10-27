#pragma once

#include <iostream>


#if !defined(__gl_h_)
    #include "glad/glad.h"
#endif

#include "GLFW/glfw3.h"
#include "Scene.h"
#include "ImGuiLayout.h"

namespace Napicu {
    class Scene;

    class Window {
    private:
        GLFWwindow *glfwWindow;
        Napicu::ImGuiLayout *imGuiLayout;
        inline static Window *window;

        std::string title;
        int width, height;
        double last_frame, delta_time;


    public:
        Window();

        inline static Napicu::Scene *current_scene;

        static void ChangeScene(int scene_index);

        void run();

        static Window* get() {
            if(Window::window == nullptr){
                Window::window = new Window();
            }
            return Window::window;
        }

        float static getWidth() {return Window::get()->width;}
        int static getHeight() {return Window::get()->height;}


    protected:
        void Loop();

        void Init();

        void Destroy();
    };
}

