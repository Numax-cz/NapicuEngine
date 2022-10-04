#include "Object.h"

namespace Napicu {

    Object::Object(const std::string &name):name(name){

    }

    template<typename T, typename std::enable_if<std::is_base_of<Napicu::Component, T>::value>::type *>
    T Object::getComponent(T componentClass) {
        for (Napicu::Component* c : this->components) {
            if(dynamic_cast<const Napicu::Component*>(&(*c)) != nullptr ){
                return c;
            }
        }
        return nullptr;
    }

    template<typename T, typename std::enable_if<std::is_base_of<Napicu::Component, T>::value>::type *>
    void Object::removeComponent(T& componentClass) {
        for(Napicu::Component* const i : this->components){
            if(i == componentClass){
                this->components.remove(i);
                return;
            }
        }
    }

    void Object::addComponent(Napicu::Component& componentClass) {
        this->components.push_back(&componentClass);
        componentClass.object = this;
    }

    void Object::update(double delta_time) {
        for(Napicu::Component* i : this->components){
            (*i).update(delta_time);
        }
    }

    void Object::start() {
        for(Napicu::Component* i : this->components){
            (*i).start();
        }
    }
}