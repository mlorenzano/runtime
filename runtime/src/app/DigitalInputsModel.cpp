#include "DigitalInputsModel.hpp"

#include <resources.h>

DigitalInputsModel::DigitalInputsModel(QObject *parent)
    : QAbstractListModel(parent)
{}

int DigitalInputsModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return static_cast<int>(Resources::get_instance().digital_inputs.size());
}

QVariant DigitalInputsModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) {
        return QVariant();
    }

    auto row = static_cast<size_t>(index.row());
    auto input = Resources::get_instance().digital_inputs.at(row);

    if (role == Roles::Name) {
        return QString::fromStdString(input.label);
    }

    if (role == Value) {
        return input.get_value();
    }

    return {};
}

QHash<int, QByteArray> DigitalInputsModel::roleNames() const
{
    return { { Roles::Name, "name" }, { Roles::Value, "value" } };
}

void DigitalInputsModel::refresh()
{
    beginResetModel();
    endResetModel();
}
