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
        QString serial = "";
        //type,x,y,z,x,y,z
        serial.sprintf("%d,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f", this->type,
                       this->pos.x(), this->pos.y(), this->pos.z(),
                       this->dest.x(), this->dest.y(), this->dest.z());
        return serial;
    }

    QString serializePosition() {
        QString serial = "";
        //type,x,y,z
        serial.sprintf("%d,%.3f,%.3f,%.3f", this->type,
                       this->pos.x(), this->pos.y(), this->pos.z());
        return serial;
    }

    QString serializeChat() {
        QString serial = "";
        //type,sende,unixtime,message     message inside double quotes
        serial.sprintf("%d,%s,%d,\"%s\"", this->type,
                       this->sender, this->time.toTime_t(), this->message);
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
