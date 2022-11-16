#pragma once
#include <nlohmann/json.hpp>

namespace Napicu {

    class DataManagment {

    private:
        static inline const std::string DATA_FILE_NAME = "data.json";
        inline static nlohmann::json* data = nullptr;

    public:

        static void loadData();

        static nlohmann::json* getData();

    };

}
