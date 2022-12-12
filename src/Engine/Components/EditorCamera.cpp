#include "EditorCamera.h"
#include "../Events/MouseEvent.h"
#include "../Utils/Config.h"
#include <cmath>

namespace Napicu{

    EditorCamera::EditorCamera(Napicu::Camera* camera) :
            editorCamera(camera) { }

    void EditorCamera::update(double delta_time) {
        const float scrollY = Napicu::MouseEvent::getScrollY();

        if(Napicu::MouseEvent::mouseButtonDown(Napicu::Config::LEVEL_EDITOR_CAMERA_DRAG_KEY)){
            if(this->dragDebounce > 0){
                this->originPosition = glm::vec2(Napicu::MouseEvent::getOrthoX(),Napicu::MouseEvent::getOrthoY());
                this->dragDebounce -= (float)delta_time;
                return;
            }else {
                glm::vec2 mousePosition = Napicu::MouseEvent::getOrthoPosition();
                glm::vec2 d = mousePosition - this->originPosition;
                glm::vec2 cameraPosition = this->editorCamera->getPosition()
                        - (d * glm::vec2((float)delta_time)
                        * glm::vec2(Napicu::Config::LEVEL_EDITOR_CAMERA_DRAG_SPEED));

                this->editorCamera->setPosition(cameraPosition);
            }
        }else if(this->dragDebounce <= 0.0f){
            this->dragDebounce = 0.1f;
        }

        if(scrollY != 0.0f){
            auto zoomLevel = (float)std::pow(std::abs(scrollY) * Napicu::Config::LEVEL_EDITOR_CAMERA_SCROLL_SENSITIVITY,
                                             1 / this->editorCamera->getZoomLevel());
            zoomLevel *= -glm::sign(scrollY);

            this->editorCamera->addZoomLevel(zoomLevel);
        }

        if(Napicu::MouseEvent::mouseButtonDown(GLFW_MOUSE_BUTTON_RIGHT)){
            this->editorCamera->setPosition(glm::vec2(0.0f, 0.0f));
            this->editorCamera->resetZoomLevel();
        }


    }
}