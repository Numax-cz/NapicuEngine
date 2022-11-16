#include <fstream>
#include <iostream>
#include "DataManagment.h"

namespace Napicu {

    void DataManagment::loadData() {
        nlohmann::json* j = new nlohmann::json();
        std::ifstream i(DataManagment::DATA_FILE_NAME);
        if(i){
            i >> *j;
            DataManagment::data = j;
        }
        else {
            std::ofstream o(DataManagment::DATA_FILE_NAME);
            o.close();
        }
    }

    nlohmann::json* DataManagment::getData() {
        return DataManagment::data;
    }
}