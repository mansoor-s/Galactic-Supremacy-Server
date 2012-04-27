/*
    Note:
    Arena extends QObject so that it can take advantage of Qt's scheduled object deletion mech.
    It will reduce complexity as the arena object needs to perform async IO (persisting to DB) before being deleted
*/
#ifndef ARENA_H
#define ARENA_H
#include <QObject>
#include <QList>
#include "Request.h"
#include <qt/qvector3d.h>
#include "Units/Entity.h"

class UnitMove {

private:
    QVector3D location;
};


class UnitAttack {

private:
    Entity target;
};


class Arena : public QObject {
    Q_OBJECT
public:
    Arena() {}
    ~Arena() {}

    //non-blocking method
    void shutdown();

private:
    QList<Request*> requests;
};
#endif // ARENA_H
