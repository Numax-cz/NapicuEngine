

#include "Line.h"

namespace Napicu {
    Line::Line(glm::vec2 from, glm::vec2 to, glm::vec3 color, int lifeTime)
            : from(from), to(to), color(color), lifeTime(lifeTime) {}

    int Line::beginFrame() {
        this->lifeTime--;
        return this->lifeTime;
    }

    glm::vec2 Line::getFrom() {
        return this->from;
    }

    glm::vec2 Line::getTo() {
        return this->to;
    }

    glm::vec3 Line::getColor() {
        return this->color;
    }

    int Line::getLifeTime() {
        return this->lifeTime;
    }
}
