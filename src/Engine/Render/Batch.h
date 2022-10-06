#pragma once


#ifndef OPENGL_BATCH_H
#define OPENGL_BATCH_H

#include <iostream>
#include <list>
#include "Texture.h"
#include "Shader.h"
#include "../Camera.h"
#include "../window.h"
#include "../Components/SpriteRender.h"

namespace Napicu{
    class Batch {
    protected:

    private:
        int batchSize;

        Napicu::Shader* shader;
        float* vertexArray;

        Napicu::SpriteRender* sprites;

        int vertexID, fragmentID, shaderProgram, spritesNum;
        GLuint vaoID, vboID, eboID;

        const float POS_SIZE = 2;
        const float POS_OFFSET = 0;

        const int VERTEX_SIZE = 6;
        const int VERTEX_SIZE_BYTES = VERTEX_SIZE * sizeof(float);

        const int COLOR_SIZE = 3;

        void loadElementArray(int* elements, int index);
        int* generateElementArray();

    public:
        Batch(int batchSize);
        void start();
        void render();
        void addSprite(Napicu::SpriteRender* obj);
        void loadVertexP(int index);





    };

}


#endif //OPENGL_BATCH_H
