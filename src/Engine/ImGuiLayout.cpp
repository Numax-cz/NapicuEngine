#include "ImGuiLayout.h"
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include "imgui_impl_opengl3.h"
#include <iostream>


namespace Napicu{



    ImGuiLayout::ImGuiLayout(GLFWwindow *glfWwindow) : glfWwindow(glfWwindow) {

    }

    void ImGuiLayout::initImGui() {
        ImGui::CreateContext();
        ImGui::StyleColorsDark();
        ImGui_ImplGlfw_InitForOpenGL(this->glfWwindow, true);
        ImGui_ImplOpenGL3_Init("#version 460");
        }


    void ImGuiLayout::update() {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
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
}