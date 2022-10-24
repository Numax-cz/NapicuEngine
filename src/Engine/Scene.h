#pragma once

#include <iostream>
#include "Camera.h"
#include "Object/Object.h"
#include "Render/Render.h"
#include <imgui.h>

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

        Napicu::Camera camera = *new Napicu::Camera(0.0f, 1920, 0.0f, 1080);

        virtual void update(double delta_time) {};

        virtual void init() {};

        void load(){
            //TODO LOAD CONFIG DATA

            this->levelLoad = true;
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

        const Napicu::Camera getCamera() const { return this->camera; }
    };
}


