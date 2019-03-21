#include "resources.h"

Resources::Resources(const std::vector<DigitalResource> d_i,
                     const std::vector<DigitalResource> d_o,
                     const std::vector<AnalogResource> a_i,
                     const std::vector<AnalogResource> a_o,
                     const std::vector<EncoderResource> e)
{
    digital_inputs = d_i;
    digital_outputs = d_o;
    analog_inputs = a_i;
    analog_outputs = a_o;
    encoders = e;
}
