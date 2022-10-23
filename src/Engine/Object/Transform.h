#pragma once

#include <glm/vec2.hpp>


namespace Napicu {

    struct ObjectTransform {
        glm::vec2 position;
        glm::vec2 scale;
        int zIndex;

        ObjectTransform() : position(*new glm::vec2(1, 1)), scale(*new glm::vec2(1, 1)), zIndex(0) {}

        ObjectTransform(glm::vec2 position) : position(position), scale(*new glm::vec2(1, 1)) {}

        ObjectTransform(glm::vec2 position, glm::vec2 scale) : position(position), scale(scale), zIndex(0) {}

        ObjectTransform(glm::vec2 position, glm::vec2 scale, int zIndex) : position(position), scale(scale),
                                                                           zIndex(zIndex) {}

        ObjectTransform *copy();

        void copy(ObjectTransform *to);

        bool equals(ObjectTransform *obj);
    };

}