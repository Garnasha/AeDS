TEMPLATE = app
CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
	matrix.cpp \
    wormholeCalc.cpp \
    indirectionSort.cpp \
    starchartIO.cpp \
    prim.cpp


include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    matrix.h \
    indirectionSort.h \
    starchartIO.h \
    wormholeCalc.h \
    starchart_types.h \
    prim.h

OTHER_FILES += \
    example.in

