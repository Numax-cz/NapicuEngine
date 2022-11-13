#pragma once


#include <iostream>

#include <list>
#include <glm/vec2.hpp>
#include "../Components/Component.h"
#include "../Utils/Console.h"
#include "Transform.h"

namespace Napicu {
    class Component;

    class Object {

    private:
        inline static int idCounter = 0;
        int id = -1;


    public:
        Napicu::ObjectTransform *transform;
        std::list<Component *> components;
        std::string name;

        Object(std::string name);

        Object(std::string name, Napicu::ObjectTransform *transform);

        template<typename T, typename  = typename std::enable_if<std::is_base_of<Napicu::Component, T>::value>::type *>
        T *getComponent(T *componentClass) {
            for (Napicu::Component *c: this->components) {
                if (static_cast<const Napicu::Component *>(c) != nullptr) {
                    return static_cast<T *>(c);
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

        void imGui();

        void start();

        std::list<Component *> getAllComponents();

        static void init(int maxID);
    };

}



