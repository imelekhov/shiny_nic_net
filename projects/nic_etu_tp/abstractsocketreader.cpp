#include "abstractsocketreader.h"

namespace SocketKit
{

AbstractSocketReader::AbstractSocketReader (QObject* parent) : AbstractSocket (parent) {
    connect(&socket_, SIGNAL(readyRead()), this, SLOT(readSocket()));
    msg_ = new char[MAX_MSG_LEN];
}

bool AbstractSocketReader::bind (quint16 port) {
    port_ = port;
    return socket_.bind(port);
}

AbstractSocketReader::~AbstractSocketReader (void) {
    delete[] msg_;
}

quint16 AbstractSocketReader::port(void) const {
    return port_;
}

}
