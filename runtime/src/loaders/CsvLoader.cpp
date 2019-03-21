#include "CsvLoader.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

void CsvLoader::load(std::string &&filename) const
{
    auto tokens = split(read(std::move(filename)), ";");
    for (auto &item : tokens) {
        std::cerr << item << std::endl;
    }
}

std::string CsvLoader::read(std::string &&filename) const
{
    std::ifstream ifs;
    ifs.open(filename);
    std::stringstream ss;
    ss << ifs.rdbuf();
    return ss.str();
}

std::vector<std::string> CsvLoader::split(std::string content,
                                          const std::string &delimiter) const
{
    std::vector<std::string> lines;
    size_t pos = 0;
    std::string token;
    do {
        pos = content.find(delimiter);
        token = content.substr(0, pos);
        lines.emplace_back(token);
        content.erase(0, pos + delimiter.length());
    } while (pos != std::string::npos);

    return lines;
}
