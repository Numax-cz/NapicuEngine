

#ifndef OPENGL_SCENE_H
#define OPENGL_SCENE_H
#include <iostream>
#include "Camera.h"
#include "Object/Object.h"

namespace Napicu{

    class Scene {
    protected:
        std::list<Object> sceneObjects;

    private:
        bool isRunning = false;

    public:
        Scene() {};

        virtual void update(double delta_time) {};

        virtual void init() {};

        Napicu::Camera camera = *new Napicu::Camera(-1.0f, 1.0f, -1.0f, 1.0f);

        void start(){
            for(Object& object : this->sceneObjects){
                object.start();
            }
            this->isRunning = true;
        }

        void addObjectToScene(Object& sceneObject) {
            this->sceneObjects.push_back(sceneObject);
            if(this->isRunning) {
                sceneObject.start();
            }
        };
    };
}


#endif //OPENGL_SCENE_H
