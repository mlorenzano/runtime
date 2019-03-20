#include "communication.h"

#include <QMessageBox>
#include <QApplication>

#include "communicationlistener.h"
#include "communication_private.h"
#include "callbackevent.h"
#include "abstractdevice.h"

Communication* Communication::instance = nullptr;

Communication *Communication::getInstance()
{
    if (!instance)
        instance = new Communication();
    return instance;
}

bool Communication::connectToHost()
{
    if (dptr->running)
        return false;

    if (dptr->connected)
        return true;

    notifyStateListeners(ConnectingState);
    dptr->running = false;
    dptr->thread = std::thread(&CommunicationPrivate::run, dptr, m_device);
    while (!dptr->running)
        qApp->processEvents();
    if (!dptr->connected && dptr->thread.joinable())
        dptr->thread.join();
    notifyStateListeners(dptr->connected ? ConnectedState : UnconnectedState);
    return dptr->connected;
}

bool Communication::disconnectFromHost()
{
    notifyStateListeners(ClosingState);
    dptr->stop = true;
    if (dptr->thread.joinable()) {
        request req;
        memset(&req, 0, sizeof(req));
        dptr->requests.append(std::move(req));
        dptr->thread.join();
    }
    notifyStateListeners(UnconnectedState);
    return true;
}

bool Communication::isConnected() const
{
    return (dptr->connected);
}

AbstractDevice* Communication::getDevice()
{
    return m_device;
}

void Communication::setDevice(AbstractDevice *device)
{
    if (!device)
        return;

    if (isConnected())
        disconnectFromHost();
    m_device = device;
    //    m_backend->setNotifyEvent([&](std::function<void(void)> func) {
    //        qApp->postEvent(this, new CallbackEvent(func));
    //    });
    m_device->setTimeoutEvent(std::bind(&Communication::timeoutEvent, this));
}

void Communication::registerListener(CommunicationListener *l)
{
    auto it = std::find(m_listeners.begin(), m_listeners.end(), l);
    if (it == m_listeners.end())
        m_listeners.push_back(l);
}

void Communication::removeListener(CommunicationListener *l)
{
    auto it = std::find(m_listeners.begin(), m_listeners.end(), l);
    if (it != m_listeners.end())
        m_listeners.erase(it);
}

void Communication::registerResourceNotifier(const Resources resource,
                                             std::function<void(int, QVariant)> callback)
{
    m_map.emplace(resource, callback);
}

void Communication::removeResourceNotifiers(const Resources resource)
{
    auto it = m_map.find(resource);
    if (it == m_map.end())
        return;

    m_map.erase(it);
}

Communication::Communication(QObject *parent) :
    QObject(parent),
    m_device(nullptr),
    m_listeners(),
    dptr(new CommunicationPrivate())
{
}

Communication::~Communication()
{
}

void Communication::customEvent(QEvent *e)
{
    if (auto *clbkEvent = dynamic_cast<CallbackEvent*>(e)) {
        auto clbk = clbkEvent->callback();
        if (clbk)
            clbk();
        e->accept();
    }
    QObject::customEvent(e);
}

void Communication::notifyStateListeners(ConnectionState state)
{
    for (auto *listener : m_listeners)
        listener->communicationStateChanged(state);
}

void Communication::timeoutEvent()
{
    disconnectFromHost();
}
