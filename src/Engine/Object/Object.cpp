#include "Object.h"

namespace Napicu {

    Object::Object(const std::string &name) : name(name), transform(new Napicu::ObjectTransform()) {

    }

    Object::Object(const std::string &name, Napicu::ObjectTransform *transform) : name(name), transform(transform) {

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