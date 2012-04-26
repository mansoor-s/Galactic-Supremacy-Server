#ifndef SYSTEM_H
#define SYSTEM_H
/*
    Represents the current state of the star system
 */

#include <QList>
#include <Entity.h>

class System {

    System() {}
    ~System() {}

    void setEntities(QList<Entity*> entities) {
        this->entities = entities;
    }

    QList<Entity*> getEntities() {
        return this->entities;
    }

private:
    //holds refrence to all entities... ships, planets, moons etc
    QList<Entity*> entities;
    //holds refrence only to ships
    QList<Entity*> ships;
    //holds refrence to all of the planets
    QList<Entity*> planets;
    //holds refrence to all of the moons
    QList<Entity*> moons;
};

#endif // SYSTEM_H
