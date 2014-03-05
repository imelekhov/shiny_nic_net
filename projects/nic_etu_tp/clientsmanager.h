#pragma once

#include <QMutex>
#include <QObject>
#include "nic_types.h"


namespace ym
{
class ClientsManager : public QObject
{
    Q_OBJECT
public:
    explicit ClientsManager(QObject *parent = 0);
    ~ClientsManager();

public:
    void write_to_all(int, const QString&);
    int size() const;
    int getBytesTransmitted() const;
    const QList<KeyType>& keys() const {
        return clients_.keys();
    }

    void add(const ym::KeyType&, const ym::ValueType&);
    void remove(const ym::KeyType&);

private:
    void write_to_one();

private:
    ClientsContainer clients_;
    mutable QMutex mutex;

    int bytesTransmitted;
};
}


