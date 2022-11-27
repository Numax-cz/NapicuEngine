#pragma once

#include <iostream>
#include <list>

#include "Shader.h"
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

namespace Napicu {
    class LineVector{
    private:
        glm::vec2 from;
        glm::vec2 to;
        glm::vec3 color;
        int lifeTime;
    public:
        LineVector(const glm::vec2& from, const glm::vec2& to, const glm::vec3& color, int lifeTime);

        int beginFrame();

        glm::vec2 getFrom();

        glm::vec2 getTo();

        glm::vec3 getColor();

        int getLifeTime();
    };

}