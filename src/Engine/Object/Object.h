#pragma once

#include <iostream>

#include <list>
#include <glm/vec2.hpp>
#include "Component.h"
#include "../Utils/Console.h"

namespace Napicu{

    struct ObjectTransform{
        glm::vec2 position;
        glm::vec2 scale;

        ObjectTransform(){
            this->position = *new glm::vec2(0, 0);
            this->scale = *new glm::vec2(1, 1);
        }

        ObjectTransform(glm::vec2 position){
            this->position = position;
            this->scale = *new glm::vec2(1, 1);
        }

        ObjectTransform(glm::vec2 position, glm::vec2 scale){
            this->position = position;
            this->scale = scale;
        }
    };

    class Object {

    private:
        std::string name;
        std::list<Component*> components;


    public:
        Napicu::ObjectTransform transform;
        Object(const std::string& name);
        Object(const std::string& name, Napicu::ObjectTransform transform);
        template<typename T, typename std::enable_if<std::is_base_of<Component, T>::value>::type* = nullptr> T* getComponent(T componentClass);
        template<typename T, typename std::enable_if<std::is_base_of<Component, T>::value>::type* = nullptr> void removeComponent(T& componentClass);
        void addComponent(Component& componentClass);
        void update(double delta_time);
        void start();
    };

}



