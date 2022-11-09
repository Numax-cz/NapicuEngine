#pragma once
#include "Line.h"
#include "../window.h"


namespace Napicu{
    class Draw{
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