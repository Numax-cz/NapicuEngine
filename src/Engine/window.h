#pragma once


#include <iostream>

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Scene.h"


namespace Napicu
{
    class Scene;
    class Window
    {
    private:
        GLFWwindow* window;

        std::string title;
        int width, height;
        double last_frame, delta_time;


    public:
        Window(const std::string& title, int width, int height);
        inline static Napicu::Scene* current_scene;
        static void ChangeScene(int scene_index);
        void Run();



    protected:
        void Loop();
        void Init();
    };
}

