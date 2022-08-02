

#ifndef OPENGL_LEVELEDITOR_H
#define OPENGL_LEVELEDITOR_H

#include "Utils/Console.h"
#include "Scene.h"
#include "Render/Shader.h"


namespace Napicu{

    class LevelEditor : public Napicu::Scene{

    private:
        Napicu::Shader* shader = new Napicu::Shader("src/Engine/shaders/default.glsl");
        int vertexID, fragmentID, shaderProgram;
        GLuint vaoID, vboID, eboID;
        float vertexArray[28] = {
                //Position                      //Color
                0.5f,-0.5f, 0.0f,    1.0f, 0.0f, 0.0f, 1.0f,
                -0.5f,0.5f, 0.0f,   0.0f, 1.0f, 0.0f, 1.0f,
                0.5f, 0.5f, 0.0f,   0.0f, 0.0f, 1.0f, 1.0f,
                -0.5f,-0.5f,0.0f,   1.0f, 1.0f, 0.0f, 1.0f,

        };

        int elementArray[6] = {
                2,1,0,
                0,1,3
        };


    public:
        LevelEditor() : Napicu::Scene() {

        };

        void update(double delta_time) override;
        void init() override;

    };
}


#endif //OPENGL_LEVELEDITOR_H
