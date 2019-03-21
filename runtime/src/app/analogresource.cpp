#include "analogresource.h"

AnalogResource::AnalogResource(const std::string n, const unsigned short d_v)
{
    name = n;
    value = default_value = d_v;
}
