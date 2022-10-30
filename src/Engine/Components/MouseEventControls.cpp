#include "MouseEventControls.h"
#include "../window.h"
#include "../Events/MouseEvent.h"

namespace Napicu{

    void MouseEventControls::pickUpObject(Napicu::Object *object) {
        this->holdingObject = object;
        object->transform->position = new glm::vec2(600, 600);
    }


    void MouseEventControls::drop() {
        Window::current_scene->addObjectToScene(this->holdingObject);
        this->holdingObject = nullptr;

    }

    void MouseEventControls::update(double delta_time) {
        if(this->holdingObject != nullptr){
//
            this->holdingObject->transform->position->x = Napicu::MouseEvent::getOrthoX() - 16;
            this->holdingObject->transform->position->y = Napicu::MouseEvent::getOrthoY() - 16;


            if(Napicu::MouseEvent::mouseButtonDown(GLFW_MOUSE_BUTTON_LEFT)){
                this->drop();

            }

        }
    }

}
