#include <QHostAddress>
#include <QThread>
#include "rxclienttask.h"


using namespace ym;

class Sleeper : public QThread
{
public:
    static void usleep(unsigned long usecs){QThread::usleep(usecs);}
    static void msleep(unsigned long msecs){QThread::msleep(msecs);}
    static void sleep(unsigned long secs){QThread::sleep(secs);}
};


RxClientTask::RxClientTask(int id,
                           ClientsManager& manager,
                           const QString& message)
    : id_(id),
      client_manager_(manager),
      message_(message)
{
}

void RxClientTask::set_socket_descriptor(int value)
{
    sock_descriptor_ = value;
}

void RxClientTask::run()
{
    QTextStream(stdout) << "task " << id_ << " started\n";
    QTextStream(stdout) << id_ << ": clients size = " << client_manager_.size() << "\n";
    message_ += "\n";
    client_manager_.write_to_all(id_, message_);

    QTextStream(stdout) << "task " << id_ << " stopped\n";
}
