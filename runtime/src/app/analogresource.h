#ifndef ANALOGRESOURCE_H
#define ANALOGRESOURCE_H

#include <string>

class AnalogResource
{
public:
    AnalogResource() = default;
    AnalogResource(const std::string n, const unsigned short d_v);
    ~AnalogResource() = default;

    inline std::string get_name() { return name; }
    inline void set_name(std::string n) { name = n; }

    inline unsigned short get_value() { return value; }
    inline void set_state(unsigned short v) { value = v; }

    inline unsigned short get_default_value() { return default_value; }
    inline void set_defautl_state(unsigned short d_v) { default_value = d_v; }

private:
    std::string name;
    unsigned short value;
    unsigned short default_value;
};

#endif // ANALOGRESOURCE_H
