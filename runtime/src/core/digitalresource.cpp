#include "digitalresource.h"

DigitalResource::DigitalResource(std::string &&n, bool d_v) :
    Resource(std::move(n)),
    value{d_v},
    default_value{d_v}
{}

bool DigitalResource::get_value() const noexcept
{
    return value;
}

void DigitalResource::set_state(bool v)
{
    value = v;
}

bool DigitalResource::get_default_value() const noexcept
{
    return default_value;
}

void DigitalResource::set_defautl_state(bool d_v)
{
    default_value = d_v;
}
