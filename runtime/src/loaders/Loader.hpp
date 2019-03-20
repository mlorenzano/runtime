#pragma once

#include "ILoader.hpp"

class Loader : public ILoader
{
public:
    Loader() = default;
    Loader(const Loader &) = default;
    Loader(Loader &&) = default;
    ~Loader() override = default;

    Loader &operator=(const Loader &) = default;
    Loader &operator=(Loader &&) = default;

    void load(std::string &&filename) const override;
};
