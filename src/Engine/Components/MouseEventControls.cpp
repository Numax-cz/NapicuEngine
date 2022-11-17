#include "MouseEventControls.h"
#include "../window.h"
#include "../Events/MouseEvent.h"
#include "../Utils/Config.h"

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

            int x = (int)(Napicu::MouseEvent::getOrthoX() / Napicu::Config::GRID_WIDTH) *  Napicu::Config::GRID_WIDTH;
            int y = (int)(Napicu::MouseEvent::getOrthoY() / Napicu::Config::GRID_HEIGHT) *  Napicu::Config::GRID_HEIGHT;


            this->holdingObject->transform.setPositionX(x);
            this->holdingObject->transform.setPositionY(y);

            if (Napicu::MouseEvent::mouseButtonDown(GLFW_MOUSE_BUTTON_LEFT)) {
                this->drop();
            }
        }
    }
}
