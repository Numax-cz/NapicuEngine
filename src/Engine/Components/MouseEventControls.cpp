#include "MouseEventControls.h"
#include "../window.h"
#include "../Events/MouseEvent.h"

namespace Napicu {

    void MouseEventControls::pickUpObject(Napicu::Object *object) {
        this->holdingObject = object;
        Window::current_scene->addObjectToScene(this->holdingObject);
    }

    void MouseEventControls::drop() {
        this->holdingObject = nullptr;
    }

    void MouseEventControls::update(double delta_time) {
        if (this->holdingObject != nullptr) {
            this->holdingObject->transform->setPositionX(Napicu::MouseEvent::getOrthoX() - 16);
            this->holdingObject->transform->setPositionY(Napicu::MouseEvent::getOrthoY() - 16);

            if (Napicu::MouseEvent::mouseButtonDown(GLFW_MOUSE_BUTTON_LEFT)) {
                this->drop();
            }
        }
    }
}
