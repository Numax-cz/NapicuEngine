#pragma once
#include "Component.h"
#include "../Object/Object.h"

namespace Napicu{

class MouseEventControls : public Napicu::Component{
    private:

    public:
        Napicu::Object* holdingObject = nullptr;

        void pickUpObject(Napicu::Object *object);

        void drop();

        void update(double delta_time) override;



    };
}