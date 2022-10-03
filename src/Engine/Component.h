

#ifndef OPENGL_COMPONENT_H
#define OPENGL_COMPONENT_H


#include "Object.h"

namespace Napicu{
    class Object;

    class Component{


    private:

    public:
        Napicu::Object* object = nullptr;

        virtual void update(float delta_time) {};

    };


}

#endif //OPENGL_COMPONENT_H
