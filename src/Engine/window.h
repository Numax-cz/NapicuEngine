#pragma once

#include <iostream>


#if !defined(__gl_h_)

#include "glad/glad.h"

#endif

#include "GLFW/glfw3.h"
#include "Scene.h"
#include "ImGuiLayout.h"
#include "Render/Line.h"
#include "Render/Framebuffer.h"
#include "Render/Select.h"

namespace Napicu {
    class Scene;

    class Window {
    private:
        GLFWwindow *glfwWindow;
        Napicu::ImGuiLayout *imGuiLayout;
        Napicu::Framebuffer *frameBuffer;
        Napicu::Select *selectTexture;
        inline static Window *window;

        std::string title;
        int width, height;
        double last_frame, delta_time;


    public:
        Window();

        inline static Napicu::Scene *current_scene;

        static void ChangeScene(int scene_index);

        //TODO FIX SCREEN SIZE FOR OTHER...
        static inline const float SCREEN_SIZE_Y = 1080.0f;

        static inline const float SCREEN_SIZE_X = 1920.0f;

        void run();

        static Window *get() {
            if (Window::window == nullptr) {
                Window::window = new Window();
            }
            return Window::window;
        }

        int static getWidth() { return Window::get()->width; }

        int static getHeight() { return Window::get()->height; }

        void static setWidth(int width) { Window::get()->width = width; }

        void static setHeight(int height) { Window::get()->height = height; }

        Napicu::Framebuffer static *getFramebuffer();

        float static getAspectRation();

    protected:
        static void windowSizeCallback(GLFWwindow *window, int width, int height);

        void Loop();

        void Init();

        void Destroy();
    };
}

