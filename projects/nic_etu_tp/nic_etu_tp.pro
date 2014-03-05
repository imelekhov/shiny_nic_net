QT       += core network gui

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += widgets
}

TARGET = nic_srv

CONFIG   -= app_bundle
TEMPLATE  = app

include(../../config.pri)

LIBS += -L$$LIB_PATH -lboost_system -lboost_thread

SOURCES += main.cpp \
    udpreceiver.cpp
SOURCES += abstractsocket.cpp
SOURCES += abstractsocketreader.cpp
SOURCES += incomesocketreader.cpp
SOURCES += rxclienttask.cpp
SOURCES += nicserver.cpp
SOURCES += mainform.cpp
SOURCES += nicservice.cpp
SOURCES += clientsmanager.cpp

HEADERS += rxclienttask.h \
    udpreceiver.h
#HEADERS += thread_pool.h
HEADERS += abstractsocket.h
HEADERS += abstractsocketreader.h
HEADERS += incomesocketreader.h
HEADERS += nicserver.h
HEADERS += mainform.h
HEADERS += execution_config.h
HEADERS += server_state.h
HEADERS += excep.h
HEADERS += nicservice.h
HEADERS += clientsmanager.h

FORMS += mainform.ui
