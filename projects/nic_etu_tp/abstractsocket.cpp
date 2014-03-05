#include "abstractsocket.h"

namespace SocketKit
{

AbstractSocket::AbstractSocket (QObject* parent) : QObject(parent), socket_(this)
{
}

}

