#include "Line.h"
#include "../window.h"
#include <glm/vec2.hpp>

namespace Napicu {

    LineVector::LineVector(glm::vec2 from, glm::vec2 to, glm::vec3 color, int lifeTime)
            : from(from), to(to), color(color), lifeTime(lifeTime) {}

    int LineVector::beginFrame() {
        this->lifeTime--;
        return this->lifeTime;
    }

    glm::vec2 LineVector::getFrom() {
        return this->from;
    }

    glm::vec2 LineVector::getTo() {
        return this->to;
    }

    glm::vec3 LineVector::getColor() {
        return this->color;
    }

    int LineVector::getLifeTime() {
        return this->lifeTime;
    }
}