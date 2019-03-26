#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "DigitalInputsModel.hpp"
#include "MenuBar.hpp"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    MenuBar menu;
    engine.rootContext()->setContextProperty("menu", &menu);

    DigitalInputsModel di_model;
    QObject::connect(&menu, &MenuBar::refresh_after_load,
                     &di_model, &DigitalInputsModel::refresh);
    engine.rootContext()->setContextProperty("digital_inputs", &di_model);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    return QGuiApplication::exec();
}
