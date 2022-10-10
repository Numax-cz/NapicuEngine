#include "Batch.h"
#include "../window.h"
#include "Texture.h"

namespace Napicu{

    Batch::Batch(int batchSize) : batchSize(batchSize){
        this->shader =  new Napicu::Shader("src/Engine/shaders/default.glsl");
//        this->sprites = new Napicu::SpriteRender();

//        this->vertexArray = {
//                        0.5f,0.5f, 0.0f,    1.0f, 0.0f, 0.0f,   1.0f, 1.0f,
//                        0.5f,-0.5f, 0.0f,     1.0f, 1.0f, 0.0f,   1.0f, 0.0f,
//                        -0.5f, -0.5f, 0.0f,    1.0f, 0.0f, 1.0f,   0.0f, 0.0f,
//                        -0.5f,0.5f,0.0f,     1.0f, 1.0f, 0.0f,     0.0f, 1.0f
//        };

        this->vertexArray = *new std::vector<float>() = {
                        0.5f,0.5f, 0.0f,    1.0f, 0.0f, 0.0f, 0.0f,   1.0f, 1.0f,
                        0.5f,-0.5f, 0.0f,     1.0f, 1.0f, 0.0f, 1.0f,   1.0f, 0.0f,
                        -0.5f, -0.5f, 0.0f,    1.0f, 0.0f, 1.0f, 1.0f,  0.0f, 0.0f,
                        -0.5f,0.5f,0.0f,     1.0f, 1.0f, 0.0f,  1.0f,   0.0f, 1.0f
        };

        //this->spritesNum = 0;
        this->room = true;
    }

    void Batch::start() {

        //Gen
        glGenBuffers(1, &this->vboID);
        glGenVertexArrays(1, &this->vaoID);
        glGenBuffers(1, &this->eboID);

        //Bind
        glBindBuffer(GL_ARRAY_BUFFER, this->vboID);
        glBindVertexArray(this->vaoID);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->eboID);

        std::vector<int> elementArray = this->generateElementArray();


        //Set vertex attribute pointers
        glBufferData(GL_ARRAY_BUFFER, (GLsizeiptr)(this->vertexArray.size() * sizeof(float)), this->vertexArray.data(), GL_STATIC_DRAW);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(this->batchSize * 6) * sizeof(float), elementArray.data(), GL_STATIC_DRAW);

        //Set vertex attribute pointers
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, this->VERTEX_SIZE_BYTES, nullptr);
        glEnableVertexAttribArray(0);

        //Set indices attribute pointer
        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, this->VERTEX_SIZE_BYTES, (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        //Set Texcoords attribute pointers
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, this->VERTEX_SIZE_BYTES, (void*)(6 * sizeof(float))); //6
        glEnableVertexAttribArray(2);

        //Unbind all
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }

    void Batch::render() {
        glBindVertexArray(this->vaoID);
        if(this->eboID > 0) glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->eboID);

        //Shader
        this->shader->use();
        this->shader->uploadUniformMat4("uProjection", Napicu::Window::current_scene->getCamera().getViewProjectionMatrix());


        glBindVertexArray(this->vaoID);
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);

        //glDrawElements(GL_TRIANGLES, this->getSpritesSizeIndex() * 6, GL_UNSIGNED_INT, (void*)nullptr);
        glDrawElements(GL_TRIANGLES, (this->getSpritesSizeIndex() + 1) * 6 , GL_UNSIGNED_INT, (void*)nullptr);

        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);
        glBindVertexArray(0);
    }

    void Batch::addSprite(Napicu::SpriteRender* obj) {

        //this->sprites[this->spritesNum] = obj;
        this->sprites.push_back(obj);


        this->loadVertexP(this->getSpritesSizeIndex());
//        this->spritesNum++;

        if(this->getSpritesSizeIndex() >= this->batchSize){
            this->room = false;
        }
    }

    void Batch::loadVertexP(int index) {
        Napicu::SpriteRender* spriteRender = this->sprites[index];
        int offSet = this->VERTEX_SIZE * index * 4;

        glm::vec4* color = spriteRender->getColor();

        float xA = 1.0f;
        float yA = 1.0f;



        for (int i = 0; i < 4; ++i) {
            if(i == 1){
                yA = 0.0f;
            }else if (i == 2){
                xA = 0.0f;
            }else if (i == 3){
                yA = 1.0f;
            }


            //Position
            this->vertexArray.at(offSet) = spriteRender->object->transform->position.x + (xA *  spriteRender->object->transform->scale.x);
            this->vertexArray.at(offSet + 1) = spriteRender->object->transform->position.y + (yA *  spriteRender->object->transform->scale.y);

            //Color
            this->vertexArray.at(offSet + 2) = color->x; //R
            this->vertexArray.at(offSet + 3) = color->y; //G
            this->vertexArray.at(offSet + 4) = color->z; //B
            this->vertexArray.at(offSet + 5) = color->w; //A


            offSet += this->VERTEX_SIZE;
        }
    }

    std::vector<int> Batch::generateElementArray() {
        std::vector<int> elements;
        elements.reserve(6 * this->batchSize);

        for(int i = 0; i < this->batchSize; i++){
           this->loadElementArray(elements, i);
        }

        return elements;
    }

    void Batch::loadElementArray(std::vector<int>& elements, int index) {
        int offSetArrayIndex = 6 * index;
        int offSet = 4 * index;

        elements[offSetArrayIndex] = offSet + 3;
        elements[offSetArrayIndex + 1] = offSet + 2;
        elements[offSetArrayIndex + 2] = offSet;

        elements[offSetArrayIndex + 3] = offSet ;
        elements[offSetArrayIndex + 4] = offSet + 2;
        elements[offSetArrayIndex + 5] = offSet + 1;
    }
}