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
    enum class Type { Uknown, DigIn, DigOut, AnalogIn, AnalogOut, Encoders };
    Type state{Type::Uknown};

    std::string read(std::string &&filename) const;
    std::vector<std::string> split(std::string content,
                                   const std::string &delimiter) const;
    bool is_tag(const std::string &item) const;
    void update_state(const std::string &item);
};
