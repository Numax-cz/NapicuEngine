#include <utility>
#include "window.h"
#include "Scenes/LevelEditor.h"
#include "Scenes/Level.h"
#include "Events/MouseEvent.h"
#include "Render/Draw.h"
#include "Utils/Assets.h"

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

        this->frameBuffer = new Napicu::Framebuffer((int)Window::SCREEN_SIZE_X, (int)Window::SCREEN_SIZE_Y);
        this->selectTexture = new Napicu::Select((int)Window::SCREEN_SIZE_X, (int)Window::SCREEN_SIZE_Y);
        glViewport(0, 0, (int)Window::SCREEN_SIZE_X, (int)Window::SCREEN_SIZE_Y);

        this->ChangeScene(0);

    }

    void Window::Loop() {
        Napicu::Shader *shader = Napicu::Assets::getShader("src/Engine/shaders/default.glsl");
        Napicu::Shader *pShader = Napicu::Assets::getShader("src/Engine/shaders/selectShader.glsl");

        while (!glfwWindowShouldClose(this->glfwWindow)) {

            double current_frame = glfwGetTime();
            this->delta_time = current_frame - this->last_frame;
            this->last_frame = current_frame;

            glDisable(GL_BLEND);
            this->selectTexture->enable();


            glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            Napicu::Render::bindShader(*pShader);
            Napicu::Draw::beginFrame();

            if(Napicu::MouseEvent::mouseButtonDown(GLFW_MOUSE_BUTTON_LEFT)){
                int x = (int)Napicu::MouseEvent::getX();
                int y = (int)Napicu::MouseEvent::getY();
                std::cout << y << std::endl;
            }


            glfwPollEvents();

            this->frameBuffer->bind();
            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            if (this->delta_time >= 0) {
                Napicu::Draw::draw();
                Napicu::Render::bindShader(*shader);
                Napicu::Window::current_scene->update(this->delta_time);
            }
            this->frameBuffer->unbind();
            //Render ImGui
            this->imGuiLayout->update(this->current_scene);


            glfwSwapBuffers(this->glfwWindow);
        }
        Napicu::Window::current_scene->saveSettings();
    }

    void Window::Destroy() {
        this->imGuiLayout->destroy();

    }

    void Window::windowSizeCallback(GLFWwindow *window, int width, int height) {
        Window::get()->setWidth(width);
        Window::get()->setHeight(height);
    }

    Napicu::Framebuffer* Window::getFramebuffer() {
        return Window::get()->frameBuffer;
    }

    float Window::getAspectRation() {
        return 16.0f / 9.0f;
    }


}

