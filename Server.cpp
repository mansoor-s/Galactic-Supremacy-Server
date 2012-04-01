#include "Server.h"
#include <QDebug>

Server::Server(Log *log)
{
    this->log = log;
    int port = 1337;
    server = new QWsServer(this);
    if ( ! server->listen(QHostAddress::Any, port) )
    {
        log->log( "Error: Can't launch server" );
    }
    else
    {
        log->log( "Server is listening port " + QString::number(port) );
    }
    connect(server, SIGNAL(newConnection()), this, SLOT(onClientConnection()));
    this->log = log;
}

Server::~Server()
{
}

void Server::onClientConnection()
{
    QWsSocket * clientSocket = server->nextPendingConnection();

    QObject * clientObject = qobject_cast<QObject*>(clientSocket);

    connect(clientObject, SIGNAL(frameReceived(QString)), this, SLOT(onDataReceived(QString)));
    connect(clientObject, SIGNAL(disconnected()), this, SLOT(onClientDisconnection()));
    connect(clientObject, SIGNAL(pong(quint64)), this, SLOT(onPong(quint64)));

    clients << clientSocket;

    log->log("Client connected");
}

void Server::onDataReceived(QString data)
{
    QWsSocket * socket = qobject_cast<QWsSocket*>( sender() );
    if (socket == 0)
        return;

    log->log( data );

    QWsSocket * client;
    foreach ( client, clients )
    {
        client->write( data );
    }
}

void Server::onPong(quint64 elapsedTime)
{
    log->log( "ping: " + QString::number(elapsedTime) + " ms" );
}

void Server::onClientDisconnection()
{
    QWsSocket * socket = qobject_cast<QWsSocket*>(sender());
    if (socket == 0)
        return;

    clients.removeOne(socket);

    socket->deleteLater();

    log->log("Client disconnected");
}

