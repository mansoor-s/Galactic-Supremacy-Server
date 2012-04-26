#-------------------------------------------------
#
# Project created by QtCreator 2012-03-31T04:28:03
#
#-------------------------------------------------

QT       += core

QT       += network

QT       -= gui

#not using mongodb anymore
#LIBS    += -lmongoclient -lboost_thread-mt -lboost_filesystem -lboost_program_options -lboost_system-mt

TARGET = Galactic-Supremacy-Server
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    Server.cpp \
    log.cpp \
    QtWebSocket/QWsSocket.cpp \
    QtWebSocket/QWsServer.cpp \
    Chat.cpp \
    EventLoop.cpp \
    Database.cpp \
    ArenaManager.cpp

HEADERS += \
    Server.h \
    log.h \
    QtWebSocket/QWsServer.h \
    QtWebSocket/QWsSocket.h \
    Command.h \
    Request.h \
    Client.h \
    Chat.h \
    EventLoop.h \
    Flow.h \
    Database.h \
    Units/Ship.h \
    Units/Entity.h \
    Units/Panet.h \
    Units/System.h \
    Units/Moon.h \
    Arena.h \
    ArenaManager.h

OTHER_FILES += \
    Readme.md \
    License.txt \
    .gitignore

#include support for c++0x
QMAKE_CXXFLAGS += -std=c++0x -U__STRICT_ANSI__






