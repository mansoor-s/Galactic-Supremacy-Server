#ifndef SERVER_H
#define SERVER_H

#include <QtCore>
#include <QtNetwork/QtNetwork>

#include "QtWebSocket/QWsServer.h"
#include "QtWebSocket/QWsSocket.h"
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

private:
    QWsServer * server;
    QList<QWsSocket*> clients;
    Log *log;
};


#endif // SERVER_H