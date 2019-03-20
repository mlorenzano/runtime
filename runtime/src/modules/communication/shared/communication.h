#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <functional>
#include <memory>
#include <vector>

#include <QObject>

#include "communication_global.h"
#include "communication_shared.h"

class CommunicationPrivate;
class CommunicationListener;
class AbstractDevice;

class COMMUNICATION_EXPORT Communication : public QObject
{
    Q_OBJECT

public:
    enum ConnectionState {
        UnconnectedState,
        ConnectingState,
        ConnectedState,
        ClosingState
    };

    static Communication* getInstance();

    bool connectToHost();
    bool disconnectFromHost();
    bool isConnected() const;

    AbstractDevice* getDevice();
    void setDevice(AbstractDevice *device);

    void registerListener(CommunicationListener *l);
    void removeListener(CommunicationListener *l);

    void registerResourceNotifier(const Resources resource,
                                  std::function<void(int, QVariant)> callback);
    void removeResourceNotifiers(const Resources resource);

signals:
    void error(const QString &title, const QString &message,
               const QString &description, bool exec);

protected:
    explicit Communication(QObject *parent = nullptr);
    ~Communication();

    void customEvent(QEvent *e);

private:
    static Communication *instance;
    AbstractDevice *m_device;
    std::vector<CommunicationListener*> m_listeners;
    std::map<Resources, std::function<void(int, QVariant)> > m_map;
    CommunicationPrivate *dptr;

    void notifyStateListeners(Communication::ConnectionState state);
    void timeoutEvent();
};

Q_DECLARE_METATYPE(Communication::ConnectionState)

#endif // COMMUNICATION_H
