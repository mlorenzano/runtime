#pragma once

#include "analogresource.h"
#include "digitalresource.h"
#include "encoderresource.h"

#include <vector>

class Resources
{
public:
    static Resources &get_instance();

    Resources(const Resources &) = delete;
    Resources(Resources &&) = delete;
    ~Resources() = default;

    Resources &operator=(const Resources &) = delete;
    Resources &operator=(Resources &&) = delete;

    std::vector<DigitalResource> digital_inputs;
    std::vector<DigitalResource> digital_outputs;
    std::vector<AnalogResource> analog_inputs;
    std::vector<AnalogResource> analog_outputs;
    std::vector<EncoderResource> encoders;

    void clear();

private:
    Resources() = default;
};
