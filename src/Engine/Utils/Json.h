#pragma once
#include <nlohmann/json.hpp>
#include <nlohmann/adl_serializer.hpp>
#include "../Components/Component.h"
#include "../Components/Rigid.h"
#include "../Components/SpriteRender.h"

namespace Napicu{

    class Json{

    public:
        static nlohmann::json objectToJson(Napicu::Component* ob);

        static nlohmann::json objectToJson(Napicu::Object ob);

        static nlohmann::json objectToJson(Napicu::ObjectTransform ob);

        static Napicu::Object jsonToObject(nlohmann::json json);
    };




}