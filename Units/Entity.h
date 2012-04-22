#ifndef ENTITY_H
#define ENTITY_H

#include <Qt/qvector3d.h>
#include <QString>
#include <QVariantMap>

class Entity {

    Entity() {
        this->mobile = false;
    }

    ~Entity() {

    }

    virtual QVariantMap serialize();
    virtual void deserialize(QVariantMap data);

    QVector3D getPosition() {
        return this->position;
    }

    void setPosition(QVector3D pos) {
        this->position = pos;
    }

    QVector3D getDestination() {
        return this->destination;
    }

    void setDestination(QVector3D pos) {
        this->destination = pos;
    }

    int getVelocity() {
        return this->velocity;
    }

    void setVelocity(int vel) {
        this->velocity = vel;
    }

    QString getOwner() {
        return this->owner;
    }

    void setOwner(QString owner) {
        this->owner = owner;
    }

private:
    QVector3D position;
    int velocity;
    QVector3D destination;
    QString owner;
    bool mobile;
};
#endif // ENTITY_H
