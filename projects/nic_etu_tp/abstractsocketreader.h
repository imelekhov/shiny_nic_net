#pragma once

#include "abstractsocket.h"

namespace SocketKit
{
class AbstractSocketReader : public AbstractSocket
{
Q_OBJECT
    quint16 port_;
protected:
    char* msg_;
public:
    explicit AbstractSocketReader (QObject* = 0);
    ~AbstractSocketReader ();
    bool bind (quint16 port);
    quint16 port() const;
protected slots:
    virtual void readSocket () = 0;
};

}
