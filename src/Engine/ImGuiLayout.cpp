#include "ImGuiLayout.h"
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include "imgui_impl_opengl3.h"


namespace Napicu{



    ImGuiLayout::ImGuiLayout(GLFWwindow *glfWwindow) : glfWwindow(glfWwindow) {

    }

    void ImGuiLayout::initImGui() {
        ImGui::CreateContext();
        ImGui_ImplGlfw_InitForOpenGL(this->glfWwindow, true);
    }

    void ImGuiLayout::newFrame() {
        ImGui_ImplGlfw_NewFrame();
    }

    void ImGuiLayout::update() {
        ImGui_ImplGlfw_NewFrame();
    }

    void ImGuiLayout::render() {


        //TODO RENDER

        ImGui::Text("ČÉst");

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    void ImGuiLayout::destroy() {
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
    }
}