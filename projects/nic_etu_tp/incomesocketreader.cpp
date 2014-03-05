#include "incomesocketreader.h"

namespace SocketKit
{

IncomeSocketReader::IncomeSocketReader (QObject* parent) : AbstractSocketReader(parent)
{
}

void IncomeSocketReader::closeSocket()
{
    socket_.close();
}

void IncomeSocketReader::readSocket () {
    UDPError error = SocketKit::NONE;
    const int len = socket_.readDatagram(msg_, MAX_MSG_LEN);
    if (len == -1)
    {
        error = SocketKit::LENGTH;
        return;
    }

    emit new_income_message(std::string(msg_), error);
}

}
