#include "ExcelLoader.hpp"
#include <xlnt/xlnt.hpp>

void ExcelLoader::load(std::string &&filename) const
{
    xlnt::workbook wb;
    wb.load(filename);
    auto ws = wb.active_sheet();

    std::clog << "Print rows content" << std::endl;
    for (auto row : ws.rows(false))
    {
        for (auto cell : row)
        {
            std::clog << cell.to_string() << std::endl;
        }
    }
    std::clog << "Processing complete" << std::endl;

}
