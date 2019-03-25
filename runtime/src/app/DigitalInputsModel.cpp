#include "DigitalInputsModel.hpp"
#include "resources.h"

DigitalInputsModel::DigitalInputsModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

int DigitalInputsModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    int size = static_cast<int>(Resources::get_instance().digital_inputs.size());
    return size;
}

QVariant DigitalInputsModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    size_t row = static_cast<size_t>(index.row());
    DigitalResource input = Resources::get_instance().digital_inputs.at(row);

    if (role == Roles::Name) {
        QString input_name = QString::fromStdString(input.label);
        return input_name;
    } else if (role == Value) {
        int input_value = input.get_value();
        return input_value;
    }

    return {};
}

QHash<int, QByteArray> DigitalInputsModel::roleNames() const
{
    return { { Roles::Name, "name" }, { Roles::Value, "value" } };
}
