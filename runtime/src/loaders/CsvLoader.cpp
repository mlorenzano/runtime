#include "CsvLoader.hpp"

#include <resources.h>

#include <fstream>
#include <iostream>
#include <sstream>

void CsvLoader::load(std::string &&filename)
{
    auto rows = split(read(std::move(filename)), "\r\n");
    decltype (auto) r = Resources::get_instance();
    for (size_t i = 0; i < rows.size(); ++i) {
        auto item = rows.at(i);

        if (item.empty() || item.size() <= 1) {
            continue;
        }

        if (is_tag(item)) {
            update_state(item);
            continue;
        }

        auto tokens = split(item, ";");
        switch (state) {
            case Type::Uknown:
                throw std::logic_error("why I'm here?");

            case Type::DigIn:
                r.digital_inputs.emplace_back(std::move(tokens.front()),
                                              std::stoi(tokens.back()));
                break;

            case Type::DigOut:
                r.digital_outputs.emplace_back(std::move(tokens.front()),
                                               false);
                break;

            case Type::AnalogIn:
                r.analog_inputs.emplace_back(std::move(tokens.front()), 0);
                break;

            case Type::AnalogOut:
                r.analog_outputs.emplace_back(std::move(tokens.front()), 0);
                break;

            case Type::Encoders:
                r.encoders.emplace_back(std::move(tokens.front()), 0.0);
                break;
        }
    }

    std::cerr << r.digital_inputs.size() << " digital inputs" << std::endl
              << r.digital_outputs.size() << " digital outputs" << std::endl
              << r.analog_inputs.size() << " analog inputs" << std::endl
              << r.analog_outputs.size() << " analog outputs" << std::endl
              << r.encoders.size() << " encoders";
}

std::string CsvLoader::read(std::string &&filename) const
{
    std::ifstream ifs;
    ifs.open(filename);
    std::stringstream ss;
    ss << ifs.rdbuf();
    return ss.str();
}

std::vector<std::string> CsvLoader::split(std::string content,
                                          const std::string &delimiter) const
{
    std::vector<std::string> lines;
    size_t pos = 0;
    std::string token;
    do {
        pos = content.find(delimiter);
        token = content.substr(0, pos);
        lines.emplace_back(token);
        content.erase(0, pos + delimiter.length());
    } while (pos != std::string::npos);

    return lines;
}

bool CsvLoader::is_tag(const std::string &item) const
{
    return item.at(1) == '#';
}

void CsvLoader::update_state(const std::string &item)
{
    if (item.find("DIGITAL") != std::string::npos &&
        item.find("INPUTS") != std::string::npos) {
        state = Type::DigIn;
    } else if (item.find("DIGITAL") != std::string::npos &&
               item.find("OUTPUTS") != std::string::npos) {
        state = Type::DigOut;
    } else if (item.find("ANALOG") != std::string::npos &&
               item.find("INPUTS") != std::string::npos) {
        state = Type::AnalogIn;
    } else if (item.find("ANALOG") != std::string::npos &&
               item.find("OUTPUTS") != std::string::npos) {
        state = Type::AnalogOut;
    } else if (item.find("ENCODERS") != std::string::npos) {
        state = Type::Encoders;
    } else {
        throw std::logic_error("tag not recognized");
    }
}
