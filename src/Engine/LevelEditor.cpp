

#include "LevelEditor.h"

namespace Napicu {



    void LevelEditor::init() {

        //Gen
        glGenBuffers(1, &this->vboID);
        glGenVertexArrays(1, &this->vaoID);
        glGenBuffers(1, &this->eboID);


        //Bind
        glBindBuffer(GL_ARRAY_BUFFER, this->vboID);
        glBindVertexArray(this->vaoID);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->eboID);


        //Set vertex attribute pointers
        glBufferData(GL_ARRAY_BUFFER, sizeof(this->vertexArray), this->vertexArray, GL_STATIC_DRAW);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(this->elementArray), this->elementArray, GL_STATIC_DRAW);


        //Set vertex attribute pointers
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), nullptr);
        glEnableVertexAttribArray(0);

        //Set indices attribute pointer
        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(4 * sizeof(float)));
        glEnableVertexAttribArray(1);


        //Set Texcoords attribute pointers
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(2 * sizeof(float))); //6
        glEnableVertexAttribArray(2);

        //Unbind all
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        glBindVertexArray(0);

        this->shader->compile();
    }



    void LevelEditor::update(double delta_time) {


        this->shader->use();

//        this->shader->uploadTexture("texSampler");
//        this->texture->Bind();



        this->shader->uploadUniformMat4("uProjection", this->camera.GetViewProjectionMatrix());


        glBindVertexArray(this->vaoID);
        if(this->eboID > 0) glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->eboID);

        glBindVertexArray(this->vaoID);
        glDrawElements(GL_TRIANGLES, sizeof (this->elementArray), GL_UNSIGNED_INT, (void*)nullptr);
        glBindVertexArray(0);
    }




}
