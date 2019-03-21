#ifndef DIGITALOUTPUT_H
#define DIGITALOUTPUT_H

#include <string>

class DigitalResource
{
public:
    DigitalResource() = default;
    DigitalResource(const std::string n, const bool d_s);
    ~DigitalResource() = default;

    inline std::string get_name() { return name; }
    inline void set_name(std::string n) { name = n; }

    inline bool get_state() { return state; }
    inline void set_state(bool s) { state = s; }

    inline bool get_default_state() { return default_state; }
    inline void set_defautl_state(bool d_s) { default_state = d_s; }

private:
    std::string name;
    bool state;
    bool default_state;
};

#endif // DIGITALOUTPUT_H
