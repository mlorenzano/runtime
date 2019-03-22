#include "analogresource.h"

AnalogResource::AnalogResource(std::string &&n, uint16_t d_v) :
    Resource(std::move(n)),
    value{d_v},
    default_value{d_v}
{}

uint16_t AnalogResource::get_value() const noexcept
{
    return value;
}

void AnalogResource::set_state(uint16_t v)
{
    value = v;
}

uint16_t AnalogResource::get_default_value() const noexcept
{
    return default_value;
}

void AnalogResource::set_defautl_state(uint16_t d_v)
{
    default_value = d_v;
}
