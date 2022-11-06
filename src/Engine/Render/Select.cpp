#include "Select.h"
#include "../window.h"
#include <glm/vec2.hpp>

namespace Napicu {

    void Select::start() {
        glGenBuffers(1, &Select::vboID);
        glGenBuffers(1, &Select::vaoID);

        glBindBuffer(GL_ARRAY_BUFFER, Select::vboID);
        glBindVertexArray(Select::vaoID);

        glBufferData(GL_ARRAY_BUFFER, (GLsizeiptr) ((Select::max_lines * 6 * 2) * sizeof(float)),
                     Select::vertexArray, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), nullptr);
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) (3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        glLineWidth(2.0f);

        Select::shader.compile();

        Select::started = true;
    }

    void Select::beginFrame() {
        if (!Select::started) Select::start();
        Select::lines.size();
        for(int i = 0; i < Select::lines.size(); i++){

            if(Select::lines[i]->beginFrame() < 0){
                Select::lines.erase(Select::lines.begin() + i);
                i--;
            }



        }
    }

    void Select::draw() {
        if (Select::lines.size() <= 0) return;
        int index = 0;

        for (Napicu::Line *line: Select::lines) {
            for (int i = 0; i < 2; i++) {
                glm::vec2 position = (i == 0) ? line->getFrom() : line->getTo();
                glm::vec3 color = line->getColor();
                //Position
                Select::vertexArray[index] = position.x;
                Select::vertexArray[index + 1] = position.y;
                Select::vertexArray[index + 2] = -10.0f; //IDK
                //Color
                Select::vertexArray[index + 3] = color.x;
                Select::vertexArray[index + 4] = color.y;
                Select::vertexArray[index + 5] = color.z;

                index += 6;
            }
        }

        glBindBuffer(GL_ARRAY_BUFFER, Select::vboID);
        glBufferSubData(GL_ARRAY_BUFFER, 0, (GLsizeiptr) ((Select::lines.size() * 2 * 6) * sizeof(float)),
                        Select::vertexArray);
        glBindVertexArray(Select::vaoID);

        //Shader
        Select::shader.use();
        Select::shader.uploadUniformMat4("uViewProjection",
                                         Napicu::Window::current_scene->getCamera().getViewProjectionMatrix());

        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);

        glDrawArrays(GL_LINES, 0, Select::lines.size() * 6 * 2);

        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);
        glBindVertexArray(0);


        Select::shader.detach();
    }

    void Select::addLine(glm::vec2 from, glm::vec2 to) {
        Select::addLine(from, to, *new glm::vec3(1, 0, 0), 1);
    }

    void Select::addLine(glm::vec2 from, glm::vec2 to, glm::vec3 color) {
        Select::addLine(from, to, color, 1);
    }

    void Select::addLine(glm::vec2 from, glm::vec2 to, glm::vec3 color, int lifeTime) {
        if (Select::lines.size() >= Select::max_lines) return;
        Select::lines.push_back(new Napicu::Line(from, to, color, lifeTime));
    }

}