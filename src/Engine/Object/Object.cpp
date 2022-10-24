#include "Object.h"

#include <utility>

namespace Napicu {

    Object::Object(std::string name) : name(std::move(name)), transform(new Napicu::ObjectTransform()) {

    }

    Object::Object(std::string name, Napicu::ObjectTransform *transform) : name(std::move(name)), transform(transform) {

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
            (*i).start();
        }
    }

    void Object::imGui() {
        for (Napicu::Component *i: this->components) {
            i->imGui();
        }
    }


}