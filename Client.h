#ifndef CLIENT_H
#define CLIENT_H

#include "QtWebSocket/QWsSocket.h"

class Client : public QWsSocket
{
    Q_OBJECT
public:
    Client(QTcpSocket * socket, QObject * parent);

    void isAuthenticated(bool auth) {
        this->authenticated = auth;
    }

    QString clientId() {
        return this->authId;
    }

    void setClientId(QString id) {
        this->authId = id;
    }
private:
    bool authenticated;
    QString authId;
};

#endif // CLIENT_H
