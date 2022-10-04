

#ifndef OPENGL_TESTOBJECT_H
#define OPENGL_TESTOBJECT_H

#include "../Component.h"
#include "../Utils/Console.h"

class TestObject : public Napicu::Component{


    void start() override{
        Napicu::Console::Info("Starting");
    }

    void update(double delta_time) override{
        Napicu::Console::Info("Updating");

    }




};


#endif //OPENGL_TESTOBJECT_H
