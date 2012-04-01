#-------------------------------------------------
#
# Project created by QtCreator 2012-03-31T04:28:03
#
#-------------------------------------------------

QT       += core

QT       += network

QT       -= gui

TARGET = Galactic-Supremacy-Server
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    Server.cpp \
    log.cpp \
    QtWebSocket/QWsSocket.cpp \
    QtWebSocket/QWsServer.cpp

HEADERS += \
    Server.h \
    log.h \
    QtWebSocket/QWsServer.h \
    QtWebSocket/QWsSocket.h \
    Command.h \
    Request.h

OTHER_FILES += \
    Readme.md \
    License.txt
