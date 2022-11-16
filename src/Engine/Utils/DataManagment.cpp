#include <fstream>
#include "DataManagment.h"

namespace Napicu {


    void DataManagment::loadData() {
        nlohmann::json j;
        std::ifstream i("data.json");
        if(i){
            i >> j;
            DataManagment::data = &j;
        }
        else {
            std::ofstream o("data.json");
            o.close();
        }
    }

    nlohmann::json* DataManagment::getData() {
        return DataManagment::data;
    }
}