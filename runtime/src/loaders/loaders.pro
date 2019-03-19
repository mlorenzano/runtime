include(../../runtime.pri)

QT += core

isEmpty(PRECOMPILED_HEADER):PRECOMPILED_HEADER = $$IDE_SOURCE_TREE/src/pch/runtime_stl_pch.h

TARGET = loaders
TEMPLATE = lib

DISTFILES += \
    loaders.pri

DESTDIR = $$PWD/bin
DLLDESTDIR = $$PWD/bin

HEADERS += \
    ILoader.hpp \
    ExcelLoader.hpp

SOURCES += \
    ExcelLoader.cpp
