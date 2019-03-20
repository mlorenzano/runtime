MODULE_NAME = communication

include(../../module.pri)

DEFINES += COMMUNICATION_LIBRARY

INCLUDEPATH += \
    $$PWD

HEADERS += \
    include/callbackevent.h \
    include/communication_private.h \
    include/safequeue.h \
    shared/abstractdevice.h \
    shared/communication.h \
    shared/communication_global.h \
    shared/communication_shared.h \
    shared/communicationlistener.h

SOURCES += \
    src/communication.cpp \
    src/communication_private.cpp

FORMS +=

