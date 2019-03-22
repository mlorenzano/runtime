#pragma once

#include "Resource.hpp"

class EncoderResource : public Resource
{
public:
    EncoderResource() = default;
    explicit EncoderResource(std::string &&n, float d_v);
    EncoderResource(const EncoderResource &) = default;
    EncoderResource(EncoderResource &&) = default;
    ~EncoderResource() = default;

    EncoderResource &operator=(const EncoderResource &) = default;
    EncoderResource &operator=(EncoderResource &&) = default;

    float get_value() const noexcept;
    void set_state(float v);

    float get_default_value() const noexcept;
    void set_defautl_state(float d_v);

private:
    float value{0};
    float default_value{0};
};
