#ifndef DIGITALINPUTSMODEL_HPP
#define DIGITALINPUTSMODEL_HPP

#include <QAbstractListModel>
#include "digitalresource.h"

class DigitalInputsModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit DigitalInputsModel(QObject *parent = nullptr);

    enum Roles {
        Name = Qt::UserRole + 1,
        Value,
    };

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;
};

#endif // DIGITALINPUTSMODEL_HPP
