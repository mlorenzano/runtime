#pragma once

#include "ILoader.hpp"

class CsvLoader : public ILoader
{
public:
    CsvLoader() = default;
    CsvLoader(const CsvLoader &) = default;
    CsvLoader(CsvLoader &&) = default;
    ~CsvLoader() override = default;

    CsvLoader &operator=(const CsvLoader &) = default;
    CsvLoader &operator=(CsvLoader &&) = default;

    void load(std::string &&filename) const override;
};
