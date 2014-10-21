TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    matrix.tpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    matrix.h

