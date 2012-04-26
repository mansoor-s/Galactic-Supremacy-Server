#ifndef ARENA_H
#define ARENA_H
#include <QList>
#include "Request.h"
#include <qt/qvector3d.h>
#include "Entity.h"

class UnitMove {

private:
    QVector3D location;
};


class UnitAttack {

private:
    Entity target;
};


class Arena {
public:
    Arena() {}
    ~Arena() {}

private:
    QList<Request*> requests;
};
#endif // ARENA_H
