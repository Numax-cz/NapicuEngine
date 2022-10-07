#pragma once

#ifndef OPENGL_SPRITERENDER_H
#define OPENGL_SPRITERENDER_H

#include "../Object/Component.h"
#include "../Utils/Console.h"
namespace Napicu{
    class SpriteRender : public Napicu::Component{

    protected:
        glm::vec3* color;


    public:
        glm::vec3* getColor() const {return this->color;}


        SpriteRender() : color(new glm::vec3(0, 0, 0)){

        }

        SpriteRender(glm::vec3* color) : color(color){

        }

        void start() override{
        }

        void update(double delta_time) override{
        }






    };
}


#endif //OPENGL_SPRITERENDER_H