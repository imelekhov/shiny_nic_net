#pragma once

#include <QMap>
#include <QTcpSocket>

namespace ym
{
    typedef int KeyType;
    typedef QTcpSocket* ValueType;
    typedef QMap<KeyType, ValueType> ClientsContainer;
}


