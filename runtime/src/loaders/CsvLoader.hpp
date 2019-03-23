#pragma once

#include "ILoader.hpp"

#include <vector>

class CsvLoader : public ILoader
{
public:
    CsvLoader() = default;
    CsvLoader(const CsvLoader &) = default;
    CsvLoader(CsvLoader &&) = default;
    ~CsvLoader() override = default;

    CsvLoader &operator=(const CsvLoader &) = default;
    CsvLoader &operator=(CsvLoader &&) = default;

    void load(std::string &&filename) override;

private:


    std::string read(std::string &&filename) const;
    std::vector<std::string> split(std::string content,
                                   const std::string &delimiter) const;

};
