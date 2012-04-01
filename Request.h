#ifndef REQUEST_H
#define REQUEST_H

#include <QRegExp>
#include <QStringList>
#include <Qt/qvector3d.h>


class Request {
public:
    enum Type {
        UnitMovement,
        AttackOrder,
        PrivateChat,
        AllianceChat
    };


    Request(int clientId, QString data) {
        this->deserialize(data);
    }
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

        } else {
            this->valid = false;
            return;
        }

        this->valid = true;
    }


    bool isValid() {
    }

private:
    bool valid;
    int type;
    QString id;
    QVector3D *dest;
    QString attackerId;
    QString targetId;
    QString recipient;
    QString message;

};
#endif // REQUEST_H
