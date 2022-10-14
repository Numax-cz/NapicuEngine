#pragma once


#include <iostream>
#include <list>
#include "Shader.h"
#include "../Components/SpriteRender.h"

namespace Napicu{
    class Batch {
    protected:

    private:
        int batchSize;

        Napicu::Shader* shader;
        float* vertexArray{};




//        int elementArray[6] = {
//                0,1,3,
//                1,2,3
//        };


        std::vector<Napicu::SpriteRender*> sprites = *new std::vector<Napicu::SpriteRender*>();

        int vertexID, fragmentID, shaderProgram, spritesNum;
        GLuint vaoID, vboID, eboID;

        bool room;

        const float POS_SIZE = 2;
        const float POS_OFFSET = 0;

        const int VERTEX_SIZE = 6;
        const int VERTEX_SIZE_BYTES = VERTEX_SIZE * sizeof(float);

        const int COLOR_SIZE = 4;

        void loadElementArray(int*  elements, int index);
        int* generateElementArray();

    public:
        Batch(int batchSize);
        ~Batch(){
           delete this->vertexArray;
        }
        void start();
        void render();
        void addSprite(Napicu::SpriteRender* obj);
        void loadVertexP(int index);

        bool const hasRoom() const {return this->room;}

//        int const getSpritesSizeIndex() const {
//            if(this->sprites.size() - 1 > 0 ) return this->sprites.size() - 1;
//            return 0;
//        }



    };

}

