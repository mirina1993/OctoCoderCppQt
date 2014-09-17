#-------------------------------------------------
#
# Project created by QtCreator 2014-09-09T16:18:39
#
#-------------------------------------------------

QT       += core

QT       += gui
QT       += widgets
QT       += network
TARGET = MyTCPserver
CONFIG   += console
CONFIG   -= app_bundle

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyClient
TEMPLATE = app


SOURCES += main.cpp \
    MyClient.cpp

HEADERS  += \
    MyClient.h
