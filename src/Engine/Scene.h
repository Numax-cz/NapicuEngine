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
        Napicu::Render *render = new Napicu::Render();
        Napicu::Object *activeGameObject = nullptr;
        bool levelLoad = false;


    private:
        bool isRunning = false;

    public:
        Scene() {};

        Napicu::Camera camera = *new Napicu::Camera(0.0f, Napicu::Config::CAMERA_PROJECTION_SIZE_X, 0.0f, Napicu::Config::CAMERA_PROJECTION_SIZE_Y);

        virtual void update(double delta_time) {};

        virtual void init() {};

        void load() {
            Napicu::DataManagment::loadData();

            std::list<Napicu::Object> data = Napicu::DataManagment::getObjectsFromData();

            if(!data.empty()){

                printf("xd");
                for(const auto& ob : data){
                    Napicu::Object nObj = *new Napicu::Object(ob);
                    Napicu::Json::

                    this->addObjectToScene(new Napicu::Object(ob));
                }

                this->levelLoad = true;
            }

        }

        void saveSettings(){
            //TODO SAVE data
        }


        void imGuiScene() {
            if (this->activeGameObject != nullptr) {
                ImGui::Begin("Inspector");
                this->activeGameObject->imGui();
                ImGui::End();
            }
            this->imGui();
        }

        virtual void imGui() {}


        void start() {
            for (Object *object: this->sceneObjects) {
                object->start();
                this->render->add(object);
            }

            this->isRunning = true;
        }

        void addObjectToScene(Object *sceneObject) {
            this->sceneObjects.push_back(sceneObject);
            if (this->isRunning) {
                sceneObject->start();
                this->render->add(sceneObject);
            }
        };

        Napicu::Camera getCamera() { return this->camera; }
    };
}


