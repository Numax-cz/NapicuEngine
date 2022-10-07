#pragma once


#ifndef OPENGL_SCENE_H
#define OPENGL_SCENE_H
#include <iostream>
#include "Camera.h"
#include "Object/Object.h"
#include "Render/Render.h"

namespace Napicu{


    class Scene {
    protected:
        std::list<Object> sceneObjects;
        Napicu::Render* render;


    private:
        bool isRunning = false;

    public:
        Scene() {};

        Napicu::Camera camera = *new Napicu::Camera(-1.0f, 1.0f, -1.0f, 1.0f);

        virtual void update(double delta_time) {};

        virtual void init() {};


        void start(){
            for(Object& object : this->sceneObjects){
                object.start();
               this->render->add(&object);
            }

            this->isRunning = true;
        }

        void addObjectToScene(Object& sceneObject) {
            this->sceneObjects.push_back(sceneObject);
            if(this->isRunning) {
                sceneObject.start();
                this->render->add(&sceneObject);
            }
        };

        const Napicu::Camera getCamera() const {return this->camera;}
    };
}


#endif //OPENGL_SCENE_H
