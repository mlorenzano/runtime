#include "encoderresource.h"

EncoderResource::EncoderResource(std::string &&n, float d_v) :
    Resource(std::move(n)),
    value{d_v},
    default_value{d_v}
{}

float EncoderResource::get_value() const noexcept
{
    return value;
}

void EncoderResource::set_state(float v)
{
    value = v;
}

float EncoderResource::get_default_value() const noexcept
{
    return default_value;
}

void EncoderResource::set_defautl_state(float d_v)
{
    default_value = d_v;
}
