#pragma once

#ifndef OPENGL_SPRITERENDER_H
#define OPENGL_SPRITERENDER_H

#include "../Object/Component.h"
#include "../Utils/Console.h"
namespace Napicu{
    class SpriteRender : public Napicu::Component{

    protected:
        glm::vec4* color;


    public:
        glm::vec4* getColor() const {return this->color;}


        SpriteRender() : color(new glm::vec4(0.5f, 0.5f, 0.5f, 0.5f)) {

        }

        SpriteRender(glm::vec4* color) : color(color){

        }

        void start() override{
        }

        void update(double delta_time) override{
        }






    };
}


#endif //OPENGL_SPRITERENDER_H