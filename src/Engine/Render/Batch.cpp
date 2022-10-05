

#include "Batch.h"


namespace Napicu{

    Batch::Batch(int batchSize) : batchSize(batchSize){
        this->shader =  new Napicu::Shader("src/Engine/shaders/default.glsl");
        this->vertexArray = new float[batchSize * 4 * VERTEX_SIZE];

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


        //Set vertex attribute pointers
        glBufferData(GL_ARRAY_BUFFER, sizeof(this->vertexArray), this->vertexArray, GL_STATIC_DRAW); //GL_DYNAMIC_DRAW
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(this->elementArray), this->elementArray, GL_STATIC_DRAW);



        //Set vertex attribute pointers
        glVertexAttribPointer(0, this->POS_SIZE, GL_FLOAT, GL_FALSE, this->VERTEX_SIZE_BYTES, nullptr);
        glEnableVertexAttribArray(0);

        //Set indices attribute pointer (color)
        glVertexAttribPointer(1, this->COLOR_SIZE, GL_FLOAT, GL_FALSE, this->VERTEX_SIZE_BYTES, (void*)(this->COLOR_SIZE * sizeof(float)));
        glEnableVertexAttribArray(1);


        //Set Texcoords attribute pointers
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, this->VERTEX_SIZE_BYTES, (void*)(6 * sizeof(float))); //6
        glEnableVertexAttribArray(2);

        //Unbind all
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }

    int* Batch::generateElementArray() {
        int* elements = new int[6 * this->batchSize];
        for(int i = 0; i < this->batchSize; i++){

        }

        return elements;
    }


}