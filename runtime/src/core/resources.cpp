#include "resources.h"

Resources &Resources::get_instance()
{
    static Resources r;
    return r;
}
