#include <utility>
#include "window.h"
#include "LevelEditor.h"
#include "Level.h"


namespace Napicu {
    inline Napicu::Scene Window::*current_scene = nullptr;

    Window::Window(const std::string &title, int width, int height)
            : title(std::move(title)), width(width), height(height) {}

    void Window::Run() {
        this->Init();
        this->Loop();
        this->Destroy();
    }

    void Window::ChangeScene(int scene_index) {
        switch (scene_index) {
            case 0:
                Window::current_scene = new Napicu::LevelEditor();
                break;
            case 1:
                Window::current_scene = new Napicu::Level();
                break;
            default:
                Napicu::Console::Error("Unknown scene");
                break;
        }

        if (Window::current_scene) {
            Window::current_scene->init();
            Window::current_scene->start();
        }
    }

    void Window::Init() {

        try {
            if (!glfwInit()) {
                throw std::runtime_error("Unable to initialize GLFW");
            }
        } catch (const std::exception &e) {
            Napicu::Console::Error(e.what());
        }


        glfwDefaultWindowHints();
        glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
        glfwWindowHint(GLFW_MAXIMIZED, GLFW_FALSE);

        try {
            this->window = glfwCreateWindow(this->width, this->height, this->title.c_str(), nullptr, nullptr);
            if (this->window == nullptr) {
                throw std::runtime_error("Failed to creat the GLFW window");
            }
        } catch (const std::exception &e) {
            Napicu::Console::Error(e.what());
        }

        glfwMakeContextCurrent(this->window);

        glfwSwapInterval(1); //TODO V-Sync

        glfwShowWindow(this->window);

        gladLoadGL();

        glEnable(GL_BLEND);
        glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);

        this->imGuiLayout = new Napicu::ImGuiLayout(this->window);
        this->imGuiLayout->initImGui();


        this->ChangeScene(0);

    }

    void Window::Loop() {
        while (!glfwWindowShouldClose(this->window)) {

            double current_frame = glfwGetTime();
            this->delta_time = current_frame - this->last_frame;
            this->last_frame = current_frame;

            glfwPollEvents();

            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            if (this->delta_time >= 0) {
                Napicu::Window::current_scene->update(this->delta_time);
            }

            this->imGuiLayout->update();
            //Render ImGui
            this->imGuiLayout->render();


            glfwSwapBuffers(this->window);
        }
    }

    void Window::Destroy() {
        this->imGuiLayout->destroy();

    }


}

