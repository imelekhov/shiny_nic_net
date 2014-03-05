#include <QHostAddress>
#include <QThread>
#include "clientsmanager.h"

using namespace ym;

class Sleeper : public QThread
{
public:
    static void usleep(unsigned long usecs){QThread::usleep(usecs);}
    static void msleep(unsigned long msecs){QThread::msleep(msecs);}
    static void sleep(unsigned long secs){QThread::sleep(secs);}
};

ClientsManager::ClientsManager(QObject *parent)
    : QObject(parent)
      , bytesTransmitted(0)
{
}

ClientsManager::~ClientsManager()
{
}

void ClientsManager::write_to_one()
{
}

void ClientsManager::write_to_all(int thread_id,
                                  const QString& outstr)
{
    mutex.lock();
    QList<ValueType> sockets = clients_.values();
    mutex.unlock();

    const QByteArray& message = outstr.toUtf8();

    foreach (ValueType socket, sockets) {
        mutex.lock();
        if(socket && socket->isValid() &&
           QAbstractSocket::ConnectedState == socket->state())
        {
            socket->write(message);
            //socket->waitForBytesWritten(1);
            socket->flush();

            bytesTransmitted += message.size() * sizeof(char);


            QString user = socket->peerAddress().toString() + ":" +
                           QString::number(socket->peerPort());
            QTextStream(stdout) << thread_id << ": write to client: "
                                << user << ", msg: " << outstr << "\n";
        }
        mutex.unlock();
    }
}

int ClientsManager::size() const
{
    mutex.lock();
    int res = clients_.size();
    mutex.unlock();
    return res;
}

int ClientsManager::getBytesTransmitted() const
{
    return bytesTransmitted;
}

void ClientsManager::add(const ym::KeyType & key, const ym::ValueType & value)
{
    mutex.lock();
    clients_.insert(key, value);
    mutex.unlock();
}

void ClientsManager::remove(const ym::KeyType & key)
{
    mutex.lock();
    clients_[key]->close();
    clients_[key]->deleteLater();
    //delete clients_[key];
    clients_[key] = 0;
    clients_.remove(key);
    mutex.unlock();
}

