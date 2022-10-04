#pragma once
#ifndef OPENGL_OBJECT_H
#define OPENGL_OBJECT_H
#include <iostream>
#include <list>
#include <glm/vec2.hpp>
#include "Component.h"
#include "../Utils/Console.h"

namespace Napicu{

    struct ObjectTransform{
        glm::vec2 position;
        glm::vec2 scale;
    };

    class Object {

    private:
        std::string name;
        std::list<Component*> components;


    public:
        Object(const std::string& name);
        template<typename T, typename std::enable_if<std::is_base_of<Component, T>::value>::type* = nullptr> T getComponent(T componentClass);
        template<typename T, typename std::enable_if<std::is_base_of<Component, T>::value>::type* = nullptr> void removeComponent(T& componentClass);
        void addComponent(Component& componentClass);
        void update(double delta_time);
        void start();
    };

}



#endif //OPENGL_OBJECT_H
