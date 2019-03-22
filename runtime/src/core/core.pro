include(../../runtime.pri)

QT -= core gui

isEmpty(PRECOMPILED_HEADER):PRECOMPILED_HEADER = $$IDE_SOURCE_TREE/src/pch/runtime_stl_pch.h

TARGET = core
TEMPLATE = lib

DISTFILES += \
    core.pri

DESTDIR = $$PWD/bin
DLLDESTDIR = $$PWD/bin

HEADERS += \
    Resource.hpp \
    analogresource.h \
    digitalresource.h \
    encoderresource.h \
    resources.h

SOURCES += \
    Resource.cpp \
    analogresource.cpp \
    digitalresource.cpp \
    encoderresource.cpp \
    resources.cpp
