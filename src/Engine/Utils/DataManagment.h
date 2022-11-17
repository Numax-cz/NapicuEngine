#pragma once
#include <nlohmann/json.hpp>
#include "Json.h"
#include "JsonParse.h"
#include "../Object/Object.h"


namespace Napicu {

    class DataManagment {

    private:
        static inline const std::string DATA_FILE_NAME = "data.json";

        inline static nlohmann::json* data = nullptr;

        static void saveData();


    public:
        static void saveObjectToData(Napicu::Object ob);

        static void loadData();

        static nlohmann::json* getData();

    };

}
