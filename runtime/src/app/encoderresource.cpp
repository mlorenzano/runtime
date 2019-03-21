#include "encoderresource.h"

EncoderResource::EncoderResource(const std::string n, const float d_v)
{
    name = n;
    value = default_value = d_v;
}
