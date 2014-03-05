TARGET = nic_rx_udp

CONFIG   -= app_bundle
TEMPLATE = app

include(../../config.pri)

LIBS += -L$$LIB_PATH -lboost_program_options -lboost_system

SOURCES += main.cpp
SOURCES += udpreceiver.cpp

HEADERS += udpreceiver.h
