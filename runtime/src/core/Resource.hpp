#pragma once

#include <string>

class Resource
{
public:
    Resource() = default;
    explicit Resource(std::string &&name);
    Resource(const Resource &) = default;
    Resource(Resource &&) = default;
    ~Resource() = default;

    Resource &operator=(const Resource &) = default;
    Resource &operator=(Resource &&) = default;

    std::string label;

};
