#-------------------------------------------------
#
# Project created by QtCreator 2022-11-25T16:11:52
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TCP-Test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        tcpserver.cpp \

HEADERS  += mainwindow.h \
    tcpserver.h

FORMS    += mainwindow.ui
