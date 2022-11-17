#include <fstream>
#include <iostream>
#include "DataManagment.h"

namespace Napicu {

    void DataManagment::loadData() {
        nlohmann::json* j = new nlohmann::json();
        std::ifstream i(DataManagment::DATA_FILE_NAME);

        if(i.is_open()){
            Napicu::JsonParseException jsonParseException(*j);
            nlohmann::json::sax_parse(i, &jsonParseException);
        }
        else {
            std::ofstream o(DataManagment::DATA_FILE_NAME);
            //TODO WRITE DEFAULT VALUE
            o.close();
        }
        DataManagment::data = j;
        i.close();
    }

    void DataManagment::saveData() {
        if(DataManagment::data == nullptr) return;
        std::ofstream o(DataManagment::DATA_FILE_NAME);
        if(o.is_open()){
            o << *DataManagment::data;
            o.close();
        }
    }

    nlohmann::json* DataManagment::getData() {
        return DataManagment::data;
    }

    void DataManagment::saveObjectToData(Napicu::Object ob) {
        if(DataManagment::data == nullptr) return;
        (*DataManagment::data)["objects"].push_back(Napicu::Json::objectToJson(ob));
        DataManagment::saveData();
    }

    std::list<Napicu::Object> DataManagment::getObjectsFromData() {
        nlohmann::json j = *DataManagment::getData();
        std::list<Napicu::Object> list = {};

        for (const auto& el : j["objects"].items()) {
            list.push_back(Napicu::Json::jsonToObject(el.value()));
        }

        return list;
    }
}