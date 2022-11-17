
#pragma once


#include "../Object/Object.h"
#include <nlohmann/json.hpp>
#include <nlohmann/adl_serializer.hpp>

namespace Napicu {
    class Object;

    class Component {


    private:
        inline static int idCounter = 0;
        int id = -1;



    public:
        Napicu::Object *object;

        virtual void update(double delta_time) {};

        virtual void start() {};

        virtual void imGui() {};

        virtual nlohmann::json toJson(){
            return nlohmann::json();
        }

        virtual Component fromJson(nlohmann::json json){
            return Component();
        };


        void generateId() {
            if (this->id == -1) this->id = idCounter++;
        }

        int getId() { return this->id; }

    };




}
