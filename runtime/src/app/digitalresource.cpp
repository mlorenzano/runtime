#include "digitalresource.h"

DigitalResource::DigitalResource(const std::string n, const bool d_s)
{
    name = n;
    state = default_state = d_s;
}
