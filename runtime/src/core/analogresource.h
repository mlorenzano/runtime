#pragma once

#include "Resource.hpp"

class AnalogResource : public Resource
{
public:
    AnalogResource() = default;
    explicit AnalogResource(std::string &&n, uint16_t d_v);
    AnalogResource(const AnalogResource &) = default;
    AnalogResource(AnalogResource &&) = default;
    ~AnalogResource() = default;

    AnalogResource &operator=(const AnalogResource &) = default;
    AnalogResource &operator=(AnalogResource &&) = default;

    uint16_t get_value() const noexcept;
    void set_state(uint16_t v);

    uint16_t get_default_value() const noexcept;
    void set_defautl_state(uint16_t d_v);

private:
    uint16_t value{0};
    uint16_t default_value{0};
};
