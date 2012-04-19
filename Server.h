#ifndef SERVER_H
#define SERVER_H

#include <exception>
#include <QtCore>
#include <QtNetwork/QtNetwork>

#include "QtWebSocket/QWsServer.h"
#include "QtWebSocket/QWsSocket.h"
#include "Client.h"
#include "Command.h"
#include "Request.h"
#include "log.h"

class Server : public QObject
{
    Q_OBJECT

public:
    Server(Log *log);
    ~Server();

public slots:
    void onClientConnection();
    void onDataReceived(QString data);
    void onPong(quint64 elapsedTime);
    void onClientDisconnection();
    void route(Request* req);

private:
    QWsServer * server;
    QList<Client*> clients;
    Log *log;
};


#endif // SERVER_H
