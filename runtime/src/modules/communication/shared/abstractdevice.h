#ifndef ABSTRACTBACKEND_H
#define ABSTRACTBACKEND_H

#include <functional>
#include <string>

#include "communication_global.h"

class COMMUNICATION_EXPORT AbstractDevice
{
public:
    AbstractDevice() { }
    AbstractDevice(const AbstractDevice &) = delete;
    AbstractDevice(AbstractDevice &&) = default;
    AbstractDevice& operator=(const AbstractDevice &other) = delete;
    virtual ~AbstractDevice() { }

    virtual bool connectHost() = 0;
    virtual bool disconnectHost() = 0;
    virtual bool isConnected() const = 0;

    virtual void reset() = 0;

    virtual int sendBytes(const char *buffer, const int size) = 0;
    virtual int readBytes(char *buffer, const int maxBufferSize) = 0;

    virtual void setTimeoutEvent(const std::function<void ()> &timeoutEvent) = 0;
};

#endif // ABSTRACTBACKEND_H
