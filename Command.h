#ifndef COMMAND_H
#define COMMAND_H

#include <Qt/qvector3d.h>
#include <QString>
#include <QDateTime>

class Command
{
public:
    /*
    task ids:

    0 - unit movement
    1 - unit position update
    2 - player/infrustrcuture updates
    3 - private chat
    4 - alliance chat
    */
    enum Type {
        UnitMovement,
        UnitPosition,
        PlayerUpdate,
        PrivateChat,
        AllianceChat
    };

    //unit position
    Command(int type, QVector3D position) {
        this->type = type;
        this->pos = position;
    }

    //unit movement
    Command(int type, QVector3D position, QVector3D destination) {
        this->type = type;
        this->pos = position;
        this->dest = destination;
    }

    //privateChat
    Command(int type, QString sender, QDateTime time, QString message) {
        this->type = type;
        this->sender = sender;
        this->time = time;
        this->message = message;
    }


    QString serialize() {
        switch(this->type) {
            case Command::UnitMovement:
                return serializeMovement();
                break;
            case Command::UnitPosition:
                return serializePosition();
                break;
            case Command::PrivateChat:
            case Command::AllianceChat:
                return serializeChat();
                break;
        }
    }

    QString serializeMovement() {
        //type,x,y,z,x,y,z
        QString serial = QString("%1,%2,%3,%4,%5f,%6,%7").arg(this->type)
                .arg(this->pos.x(), 0, 'f', 3).arg(this->pos.y(), 0, 'f', 3)
                .arg(this->pos.z(), 0, 'f', 3).arg(this->dest.x(), 0, 'f', 3)
                .arg(this->dest.y(), 0, 'f', 3).arg(this->dest.z(), 0, 'f', 3);
        return serial;
    }

    QString serializePosition() {
        //type,x,y,z
        QString serial = QString("%1,%2,%3,%4").arg(this->type)
                .arg(this->pos.x()).arg(this->pos.y()).arg(this->pos.z());
        return serial;
    }

    QString serializeChat() {
        //type,sende,unixtime,message     message inside double quotes
        QString serial = QString("%1,%2,%3,%4").arg(this->type)
                 .arg(this->sender).arg(this->time.toTime_t()).arg(this->message);
        return serial;
    }

private:
    int type;
    QVector3D pos;
    QVector3D dest;
    QString sender;
    QDateTime time;
    QString message;

};

#endif // COMMAND_H
