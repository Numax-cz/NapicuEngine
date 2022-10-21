#pragma once


#include <iostream>
#include <list>
#include "Shader.h"
#include "../Components/SpriteRender.h"
#include "Texture.h"

namespace Napicu {
    class Batch {
    protected:

    private:
        int batchSize, zIndex;

        Napicu::Shader *shader;
        std::vector<Napicu::Texture*> textures;

        float *vertexArray{};
        int *elementArray{};

        std::vector<Napicu::SpriteRender *> sprites = *new std::vector<Napicu::SpriteRender *>();
        std::vector<int> texturesSlots = {0, 1, 2, 3, 4, 5, 6, 7};

        int vertexID, fragmentID, shaderProgram, spritesNum;
        GLuint vaoID, vboID, eboID;

        bool room;

        const int VERTEX_SIZE = 9;
        const int VERTEX_SIZE_BYTES = VERTEX_SIZE * sizeof(float);


        void loadElementArray(int index);

        void generateElementArray();

    public:
        Batch(int batchSize, int zIndex);

        ~Batch() {
            delete this->vertexArray;
        }

        void start();

        void render();

        void addSprite(Napicu::SpriteRender *obj);

        void loadVertexP(int index);

        bool const hasRoom() const { return this->room; }

        int const getZIndex() const { return this->zIndex; }


//        int const getSpritesSizeIndex() const {
//            if(this->sprites.size() - 1 > 0 ) return this->sprites.size() - 1;
//            return 0;
//        }





    };

}

