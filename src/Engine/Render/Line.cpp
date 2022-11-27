#include "Line.h"
#include "../window.h"

namespace Napicu {

    LineVector::LineVector(const glm::vec2& from, const glm::vec2& to, const glm::vec3& color, int lifeTime)
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