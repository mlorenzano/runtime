#ifndef CALLBACKEVENT_H
#define CALLBACKEVENT_H

#include <QEvent>

class CallbackEvent : public QEvent
{
public:
    CallbackEvent(std::function<void(void)> callback) :
        QEvent(static_cast<QEvent::Type>(registerEventType())),
        m_callback(callback) { }

    std::function<void ()> callback() const { return m_callback; }
    void setCallback(const std::function<void ()> &callback) {
        m_callback = callback;
    }

private:
    std::function<void(void)> m_callback;
};

#endif // CALLBACKEVENT_H
