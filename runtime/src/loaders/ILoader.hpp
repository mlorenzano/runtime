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

    virtual void load(std::string &&filename) const = 0;
};
