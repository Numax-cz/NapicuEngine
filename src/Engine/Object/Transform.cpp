#include "Transform.h"

namespace Napicu {

    ObjectTransform ObjectTransform::copy() {
        return *new ObjectTransform(this->position, this->scale);
    }

    void ObjectTransform::copy(ObjectTransform &to) {
        to.scale = this->scale;
        to.position = this->position;
    }

    bool ObjectTransform::equals(ObjectTransform obj) {
        return (obj.scale.x == this->scale.x && obj.scale.y == this->scale.y) &&
               (obj.position.x == this->position.x && obj.position.y == this->position.y);

    }


}