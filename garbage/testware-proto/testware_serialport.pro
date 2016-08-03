#-------------------------------------------------
#
# Project created by QtCreator 2015-05-26T13:24:29
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testware_serialport
TEMPLATE = app


SOURCES += main.cpp\
            mainwindow.cpp \
            protothread.cpp

HEADERS  += mainwindow.h \
            protothread.h

FORMS    += mainwindow.ui
