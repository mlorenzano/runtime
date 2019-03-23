#pragma once

#include <string>

class ILoader
{
public:
    ILoader() = default;
    ILoader(const ILoader &) = default;
    ILoader(ILoader &&) = default;
    virtual ~ILoader() = default;

    ILoader &operator=(const ILoader &) = default;
    ILoader &operator=(ILoader &&) = default;

    virtual void load(std::string &&filename) = 0;

protected:
    enum class Type { Uknown, DigIn, DigOut, AnalogIn, AnalogOut, Encoders };
    Type state{Type::Uknown};

    bool is_tag(const std::string &item) const;
    void update_state(const std::string &item);
};
