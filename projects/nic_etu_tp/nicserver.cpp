#include "nicserver.h"
#include "rxclienttask.h"

#include <boost/thread.hpp>

using namespace ym;

NICServer::NICServer(QObject *parent)
    : QTcpServer(parent)
    , pool_(new QThreadPool(this))
    , state_(ym::service_state::Init)
    , udp_reader_(SocketPtr(new SocketKit::IncomeSocketReader(parent)))
    , timeout_(1000)
    , timer_(TimerPtr(new QTimer(this)))
    , bytesReceived(0)
    , bytesTransmitted(0)
{
    connect(udp_reader_.data(), SIGNAL(new_income_message(std::string,SocketKit::UDPError)),
            this, SLOT(new_datagram_received(std::string,SocketKit::UDPError)));

    uint16_t hardware_conc = boost::thread::hardware_concurrency();
    pool_->setMaxThreadCount(hardware_conc);

    connect(timer_.data(), SIGNAL(timeout()), this, SLOT(update_stat()));
    timer_->start(timeout_);
}



void NICServer::start(uint16_t udp_port, uint16_t tcp_port)
{
    if(this->listen(QHostAddress::LocalHost, tcp_port))
    {
        if(udp_reader_->bind(udp_port))
        {
            qDebug() << "Bound to udp_socket successfully";
        }
        else
        {
            qDebug() << "udp_port (" << udp_port << ") bind failed. Have to change NIC server settings";
            state_ = ym::service_state::UDPfailed;
            return;
        }

        qDebug() << "Server started";
        state_ = ym::service_state::Started;
    }
    else
    {
        qDebug() << "Server did not start!";
    }
}

void NICServer::resume()
{
    state_ = ym::service_state::Resumed;
}

void NICServer::set_num_of_threads(uint16_t value)
{
    pool_->setMaxThreadCount(value);
}

ym::service_state::State NICServer::state() const
{
    return state_;
}

void NICServer::stop()
{
    state_ = ym::service_state::Stopped;
}
/*
void NICServer::terminate()
{
    if(state_ == ym::service_state::Started ||
       state_ == ym::service_state::Stopped ||
       state_ == ym::service_state::Resumed )
    {
        QList<KeyType> keys = clients_manager_.keys();

        foreach(KeyType key, keys) {
            clients_manager_.remove(key);
        }

        //clients_manager_.remove_all();
    }
    close();
    udp_reader_->closeSocket();
    state_ = ym::service_state::Terminated;
}
*/

void NICServer::incomingConnection(int handle)
{
    /*
    if (state_ != ym::service_state::Terminated)
    {
        */
        QTcpSocket *client = new QTcpSocket(this);
        bool q = client->setSocketDescriptor(handle);
        QString user = client->peerAddress().toString() + ":" +
                QString::number(client->peerPort());

        QTextStream(stdout) << "Client connected: " << user << "\n";

        clients_manager_.add(client->peerPort(), client);

        connect(client, SIGNAL(readyRead()), this, SLOT(readyRead()));
        connect(client, SIGNAL(disconnected()), this, SLOT(disconnected()));

        emit clientAdded(user);
    //}
}

void NICServer::update_stat()
{
    bytesTransmitted = clients_manager_.getBytesTransmitted();
    emit update_statistic(bytesReceived, bytesTransmitted);
}

void NICServer::readyRead()
{
    QTcpSocket *client = (QTcpSocket*)sender();
    while(client->canReadLine())
    {
        QString str = QString::fromUtf8(client->readLine()).trimmed();
        QTextStream(stdout) << "Msg from client: " << str << "\n";

    }
}

void NICServer::disconnected()
{
    QTcpSocket *client = (QTcpSocket*)sender();
    QString host = client->peerAddress().toString();
    int port = client->peerPort();
    QString user = client->peerAddress().toString() + ":" +
            QString::number(client->peerPort());
    QString disconnect_msg = "Client disconnected: " + user;
    QTextStream(stdout) << disconnect_msg << "\n";

    int descr = client->socketDescriptor();

    clients_manager_.remove(port);

    emit clientRemoved(user);
}


void NICServer::new_datagram_received(const std::string &message,
                                      SocketKit::UDPError error)
{
    /*
    if (state_ != ym::service_state::Stopped &&
        state_ != ym::service_state::Terminated)
        */
    if (state_ != ym::service_state::Stopped)
    {
        static int counter = 0;
        if (error == SocketKit::NONE)
        {
            bytesReceived += message.size() * sizeof(char);

            QTextStream(stdout) << "new_datagram_received!!! Message: " <<
                                   message.c_str() << "\n";

            // ------- TASK --------------------------
            RxClientTask *task = new RxClientTask(counter, clients_manager_, QString(message.c_str()));
            task->setAutoDelete(true);

            pool_->start(task);
            qDebug() << "pool started " << counter++;
            // ------- ----- --------------------------
        }
    }
}
