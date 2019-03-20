#include "Loader.hpp"

#include "CsvLoader.hpp"
#include "ExcelLoader.hpp"

#include <stdexcept>

void Loader::load(std::string &&filename) const
{
    if (filename.find(".csv") != std::string::npos) {
        CsvLoader().load(std::move(filename));
    } else if (filename.find(".xls") != std::string::npos ||
               filename.find(".xlsx") != std::string::npos) {
        ExcelLoader().load(std::move(filename));
    } else {
        throw std::logic_error("format not supported");
    }
}
