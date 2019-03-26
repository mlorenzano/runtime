#ifndef MENUBAR_HPP
#define MENUBAR_HPP

#include <QObject>

class MenuBar : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString filename READ get_filename NOTIFY filename_changed)

public:
    Q_INVOKABLE void load(QString filename);

public slots:
    QString get_filename() const noexcept;

signals:
    void filename_changed();
    void refresh_after_load();

private:
    QString last_filename;
};

#endif // MENUBAR_HPP
