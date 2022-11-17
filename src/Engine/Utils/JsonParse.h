#pragma once
#include <iostream>
#include <nlohmann/json.hpp>
#include "Console.h"

namespace Napicu{
    class JsonParseException : public nlohmann::detail::json_sax_dom_parser<nlohmann::json>
    {
    public:
        JsonParseException(nlohmann::json& j)
                : nlohmann::detail::json_sax_dom_parser<nlohmann::json>(j, false)
        {}

        bool parse_error(std::size_t position,
                         const std::string& last_token,
                         const nlohmann::json::exception& ex)
        {
            //Napicu::Console::Error("parse error at input byte" + position);
            Napicu::Console::Error("parsing unsuccessful!");
            std::cerr << ex.what() << "\n"
                      << "last read: \"" << last_token << "\""
                      << std::endl;
            return false;
        }
    };
};

