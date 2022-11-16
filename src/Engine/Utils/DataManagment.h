#pragma once
#include <nlohmann/json.hpp>

namespace Napicu {

    class DataManagment {

    private:
        inline static nlohmann::json* data = nullptr;

    public:

        static void loadData();

        static nlohmann::json* getData();

    };

}
