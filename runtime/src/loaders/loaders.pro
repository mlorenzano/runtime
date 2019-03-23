include(../../runtime.pri)

include(../3rdparty/xlnt/xlnt.pri)
include(../core/core.pri)

QT -= core gui

isEmpty(PRECOMPILED_HEADER):PRECOMPILED_HEADER = $$IDE_SOURCE_TREE/src/pch/runtime_stl_pch.h

TARGET = loaders
TEMPLATE = lib

DISTFILES += \
    loaders.pri

DESTDIR = $$PWD/bin
DLLDESTDIR = $$PWD/bin

HEADERS += \
    ILoader.hpp \
    ExcelLoader.hpp \
    CsvLoader.hpp \
    Loader.hpp

SOURCES += \
    ILoader.cpp \
    ExcelLoader.cpp \
    CsvLoader.cpp \
    Loader.cpp
