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
        LineVector(glm::vec2 from, glm::vec2 to, glm::vec3 color, int lifeTime);

        int beginFrame();

        glm::vec2 getFrom();

        glm::vec2 getTo();

        glm::vec3 getColor();

        int getLifeTime();
    };


    class Line {

    private:
        inline static int max_lines = 500;
        inline static std::vector<Napicu::LineVector *> lines = {};
        inline static float *vertexArray = new float[max_lines * 6 * 2];
        inline static Napicu::Shader shader = *new Napicu::Shader("src/Engine/shaders/line.glsl");
        inline static bool started = false;

        inline unsigned static int vaoID, vboID;

    public:
        static void start();

        static void addLine(glm::vec2 from, glm::vec2 to);

        static void addLine(glm::vec2 from, glm::vec2 to, glm::vec3 color);

        static void addLine(glm::vec2 from, glm::vec2 to, glm::vec3 color, int lifeTime);

        static void beginFrame();

        static void draw();

    };
}