#pragma once

#include "Resource.hpp"

class DigitalResource : public Resource
{
public:
    DigitalResource() = default;
    explicit DigitalResource(std::string &&n, bool d_v);
    DigitalResource(const DigitalResource &) = default;
    DigitalResource(DigitalResource &&) = default;
    ~DigitalResource() = default;

    DigitalResource &operator=(const DigitalResource &) = default;
    DigitalResource &operator=(DigitalResource &&) = default;

    bool get_value() const noexcept;
    void set_state(bool v);

    bool get_default_value() const noexcept;
    void set_defautl_state(bool d_v);

private:
    bool value{false};
    bool default_value{false};
};
