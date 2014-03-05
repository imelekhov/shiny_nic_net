TARGET = nic_txc

CONFIG   -= app_bundle
TEMPLATE = app

include(../../config.pri)

LIBS += -L$$LIB_PATH -lboost_program_options -lboost_system

SOURCES += main.cpp \
    udpsender.cpp
SOURCES +=

HEADERS += \
    udpsender.h
