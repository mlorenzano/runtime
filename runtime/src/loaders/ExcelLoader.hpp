#pragma once

#include "ILoader.hpp"

class ExcelLoader : public ILoader
{
public:
    ExcelLoader() = default;
    ExcelLoader(const ExcelLoader &) = default;
    ExcelLoader(ExcelLoader &&) = default;
    ~ExcelLoader() override = default;

    ExcelLoader &operator=(const ExcelLoader &) = default;
    ExcelLoader &operator=(ExcelLoader &&) = default;

    void load(std::string &&filename) const override;
};
