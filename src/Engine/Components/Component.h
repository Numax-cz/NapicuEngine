
#pragma once


#include "../Object/Object.h"


namespace Napicu {
    class Object;

    class Component {


    private:
        inline static int idCounter = 0;
        int id = -1;


    public:
        Napicu::Object *object{};

        virtual void update(double delta_time) {};

        virtual void start() {};

        virtual void imGui() {};

        void generateId() {
            if (this->id == -1) this->id = idCounter++;
        }

        int getId() { return this->id; }

    };


}
