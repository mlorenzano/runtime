MODULE_NAME = communication

include(../../module.pri)

LIB_VERSION = 1.0.0
DEFINES += STR_LIB_VERSION=\\\"$$LIB_VERSION\\\"
DEFINES += COMMUNICATION_LIBRARY
INCLUDEPATH += ./

HEADERS += \
    $$PWD/shared/communication_global.h

SOURCES += \

FORMS +=

