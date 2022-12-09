#pragma once

#include <iostream>
#include "Camera.h"
#include "Object/Object.h"
#include "Render/Render.h"
#include "Utils/Config.h"
#include <imgui.h>
#include "Utils/Json.h"
#include "Utils/DataManagment.h"

namespace Napicu {


    class Scene {
    protected:
        std::list<Napicu::Object *> sceneObjects = {};
        Napicu::Render *sRender = new Napicu::Render();
        bool levelLoad = false;


    private:
        bool isRunning = false;

    public:
        Scene() {};

        Napicu::Camera* camera = new Napicu::Camera(0.0f, Napicu::Config::CAMERA_PROJECTION_SIZE_X, 0.0f, Napicu::Config::CAMERA_PROJECTION_SIZE_Y);

        virtual void update(double delta_time) {};
        virtual void render() {};
        virtual void imGui() {}


        virtual void init() {};

        void load() {
            Napicu::DataManagment::loadData();

            std::list<Napicu::Object*> data = Napicu::DataManagment::generateObjectsFromData();

            if(!data.empty()){
                for(Napicu::Object* ob : data){

                    this->addObjectToScene(ob);
                }

                this->levelLoad = true;
            }

        }

        void saveSettings(){
            Napicu::DataManagment::clearObjectData();
            for(const Napicu::Object *ob : this->sceneObjects){
                Napicu::DataManagment::saveObjectToData(*ob);
            }
        }

        void start() {
            for (Object *object: this->sceneObjects) {
                object->start();
                this->sRender->add(object);
            }

            this->isRunning = true;
        }

        void addObjectToScene(Object *sceneObject) {
            this->sceneObjects.push_back(sceneObject);
            if (this->isRunning) {
                sceneObject->start();
                this->sRender->add(sceneObject);
            }
        };

        Napicu::Object* getSceneObject(int objectId){
            std::vector<Napicu::Object*> sub;
            std::copy_if(this->sceneObjects.begin(), this->sceneObjects.end(), std::back_inserter(sub),[objectId](Napicu::Object* ob) {
                return ob->getId() == objectId;
            });
            if(sub.empty()) return nullptr;
            return sub[0];
        }

        Napicu::Camera* getCamera() { return this->camera; }
    };
}


