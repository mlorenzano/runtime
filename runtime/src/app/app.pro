include(../../runtime.pri)

isEmpty(PRECOMPILED_HEADER):PRECOMPILED_HEADER = $$IDE_SOURCE_TREE/src/pch/runtime_gui_pch.h

QT += core gui

DESTDIR = $$IDE_APP_PATH
TEMPLATE = app
TARGET = $$qtLibraryName(runtime)

LIBS += -L$$IDE_LIBRARY_PATH

SOURCES += \
    main.cpp \
    mainwindow.cpp

FORMS += \
    mainwindow.ui

HEADERS += \
    mainwindow.h
