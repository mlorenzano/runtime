#include "ILoader.hpp"

bool ILoader::is_tag(const std::string &item) const
{
    return item.find("#") != std::string::npos;
}

void ILoader::update_state(const std::string &item)
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
