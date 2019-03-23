#include "ExcelLoader.hpp"
#include <xlnt/xlnt.hpp>
#include <resources.h>

void ExcelLoader::load(std::string &&filename)
{
    xlnt::workbook wb;
    wb.load(filename);
    auto ws = wb.active_sheet();
    decltype (auto) r = Resources::get_instance();

    //Reset all old resources
    r.clear();

    for (size_t i = 0; i < ws.rows(false).length(); i++) {
        xlnt::cell_vector row = ws.rows(false).vector(i);
        std::string item = row.front().to_string();
        std::string value = row.back().to_string();

        if (item.empty()) {
            continue;
        }

        if (value.empty()) {
            value = "0";
        }

        //Setting cell type
        if (is_tag(item)) {
            update_state(item);
            continue;
        }

        //Set resources vectors
        switch (state) {
        case Type::Uknown:
            throw std::logic_error("why I'm here?");
            break;

        case Type::DigIn:
            r.digital_inputs.emplace_back(std::move(item),
                                           std::stoi(value));
            break;

        case Type::DigOut:
            r.digital_outputs.emplace_back(std::move(item),
                                           std::stoi(value));
            break;

        case Type::AnalogIn:
            r.analog_inputs.emplace_back(std::move(item),
                                           std::stoi(value));
            break;

        case Type::AnalogOut:
            r.analog_outputs.emplace_back(std::move(item),
                                           std::stoi(value));
            break;

        case Type::Encoders:
            r.encoders.emplace_back(std::move(item),
                                           std::stoi(value));
            break;
        }
    }

    std::cerr << r.digital_inputs.size() << " digital inputs" << std::endl
              << r.digital_outputs.size() << " digital outputs" << std::endl
              << r.analog_inputs.size() << " analog inputs" << std::endl
              << r.analog_outputs.size() << " analog outputs" << std::endl
              << r.encoders.size() << " encoders";
}
