#ifndef COMMUNICATIONLISTENER_H
#define COMMUNICATIONLISTENER_H

#include "communication.h"

class COMMUNICATION_EXPORT CommunicationListener
{
public:    
    virtual ~CommunicationListener() {}

    virtual void communicationStateChanged(Communication::ConnectionState state) = 0;
};

#endif // COMMUNICATIONLISTENER_H
