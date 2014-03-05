#pragma once

#include <QObject>
#include <QUdpSocket>

namespace SocketKit
{

static const int MAX_MSG_LEN = 8000;

class AbstractSocket : public QObject
{
Q_OBJECT
protected:
    QUdpSocket socket_;
public:
    explicit AbstractSocket (QObject* = 0);
    virtual bool bind (quint16 port) = 0;
};

}
