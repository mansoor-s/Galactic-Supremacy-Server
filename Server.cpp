#include "Server.h"

Server::Server(Log *log)
{
    this->log = log;
    int port = 1337;
    server = new QWsServer(this);
    if ( ! server->listen(QHostAddress::Any, port) )
    {
        log->log( "Error: Can't launch server. You suck." );
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
    Client * clientSocket = dynamic_cast<Client*>(server->nextPendingConnection());

    QObject * clientObject = qobject_cast<QObject*>(clientSocket);

    connect(clientObject, SIGNAL(frameReceived(QString)), this, SLOT(onDataReceived(QString)));
    connect(clientObject, SIGNAL(disconnected()), this, SLOT(onClientDisconnection()));
    connect(clientObject, SIGNAL(pong(quint64)), this, SLOT(onPong(quint64)));

    clients << clientSocket;
}

void Server::onDataReceived(QString data)
{
    Client * socket = qobject_cast<Client*>( sender() );
    if (socket == 0)
        return;

    Request *request = new Request(socket, data);

}

void Server::onPong(quint64 elapsedTime)
{
    log->log( "ping: " + QString::number(elapsedTime) + " ms" );
}

void Server::onClientDisconnection()
{
    Client * socket = qobject_cast<Client*>(sender());
    if (socket == 0)
        return;

    clients.removeOne(socket);

    socket->deleteLater();

    log->log("Client disconnected");
}

