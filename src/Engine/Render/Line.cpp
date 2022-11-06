#include "Line.h"
#include "../window.h"
#include <glm/vec2.hpp>

namespace Napicu {

    void Line::start() {
        glGenBuffers(1, &Line::vboID);
        glGenBuffers(1, &Line::vaoID);

        glBindBuffer(GL_ARRAY_BUFFER, Line::vboID);
        glBindVertexArray(Line::vaoID);

        glBufferData(GL_ARRAY_BUFFER, (GLsizeiptr) ((Line::max_lines * 6 * 2) * sizeof(float)),
                     Line::vertexArray, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), nullptr);
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) (3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        glLineWidth(2.0f);

        Line::shader.compile();

        Line::started = true;
    }

    void Line::beginFrame() {
        if (!Line::started) Line::start();
        Line::lines.size();
        for(int i = 0; i < Line::lines.size(); i++){
            if(Line::lines[i]->beginFrame() < 0) {
                Line::lines.erase(Line::lines.begin() + i);
                i--;
            }
        }
    }

    void Line::draw() {
        if (Line::lines.size() <= 0) return;
        int index = 0;

        for (Napicu::LineVector *line: Line::lines) {
            for (int i = 0; i < 2; i++) {
                glm::vec2 position = (i == 0) ? line->getFrom() : line->getTo();
                glm::vec3 color = line->getColor();
                //Position
                Line::vertexArray[index] = position.x;
                Line::vertexArray[index + 1] = position.y;
                Line::vertexArray[index + 2] = -10.0f; //IDK
                //Color
                Line::vertexArray[index + 3] = color.x;
                Line::vertexArray[index + 4] = color.y;
                Line::vertexArray[index + 5] = color.z;

                index += 6;
            }
        }

        glBindBuffer(GL_ARRAY_BUFFER, Line::vboID);
        glBufferSubData(GL_ARRAY_BUFFER, 0, (GLsizeiptr) ((Line::lines.size() * 2 * 6) * sizeof(float)),
                        Line::vertexArray);
        glBindVertexArray(Line::vaoID);

        //Shader
        Line::shader.use();
        Line::shader.uploadUniformMat4("uViewProjection",
                                         Napicu::Window::current_scene->getCamera().getViewProjectionMatrix());

        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);

        glDrawArrays(GL_LINES, 0, Line::lines.size() * 6 * 2);

        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);
        glBindVertexArray(0);


        Line::shader.detach();
    }

    void Line::addLine(glm::vec2 from, glm::vec2 to) {
        Line::addLine(from, to, *new glm::vec3(1, 0, 0), 1);
    }

    void Line::addLine(glm::vec2 from, glm::vec2 to, glm::vec3 color) {
        Line::addLine(from, to, color, 1);
    }

    void Line::addLine(glm::vec2 from, glm::vec2 to, glm::vec3 color, int lifeTime) {
        if (Line::lines.size() >= Line::max_lines) return;
        Line::lines.push_back(new Napicu::LineVector(from, to, color, lifeTime));
    }

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