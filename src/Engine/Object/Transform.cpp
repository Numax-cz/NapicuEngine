#include "Transform.h"


namespace Napicu {

    ObjectTransform *ObjectTransform::copy() {
        return new ObjectTransform(*new glm::vec2(this->position), *new glm::vec2(this->scale));
    }

    void ObjectTransform::copy(ObjectTransform *to) {
        this->scale = to->scale;
        this->position = to->position;
    }

    bool ObjectTransform::equals(ObjectTransform *obj) {
        if (obj != nullptr) {
            return (obj->scale.x == this->scale.x && obj->scale.y == this->scale.y) &&
                   (obj->position.x == this->position.x && obj->position.y == this->position.y);
        }
        return false;
    }


}