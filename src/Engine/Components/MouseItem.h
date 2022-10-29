#pragma once
#include "Component.h"
#include "../Object/Object.h"

namespace Napicu{

    class MouseItem : public Napicu::Component{
    private:

    public:
        Napicu::Object* holdingObject = nullptr;

        void pickUpObject(Napicu::Object* object);



    };
}