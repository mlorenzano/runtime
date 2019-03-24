#ifndef MENUBAR_HPP
#define MENUBAR_HPP

#include <QObject>

class MenuBar : public QObject
{
    Q_OBJECT
public:
    Q_INVOKABLE void load(QString filename);
};

#endif // MENUBAR_HPP
