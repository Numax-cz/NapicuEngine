#include <utility>
#include "window.h"
#include "Scenes/LevelEditor.h"
#include "Scenes/Level.h"
#include "Events/MouseEvent.h"
#include "Render/Draw.h"

namespace Napicu {
    inline Napicu::Scene Window::*current_scene = nullptr;

    Window::Window()
            : title("Window"), width(1280), height(720) {

    }

    void Window::run() {
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
            Window::current_scene->load();
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
            this->glfwWindow = glfwCreateWindow(this->width, this->height, this->title.c_str(), nullptr, nullptr);
            if (this->window == nullptr) {
                throw std::runtime_error("Failed to creat the GLFW window");
            }
        } catch (const std::exception &e) {
            Napicu::Console::Error(e.what());
        }

        glfwSetMouseButtonCallback(this->glfwWindow, MouseEvent::mouseEventButtonCallback);
        glfwSetCursorPosCallback(this->glfwWindow, MouseEvent::mouseEventPositionCallback);
        glfwSetScrollCallback(this->glfwWindow, MouseEvent::mouseEventScrollCallback);
        glfwSetWindowSizeCallback(this->glfwWindow, Window::windowSizeCallback);

        glfwMakeContextCurrent(this->glfwWindow);

        glfwSwapInterval(1); //TODO V-Sync

        glfwShowWindow(this->glfwWindow);

        gladLoadGL();

        glEnable(GL_BLEND);
        glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);

        this->imGuiLayout = new Napicu::ImGuiLayout(this->glfwWindow);
        this->imGuiLayout->initImGui();


        this->ChangeScene(0);

    }

    void Window::Loop() {
        while (!glfwWindowShouldClose(this->glfwWindow)) {

            double current_frame = glfwGetTime();
            this->delta_time = current_frame - this->last_frame;
            this->last_frame = current_frame;

            this->imGuiLayout->update(this->current_scene);
            Napicu::Draw::beginFrame();

            glfwPollEvents();

            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            if (this->delta_time >= 0) {
                Napicu::Draw::draw();
                Napicu::Window::current_scene->update(this->delta_time);
            }

            //Render ImGui
            this->imGuiLayout->render();


            glfwSwapBuffers(this->glfwWindow);
        }
    }

    void Window::Destroy() {
        this->imGuiLayout->destroy();

    }

    void Window::windowSizeCallback(GLFWwindow *window, int width, int height) {
        Window::get()->setWidth(width);
        Window::get()->setHeight(height);
        glViewport(0, 0, width, height);
    }


}

