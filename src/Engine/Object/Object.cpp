#include "Object.h"

#include <utility>

namespace Napicu {

    Object::Object(std::string name) :
            name(std::move(name)), transform(Napicu::ObjectTransform()), id(this->idCounter++) {

    }

    Object::Object(std::string name, Napicu::ObjectTransform transform) :
            name(std::move(name)), transform(transform), id(this->idCounter++) {

    }

    void Object::addComponent(Napicu::Component *componentClass) {
        this->components.push_back(componentClass);
        componentClass->object = this;
    }

    void Object::update(double delta_time) {
        for (Napicu::Component *i: this->components) {
            i->update(delta_time);
        }
    }

    void Object::start() {
        for (Napicu::Component *i: this->components) {
            i->start();
        }
    }

    void Object::imGui() {
        for (Napicu::Component *i: this->components) {
            i->imGui();
        }
    }

    void Object::init(int maxID) {
        Object::idCounter = maxID;
    }

    std::list<Component *> Object::getAllComponents() {
        return this->components;
    }
}