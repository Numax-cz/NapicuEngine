#pragma once
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

namespace Napicu{
    class Line{
    private:
        glm::vec2 from;
        glm::vec2 to;
        glm::vec3 color;
        int lifeTime;
    public:
        Line(glm::vec2 from, glm::vec2 to, glm::vec3 color, int lifeTime);

        int beginFrame();

        glm::vec2 getFrom();

        glm::vec2 getTo();

        glm::vec3 getColor();

        int getLifeTime();
    };
}