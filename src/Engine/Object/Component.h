
#pragma once




#include "Object.h"

namespace Napicu{
    class Object;

    class Component{


    private:

    public:
        Napicu::Object* object = nullptr;
        virtual void update(double delta_time) {};

        virtual void start()  {};
    };


}
