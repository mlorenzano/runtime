#ifndef ENCODERRESOURCE_H
#define ENCODERRESOURCE_H

#include <string>

class EncoderResource
{
public:
    EncoderResource() = default;
    EncoderResource(const std::string n, const float d_v);
    ~EncoderResource() = default;

    inline std::string get_name() { return name; }
    inline void set_name(std::string n) { name = n; }

    inline float get_value() { return value; }
    inline void set_state(float v) { value = v; }

    inline float get_default_value() { return default_value; }
    inline void set_defautl_state(float d_v) { default_value = d_v; }

private:
    std::string name;
    float value;
    float default_value;
};

#endif // ENCODERRESOURCE_H
