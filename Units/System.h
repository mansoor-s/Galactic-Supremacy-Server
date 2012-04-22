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

    void setEntities(QList<Entity> entities) {
        this->entities = entities;
    }

    QList<Entity> getEntities() {
        return this->entities;
    }

private:
    QList<Entity> entities;
};

#endif // SYSTEM_H
