#include <GLFW/glfw3.h>
#include <GL/gl.h>

#include "window.h"
#include "Utils/Console.h"

namespace Napicu{

    Window::Window(std::string title, int width, int height)
            :title(title), width(width), height(height) {}

    void Window::Run() {

        this->Init();
        this->Loop();
    }

    void Window::Init() {

        try{
            if(!glfwInit()){
                throw std::runtime_error("Unable to initialize GLFW");
            }
        }catch (const std::exception& e){
            Napicu::Console::Error(e.what());
        }


        glfwDefaultWindowHints();
        glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
        glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);

        try {
            this->window = glfwCreateWindow(this->width, this->height, this->title.c_str(), nullptr, nullptr);
            if(this->window == nullptr) {
                throw std::runtime_error("Failed to creat the GLFW window");
            }
        } catch (const std::exception& e){
            Napicu::Console::Error(e.what());
        }

        glfwMakeContextCurrent(this->window);

        glfwSwapInterval(1); //TODO V-Sync

        glfwShowWindow(this->window);





    }

    void Window::Loop() {
        while(!glfwWindowShouldClose(this->window)){
            glfwPollEvents();


            glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            glfwSwapBuffers(this->window);
        }

    }
}

