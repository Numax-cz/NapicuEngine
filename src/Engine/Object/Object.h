#pragma once


#include <iostream>

#include <list>
#include <glm/vec2.hpp>
#include "Component.h"
#include "../Utils/Console.h"

namespace Napicu {
    class Component;

    struct ObjectTransform {
        glm::vec2 position;
        glm::vec2 scale;
        int zIndex;

        ObjectTransform(): position(*new glm::vec2(1, 1)), scale(*new glm::vec2(1, 1)), zIndex(0) { }

        ObjectTransform(glm::vec2 position): position(position), scale(*new glm::vec2(1, 1)) { }

        ObjectTransform(glm::vec2 position, glm::vec2 scale, int zIndex): position(position), scale(scale), zIndex(zIndex) { }
    };

    class Object {

    private:
        std::list<Component *> components;
        std::string name;


    public:
        Napicu::ObjectTransform transform;

        Object(const std::string &name);

        Object(const std::string &name, Napicu::ObjectTransform transform);

        template<typename T, typename  = typename std::enable_if<std::is_base_of<Napicu::Component, T>::value>::type *>
        T *getComponent(T *componentClass) {
            for (Napicu::Component *c: this->components) {
                if (dynamic_cast<const Napicu::Component *>(&(*c)) != nullptr) {
                    return dynamic_cast<T *>(&(*c));
                }
            }
            return nullptr;
        }

        template<typename T, typename std::enable_if<std::is_base_of<Component, T>::value>::type * = nullptr>
        void removeComponent(T &componentClass) {
            for (Napicu::Component *const i: this->components) {
                if (i == componentClass) {
                    this->components.remove(i);
                    return;
                }
            }
        }

        void addComponent(Component *componentClass);

        void update(double delta_time);

        void start();
    };

}



