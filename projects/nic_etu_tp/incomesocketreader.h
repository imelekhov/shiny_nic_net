#pragma once

#include "abstractsocketreader.h"
#include <QDebug>
#include <QTextStream>

#include <string>

namespace SocketKit
{

enum UDPError
{
    NONE = 0,
    LENGTH = 1
};

class IncomeSocketReader : public AbstractSocketReader
{
Q_OBJECT
public:
    explicit IncomeSocketReader (QObject* = 0);
    void closeSocket();
public slots:
    void readSocket ();
signals:
    void new_income_message(const std::string& data, SocketKit::UDPError);
};

template<typename Stream>
Stream operator << (Stream out, const UDPError& error) {
    switch (error) {
        case SocketKit::NONE:
            break;
        case SocketKit::LENGTH:
            out << "ERROR: receiving message length != length of struct Track" << endl;
            break;
    }

    return out;
}

}
