#include "EditorView.h"
#include "../../window.h"
#include "../../Events/MouseEvent.h"

namespace Napicu{
    void EditorView::imgui() {
        ImGui::Begin("Viewport", nullptr ,ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse );

        ImVec2 size = EditorView::getViewportSize();
        ImVec2 position = EditorView::getCenterViewportPosition(size);
        ImGui::SetCursorPos(position);

        ImVec2 tLeft = ImGui::GetCursorScreenPos();
        tLeft.x -= ImGui::GetScrollX();
        tLeft.y -= ImGui::GetScrollY();




        int textureID = Napicu::Window::getFramebuffer()->getTextureID();
        ImGui::Image(reinterpret_cast<ImTextureID>(textureID), ImVec2(size.x, size.y), ImVec2(0, 1), ImVec2(1, 0));

        Napicu::MouseEvent::setScreenViewportPosition(glm::vec2(tLeft.x, tLeft.y));
        Napicu::MouseEvent::setScreenviewportSize(glm::vec2(size.x, size.y));

        ImGui::End();
    }

    ImVec2 EditorView::getViewportSize() {
        ImVec2 size;
        size = ImGui::GetContentRegionAvail();
        size.x -= ImGui::GetScrollX();
        size.y -= ImGui::GetScrollY();

        float asW = size.x;
        float asH = asW / Napicu::Window::getAspectRation();
        if(asH > size.y){
            asH = size.y;
            asW = asH * Napicu::Window::getAspectRation();
        }

        return {asW, asH};
    }

    ImVec2 EditorView::getCenterViewportPosition(ImVec2 aspect) {
        ImVec2 size;
        size = ImGui::GetContentRegionAvail();
        size.x -= ImGui::GetScrollX();
        size.y -= ImGui::GetScrollY();

        float viewportX = (size.x / 2.0f) - (aspect.x / 2.0f);
        float viewportY = (size.y / 2.0f) - (aspect.y / 2.0f);

        return {viewportX + ImGui::GetCursorPosX(), viewportY + ImGui::GetCursorPosY()};
    }
}
