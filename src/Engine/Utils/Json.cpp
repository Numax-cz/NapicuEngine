#include <fstream>
#include "Json.h"
#include "Console.h"


namespace Napicu{



    nlohmann::json Json::objectToJson(Napicu::Component* ob) {
        return ob->toJson();
    }

    nlohmann::json Napicu::Json::objectToJson(Napicu::Object ob) {
        nlohmann::json j;

        j["transform"] = objectToJson(ob.transform);
        j["name"] = ob.name;

        for(Napicu::Component *c : ob.components){
            j["components"].push_back(objectToJson(c));
        }

        return j;
    }

    nlohmann::json Napicu::Json::objectToJson( Napicu::ObjectTransform ob) {
        nlohmann::json j;
        j["position"]["x"] = ob.getPosition().x;
        j["position"]["y"] = ob.getPosition().y;

        j["scale"]["x"] = ob.getScale().x;
        j["scale"]["y"] = ob.getScale().y;

        j["zIndex"] = ob.getZIndex();

        return j;
    }

    Napicu::Object Json::jsonToObject(nlohmann::json json) {
        std::string name = json["name"];
        glm::vec2 position = glm::vec2(json["transform"]["position"]["x"], json["transform"]["position"]["y"]);
        glm::vec2 scale = glm::vec2(json["transform"]["scale"]["x"], json["transform"]["scale"]["y"]);
        int zIndex = json["transform"]["zIndex"];
        Napicu::Object obj =  Napicu::Object(name, Napicu::ObjectTransform(position, scale, zIndex));



        return obj;
    }
}