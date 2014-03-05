#pragma once

#include <QObject>
#include "server_state.h"
#include "execution_config.h"


namespace ym
{

class NICservice : public QObject
{
    Q_OBJECT
public:
    explicit NICservice(QObject *parent = 0);
    ~NICservice();

    service_state::State state() const;

    void start(const execution_config& config);

signals:

public slots:
    void stop();
    void terminate();

};


}


