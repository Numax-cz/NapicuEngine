#include "ImGuiLayout.h"
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include "imgui_impl_opengl3.h"

#include "window.h"

namespace Napicu {
    ImGuiLayout::ImGuiLayout(GLFWwindow *glfWwindow) : glfWwindow(glfWwindow) {

    }

    void ImGuiLayout::initImGui() {
        ImGui::CreateContext();
        ImGui::StyleColorsDark();
        ImGui_ImplGlfw_InitForOpenGL(this->glfWwindow, true);
        ImGui_ImplOpenGL3_Init("#version 460");

        ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    }


    void ImGuiLayout::update(Napicu::Scene *scene) {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        this->dockSpace();

        scene->imGuiScene();
        ImGui::End();

    }

    void ImGuiLayout::render() {

        //TODO RENDER


        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    void ImGuiLayout::destroy() {
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
    }

    void ImGuiLayout::dockSpace() {
        bool open = true;

        ImGui::SetNextWindowPos(ImVec2(0.0f, 0.0f), ImGuiCond_Always);
        ImGui::SetNextWindowSize(ImVec2((float)Napicu::Window::getWidth(), (float)Napicu::Window::getHeight()));
        ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);

        int iw =
                ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse |
                ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
                ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;

        ImGui::Begin("Menu",&open, iw);
        ImGui::PopStyleVar(2);

        ImGui::DockSpace(ImGui::GetID("Dockspace"));
    }
}