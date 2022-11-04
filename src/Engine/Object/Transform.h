#pragma once

#include <glm/vec2.hpp>


namespace Napicu {

    struct ObjectTransform {
        glm::vec2 position = *new glm::vec2(1, 1);
        glm::vec2 scale = *new glm::vec2(1, 1);
        int zIndex;

        ObjectTransform(): zIndex(0) {}

        ObjectTransform(glm::vec2 position) : position(position) {}

        ObjectTransform(glm::vec2 position, glm::vec2 scale) : position(position), scale(scale), zIndex(0) {}

        ObjectTransform(glm::vec2 position, glm::vec2 scale, int zIndex) : position(position), scale(scale),
                                                                           zIndex(zIndex) {}

        void setPositionX(float x) {this->position.x = x;}
        void setPositionY(float y) {this->position.y = y;}

        ObjectTransform copy();

        void copy(ObjectTransform& to);

        bool equals(ObjectTransform *obj);
    };

}