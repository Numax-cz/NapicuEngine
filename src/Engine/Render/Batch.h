#pragma once


#ifndef OPENGL_BATCH_H
#define OPENGL_BATCH_H

#include <iostream>
#include <list>
#include "Texture.h"
#include "Shader.h"

namespace Napicu{
    class Batch {
    protected:

    private:
        int batchSize;

        Napicu::Shader* shader;
        float* vertexArray;


        int vertexID, fragmentID, shaderProgram;
        GLuint vaoID, vboID, eboID;

        const float POS_SIZE = 2;
        const float POS_OFFSET = 0;

        const int VERTEX_SIZE = 6;
        const int VERTEX_SIZE_BYTES = VERTEX_SIZE * sizeof(float);

        const int COLOR_SIZE = 3;

    public:
        Batch(int batchSize);
        void start();
        int* generateElementArray();






    };

}


#endif //OPENGL_BATCH_H
