#ifndef COMMUNICATION_PRIVATE_H
#define COMMUNICATION_PRIVATE_H

#include <functional>
#include <atomic>
#include <thread>

#include "abstractdevice.h"
#include "safequeue.h"

struct request {
    char command;
    char size;
    char *buffer;
};

class CommunicationPrivate
{
public:
    CommunicationPrivate();

    std::function<void(std::function<void(void)>)> notifyEvent;
    SafeQueue<request> requests;
    std::atomic_bool connected;
    std::atomic_bool stop;
    std::thread thread;
    std::function<void(unsigned short,unsigned short)> sendEvent;
    std::function<void()> timeoutEvent;
    std::atomic_bool running;

    void run(AbstractDevice *device);
    int make_frame(request req, char *buffer);
    char calculateChecksum(char *buffer, int size);
};

#endif // COMMUNICATION_PRIVATE_H
