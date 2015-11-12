#-------------------------------------------------
#
# Project created by QtCreator 2015-11-05T12:29:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TPRLab2
TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp\
        tableresult.cpp \
    thing.cpp \
    setofthings.cpp \
    calculator.cpp

HEADERS  += tableresult.h \
    thing.h \
    setofthings.h \
    constants.h \
    calculator.h

FORMS    += tableresult.ui
