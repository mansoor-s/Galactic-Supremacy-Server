#ifndef CLIENT_H
#define CLIENT_H

#include "QtWebSocket/QWsSocket.h"



class Client : public QWsSocket
{
    Q_OBJECT

    class Arena {};
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

    void setArena(Arena* arena) {
        this->arena = arena;
    }

    Arena* getArena() {
        return this->arena;
    }

private:
    bool authenticated;
    QString authId;
    Arena* arena;
};

#endif // CLIENT_H
