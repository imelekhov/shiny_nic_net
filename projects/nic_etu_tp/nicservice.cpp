#include "nicservice.h"

ym::NICservice::NICservice(QObject *parent) :
    QObject(parent)
{
}

ym::NICservice::~NICservice()
{
}

ym::service_state::State ym::NICservice::state() const
{
    return ym::service_state::Stopped;
}


void ym::NICservice::start(const ym::execution_config &config)
{
}

void ym::NICservice::stop()
{
}

void ym::NICservice::terminate()
{
}
