include(../../runtime.pri)

include(../3rdparty/xlnt/xlnt.pri)
include(../core/core.pri)
include(../loaders/loaders.pri)

isEmpty(PRECOMPILED_HEADER):PRECOMPILED_HEADER = $$IDE_SOURCE_TREE/src/pch/runtime_gui_pch.h

QT += core gui quick

DESTDIR = $$IDE_APP_PATH
TEMPLATE = app
TARGET = $$qtLibraryName(runtime)

LIBS += -L$$IDE_LIBRARY_PATH

SOURCES += \
    main.cpp \
    MenuBar.cpp \
    DigitalInputsModel.cpp

RESOURCES += \
    $$PWD/qml/qml.qrc \
    $$PWD/images/images.qrc

HEADERS += \
    MenuBar.hpp \
    DigitalInputsModel.hpp
