#pragma once

#include <QRunnable>
#include <QTcpSocket>
#include <QDebug>

#include "clientsmanager.h"


namespace ym
{
class RxClientTask : public QRunnable
{
public:
    RxClientTask(int id,
                 ClientsManager& clts,
                 const QString& msg);

public:
    void set_socket_descriptor(int value);

protected:
    void run();

private:
    int sock_descriptor_;

    int id_;
    ClientsManager& client_manager_;
    QString message_;
};
}


