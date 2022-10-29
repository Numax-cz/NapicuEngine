#include "MouseItem.h"
#include "../window.h"


namespace Napicu{

    void MouseItem::pickUpObject(Napicu::Object *object) {
        this->holdingObject = object;
        Window::current_scene->addObjectToScene(object);
    }

}
