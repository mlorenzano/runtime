#include "ExcelLoader.hpp"
#include <xlnt/xlnt.hpp>

enum _CELL_TYPE{
    CELL_TYPE_NO_VALUE       = 0,
    CELL_TYPE_DIGITAL_INPUTS,
    CELL_TYPE_DIGITAL_OUTPUTS,
    CELL_TYPE_ANALOGIC_INPUTS,
    CELL_TYPE_ANALOGIC_OUTPUTS,
    CELL_TYPE_ENCODERS,

    CELL_TYPE_MAX
};

void ExcelLoader::load(std::string &&filename) const
{
    xlnt::workbook wb;
    wb.load(filename);
    auto ws = wb.active_sheet();
    auto cell_type = CELL_TYPE_NO_VALUE;

    std::clog << "Print rows content" << std::endl;
    for (auto row : ws.rows(false)) {
        for (auto cell : row) {
            //Check cell type
            if (cell.to_string().find("DIGITAL INPUTS") != std::string::npos) {
                cell_type = CELL_TYPE_DIGITAL_INPUTS;
                std::clog << cell.to_string() << std::endl;
                break;
            } else if (cell.to_string().find("DIGITAL OUTPUTS") != std::string::npos) {
                cell_type = CELL_TYPE_DIGITAL_OUTPUTS;
                std::clog << cell.to_string() << std::endl;
                break;
            } else if (cell.to_string().find("ANALOGIC INPUTS") != std::string::npos) {
                cell_type = CELL_TYPE_ANALOGIC_INPUTS;
                std::clog << cell.to_string() << std::endl;
                break;

            } else if (cell.to_string().find("ANALOGIC OUTPUTS") != std::string::npos) {
                cell_type = CELL_TYPE_ANALOGIC_OUTPUTS;
                std::clog << cell.to_string() << std::endl;
                break;

            } else if (cell.to_string().find("ENCODERS") != std::string::npos) {
                cell_type = CELL_TYPE_ENCODERS;
                std::clog << cell.to_string() << std::endl;
                break;

            }

            //Set resources vector: cell column index begins with 1
            switch (cell_type) {
            case CELL_TYPE_DIGITAL_INPUTS:
            case CELL_TYPE_DIGITAL_OUTPUTS:
            case CELL_TYPE_ANALOGIC_INPUTS:
            case CELL_TYPE_ANALOGIC_OUTPUTS:
            case CELL_TYPE_ENCODERS:
                //Resource name
                if (cell.column_index() == 1)
                    std::clog << cell.to_string() << ": ";
                //Default vale
                else if (cell.column_index() == 2)
                    std::clog << std::stof(cell.to_string()) << std::endl;
                break;
            default:
                break;
            }
        }
    }
    std::clog << "Processing complete" << std::endl;

}
