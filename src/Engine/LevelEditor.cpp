

#include "LevelEditor.h"

namespace Napicu {



    void LevelEditor::init() {
        Napicu::Shader* shader = new Napicu::Shader("src/Engine/shaders/default.glsl");

        //glGenVertexArrays(1, &this->vaoID);
        //glBindBuffer(GL_ARRAY_BUFFER, this->vboID);

    }



    void LevelEditor::update(double delta_time) {
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }




}
