#-------------------------------------------------
#
# Project created by QtCreator 2012-03-31T04:28:03
#
#-------------------------------------------------

QT       += core

QT       += network

QT       -= gui

LIBS    += -lmongoclient -lboost_thread-mt -lboost_filesystem -lboost_program_options -lboost_system-mt

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
    DatabasePool.cpp \
    DBWorker.cpp \
    Ship.cpp

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
    DatabasePool.h \
    DBWorker.h \
    Ship.h \
    Flow.h

OTHER_FILES += \
    Readme.md \
    License.txt \
    .gitignore


