depfile = $$replace(_PRO_FILE_PWD_, ([^/]+$), \\1/\\1_dependencies.pri)
exists($$depfile) {
    include($$depfile)
    isEmpty(MODULE_NAME): \
        error("$$basename(depfile) does not define MODULE_NAME.")
} else {
    isEmpty(MODULE_NAME): \
        error("MODULE_NAME is empty. Maybe you meant to create $$basename(depfile)?")
}

CONFIG += shared dll
greaterThan(QT_MAJOR_VERSION, 4) {
    CONFIG += c++14
} else {
    QMAKE_CXXFLAGS += -std=c++0x
}

TARGET = $$MODULE_NAME

include(../runtime.pri)

isEmpty(TARGET) {
    error("module.pri: You must provide a TARGET")
}
TARGET = $$qtLibraryName($$TARGET)

QT += core

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += widgets
} else {
    QT += gui
}

TEMPLATE = lib

CONFIG(static) {
    DESTDIR = $$IDE_LIBRARY_PATH/static/
}
else {
    DESTDIR = $$IDE_LIBRARY_PATH/
}

LIBS += -L$$DESTDIR
INCLUDEPATH += \
    $$OUT_PWD/ \
    $$OUT_PWD/shared/ \
    $$OUT_PWD/include/

OBJECTS_DIR = $${OUT_PWD}/obj
MOC_DIR = $${OUT_PWD}/obj
RCC_DIR = $${OUT_PWD}/obj
UI_DIR = $${OUT_PWD}/obj
