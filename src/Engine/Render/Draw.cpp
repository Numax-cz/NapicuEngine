#include "Draw.h"


namespace Napicu{

    void Draw::start() {
        glGenBuffers(1, &Draw::vboID);
        glGenBuffers(1, &Draw::vaoID);

        glBindBuffer(GL_ARRAY_BUFFER, Draw::vboID);
        glBindVertexArray(Draw::vaoID);

        glBufferData(GL_ARRAY_BUFFER, (GLsizeiptr) ((Draw::max_lines * 6 * 2) * sizeof(float)),
                     Draw::vertexArray, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), nullptr);
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) (3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        glLineWidth(2.0f);

        Draw::shader.compile();

        Draw::started = true;
    }

    void Draw::beginFrame() {
        if (!Draw::started) Draw::start();
        for(int i = 0; i < Draw::lines.size(); i++){
            if(Draw::lines[i]->beginFrame() < 0) {
                delete Draw::lines[i];
                Draw::lines.erase(Draw::lines.begin() + i);
                i--;
            }
        }
    }

    void Draw::draw() {
        if (Draw::lines.empty()) return;
        int index = 0;

        for (Napicu::LineVector *Draw: Draw::lines) {
            for (int i = 0; i < 2; i++) {
                glm::vec2 position = (i == 0) ? Draw->getFrom() : Draw->getTo();
                glm::vec3 color = Draw->getColor();
                //Position
                Draw::vertexArray[index] = position.x;
                Draw::vertexArray[index + 1] = position.y;
                Draw::vertexArray[index + 2] = -10.0f; //IDK
                //Color
                Draw::vertexArray[index + 3] = color.x;
                Draw::vertexArray[index + 4] = color.y;
                Draw::vertexArray[index + 5] = color.z;

                index += 6;
            }
        }

        glBindBuffer(GL_ARRAY_BUFFER, Draw::vboID);
        glBufferSubData(GL_ARRAY_BUFFER, 0, (GLsizeiptr) ((Draw::lines.size() * 2 * 6) * sizeof(float)),
                        Draw::vertexArray);
        glBindVertexArray(Draw::vaoID);

        //Shader
        Draw::shader.use();
        Draw::shader.uploadUniformMat4("uViewProjection",
                                       Napicu::Window::current_scene->getCamera()->getViewProjectionMatrix());

        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);

        glDrawArrays(GL_LINES, 0, Draw::lines.size() * 6 * 2);

        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);
        glBindVertexArray(0);

        Draw::shader.detach();
    }

    void Draw::addLine(const glm::vec2 from, const glm::vec2 to) {
        Draw::addLine(from, to, glm::vec3(1, 1, 1), 1);
    }

    void Draw::addLine(const glm::vec2 from, const glm::vec2 to, const glm::vec3 color) {
        Draw::addLine(from, to, color, 1);
    }

    void Draw::addLine(const glm::vec2 from, const glm::vec2 to, const glm::vec3 color, const int lifeTime) {
        if (Draw::lines.size() >= Draw::max_lines) return;
        Draw::lines.push_back(new Napicu::LineVector(from, to, color, lifeTime));
    }

    void Draw::addBox(const glm::vec2 position, const glm::vec2 dimensions, const glm::vec3 color, const int lifeTime) {
        glm::vec2 min = position - (dimensions * 0.5f);
        glm::vec2 max = position + (dimensions * 0.5f);

        std::vector<glm::vec2> vrtcs =  {
                glm::vec2(min.x, min.y), glm::vec2(min.x, max.y),
                glm::vec2(max.x, max.y), glm::vec2(max.x, min.y)
        };

//        if(angle != 0.0f){
//            for(glm::vec2 &vert : vrtcs){
//                vert = glm::rotate(glm::vec3(vert, 0.0f),
//                                   glm::radians(90.0f), glm::vec3(position, 0.0f));
//            }
//        }

        Draw::addLine(vrtcs[0], vrtcs[1], color, lifeTime);
        Draw::addLine(vrtcs[0], vrtcs[3], color, lifeTime);
        Draw::addLine(vrtcs[1], vrtcs[2], color, lifeTime);
        Draw::addLine(vrtcs[2], vrtcs[3], color, lifeTime);
    }


}