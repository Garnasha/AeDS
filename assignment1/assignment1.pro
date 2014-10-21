TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    matrix.tpp \
    wormholeCalc.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    matrix.h

