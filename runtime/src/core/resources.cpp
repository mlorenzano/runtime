#include "resources.h"

Resources &Resources::get_instance()
{
    static Resources r;
    return r;
}

void Resources::clear()
{
    digital_inputs.clear();
    digital_outputs.clear();
    analog_inputs.clear();
    analog_outputs.clear();
    encoders.clear();
}
