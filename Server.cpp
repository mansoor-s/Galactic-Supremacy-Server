#include "Server.h"

Server::Server(DatabasePool *db, Log *log) {
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

Server::~Server() {
    //delete db objects to cleanly close db connections
}

void Server::onClientConnection() {
    Client * clientSocket = dynamic_cast<Client*>(server->nextPendingConnection());

    QObject * clientObject = qobject_cast<QObject*>(clientSocket);

    connect(clientObject, SIGNAL(frameReceived(QString)), this, SLOT(onDataReceived(QString)));
    connect(clientObject, SIGNAL(disconnected()), this, SLOT(onClientDisconnection()));
    connect(clientObject, SIGNAL(pong(quint64)), this, SLOT(onPong(quint64)));

    clients << clientSocket;
}

void Server::onDataReceived(QString data) {
    Client * socket = qobject_cast<Client*>( sender() );
    if (socket == 0)
        return;

    try {

         Request *request = new Request(socket, data);

        //ignore malformed requests... perhaps log them in the future??
        if(!request->isValid()) {
            delete request;
            return;
        }

        route(request);
    } catch(std::exception &e) {

    } catch(int e) {

    }
}

void Server::onPong(quint64 elapsedTime) {
    log->log( "ping: " + QString::number(elapsedTime) + " ms" );
}

void Server::onClientDisconnection() {
    Client * socket = qobject_cast<Client*>(sender());
    if (socket == 0)
        return;

    clients.removeOne(socket);

    socket->deleteLater();
}

void Server::route(Request *req) {
    switch(req->getType()) {
        case Request::UnitMovement:

            break;
    }
}

