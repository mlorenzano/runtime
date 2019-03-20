#include "communication_private.h"

#include <QDebug>

CommunicationPrivate::CommunicationPrivate() :
    notifyEvent(nullptr),
    requests(),
    connected(false),
    stop(false),
    thread(),
    sendEvent(nullptr),
    timeoutEvent(nullptr),
    running(false)
{
}

void CommunicationPrivate::run(AbstractDevice *device)
{
    int rc = 0, size = 0;
    char buffer[512];
    unsigned char bufferIndex = 0;
    request req;

    running = false;
    if (!device || (device && !device->connectHost())) {
        running = false;
        return;
    }

    connected = true;
    stop = false;
    running = true;
    while (!stop) {
        req = requests.dequeue();
        size = make_frame(req, buffer);
        rc = device->sendBytes(buffer, size);
        if (rc < 0) {
            qDebug() << "Request cmd failed:" << req.command;
            requests.append(req);
            continue;
        }

        memset(&buffer, 0, sizeof(buffer));
        rc = device->readBytes(buffer, 512);
        //TODO: handle the case that the device reads less bytes than expected

        //TODO: add buffer parsing

//        if (notifyEvent) {
//            for (int i = 0; i < rc; i++)
                  //bind event to resource notifier
//                notifyEvent(std::bind(resourceIndex, value));
//        }
        rc = 0;
    }
    if (device) {
        device->disconnectHost();
        connected = false;
    }
    running = false;
}

int CommunicationPrivate::make_frame(request req, char *buffer)
{
    int i = 3, j = 0;
    char ck = 0;

    memset(&buffer, 0, sizeof(buffer));
    buffer[0] = '@';
    buffer[1] = req.command;
    buffer[2] = 3 + req.size;
    for (; j < req.size; i++, j++)
        buffer[i + j] = req.buffer[j];
    for (j = 0; j < i; j++)
        ck ^= buffer[j];
    if (ck == buffer[0])
        ck++;
    buffer[i++] = ck;
    buffer[i++] = 0;
    return i;
}
