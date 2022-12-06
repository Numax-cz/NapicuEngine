#include "Inspector.h"
#include <imgui.h>
#include "../../Events/MouseEvent.h"
#include "../../window.h"


namespace Napicu{


    Inspector::Inspector(Napicu::Select* selectedTexture)
            : selectedTexture(selectedTexture) {
    }



    void Inspector::imgui() {
        if (this->activeGameObject != nullptr) {
            ImGui::Begin("Inspector");
            this->activeGameObject->imGui();
            ImGui::End();
        }
    }

    void Inspector::update(float delta_time, Scene *scene) {
        if(Napicu::MouseEvent::mouseButtonDown(GLFW_MOUSE_BUTTON_LEFT)){
            int y = (int)Napicu::MouseEvent::getScreenY();
            int x = (int)Napicu::MouseEvent::getScreenX();
        }
    }



}