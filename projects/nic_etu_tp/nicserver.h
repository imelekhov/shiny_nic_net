#pragma once

#include <QSharedPointer>
#include <QTcpServer>
#include <QThreadPool>
#include <QDebug>
#include <QMap>
#include <QTimer>

#include <stdint.h>

#include "server_state.h"
#include "incomesocketreader.h"
#include "clientsmanager.h"
#include "udpreceiver.h"

namespace ym
{
class NICServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit NICServer(QObject *parent = 0);

    void start(uint16_t udp_port, uint16_t tcp_port);
    void resume();
    void stop();
    void set_num_of_threads(uint16_t value);
    //void terminate();


    ym::service_state::State state() const;

protected:
    void incomingConnection(int handle);

signals:
    void update_statistic(int, int);
    void clientAdded(const QString&);
    void clientRemoved(const QString&);

public slots:


private slots:
    void new_datagram_received(const std::string& message,
                               SocketKit::UDPError error);
    void readyRead();
    void disconnected();
    void update_stat();

private:
    QThreadPool *pool_;
    service_state::State state_;

    typedef QSharedPointer<SocketKit::IncomeSocketReader> SocketPtr;
    SocketPtr udp_reader_;

    ym::UDPReceiver udp_receiver_;

    ClientsManager clients_manager_;

    int timeout_;
    typedef QSharedPointer<QTimer> TimerPtr;
    TimerPtr timer_;

    int bytesReceived;
    int bytesTransmitted;
};
}



