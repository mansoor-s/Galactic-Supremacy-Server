#ifndef REQUEST_H
#define REQUEST_H

#include <QRegExp>
#include <QStringList>
#include <Qt/qvector3d.h>
#include "Client.h"


class Request {
public:
    enum Type {
        UnitMovement,
        AttackOrder,
        PrivateChat,
        AllianceChat,
        Authentication
    };


    Request(Client *client, QString data) {
        this->valid = false;
        this->client = client;
        this->deserialize(data);
    }

    //getters
    Client* getClient() {
        return this->client;
    }

    bool isValid() {
        return this->valid;
    }

    int getType() {
        return this->type;
    }

    QString getId() {
        return this->id;
    }

    QVector3D *getDestination() {
        return this->dest;
    }

    QString getAttackerId() {
        return this->attackerId;
    }

    QString getTargetId() {
        return this->targetId;
    }

    QString getRecipient() {
        return this->recipient;
    }

    QString getMessage() {
        return this->message;
    }

    QString getSessionId() {
        return this->sessionId;
    }


protected:
    /*
    Reques formats:

    unit movment
    type,unitId,dest_x,dest_y,dest_z

    attack order
    type,attacerShipId,targetShipId

    private chat:
    type,recipient,message     message in doublequotes

    alliance chat
    type,message

    authentication
    type,sessionId

  */
    void deserialize(QString data) {
        QStringList strList = data.split(",");
        int count = strList.count();

        if (count == 1) {
            this->valid = false;
            return;
        }

        this->type = strList.at(0).toInt();

        if (this->type == Request::UnitMovement && count == 5) {
            this->id = strList.at(1);
            this->dest = new QVector3D(strList.at(2).toFloat(),
                                       strList.at(3).toFloat(), strList.at(4).toFloat());

        } else if (this->type == Request::AttackOrder && count == 3) {
            this->attackerId = strList.at(1);
            this->targetId = strList.at(2);

        } else  if (this->type == Request::PrivateChat && count == 3) {
            this->recipient = strList.at(1);
            this->message = strList.at(2);

        } else if (this->type == Request::AllianceChat && count == 2) {
            this->message = strList.at(1);

        } else if (this->type == Request::Authentication && count == 2) {
            this->sessionId = strList.at(1);
        } else {
            this->valid = false;
            return;
        }

        this->valid = true;
    }

private:
    Client *client;
    bool valid;
    int type;
    QString id;
    QVector3D *dest;
    QString attackerId;
    QString targetId;
    QString recipient;
    QString message;
    QString sessionId;

};
#endif // REQUEST_H
