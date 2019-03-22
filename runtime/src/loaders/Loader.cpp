#include "Loader.hpp"

#include "CsvLoader.hpp"
#include "ExcelLoader.hpp"

#include <stdexcept>

void Loader::load(std::string &&filename)
{
    if (filename.find(".csv") != std::string::npos) {
        CsvLoader().load(std::move(filename));
    } else if (filename.find(".xlsx") != std::string::npos) {
        ExcelLoader().load(std::move(filename));
    } else {
        throw std::logic_error("format not supported");
    }
}
