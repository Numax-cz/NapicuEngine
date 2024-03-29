#include <fstream>
#include "Json.h"
#include "Console.h"
#include "Assets.h"

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

    Napicu::Object* Json::jsonToObjectPtr(nlohmann::json json) {
        std::string name = json["name"];
        glm::vec2 position = glm::vec2(json["transform"]["position"]["x"], json["transform"]["position"]["y"]);
        glm::vec2 scale = glm::vec2(json["transform"]["scale"]["x"], json["transform"]["scale"]["y"]);
        int zIndex = json["transform"]["zIndex"];

        Napicu::Object *obj =  new Napicu::Object(name, Napicu::ObjectTransform(position, scale, zIndex));
        Napicu::SpriteRender *render = new Napicu::SpriteRender();

        for(const auto &j : json["components"].items()){
            const auto val = j.value();
            if(val["name"].get<std::string>() == "SpriteRender"){
                if(val.contains("sprite")){
                    std::string pth = val["sprite"]["texture"]["path"];
                    render->setSprite(new Napicu::Sprite(*Napicu::Assets::getTexture(pth)));
                    obj->addComponent(render);
                }
                else if(val.contains("color")){
                    float r = val["color"]["x"];
                    float g = val["color"]["y"];
                    float b = val["color"]["z"];
                    float a = val["color"]["w"];
                    obj->addComponent(new Napicu::SpriteRender(glm::vec4(r, g, b, a)));
                }
            }
        }

        return obj;
    }
}