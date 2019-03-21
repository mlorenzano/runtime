#ifndef RESOURCES_H
#define RESOURCES_H

#include <vector>
#include "digitalresource.h"
#include "analogresource.h"
#include "encoderresource.h"

class Resources
{
public:
    Resources() = default;
    Resources(const std::vector<DigitalResource> d_i,
              const std::vector<DigitalResource> d_o,
              const std::vector<AnalogResource> a_i,
              const std::vector<AnalogResource> a_o,
              const std::vector<EncoderResource> e);
    ~Resources() = default;

private:
    std::vector<DigitalResource> digital_inputs;
    std::vector<DigitalResource> digital_outputs;
    std::vector<AnalogResource> analog_inputs;
    std::vector<AnalogResource> analog_outputs;
    std::vector<EncoderResource> encoders;
};

#endif // RESOURCES_H
