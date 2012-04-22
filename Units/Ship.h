#ifndef SHIP_H
#define SHIP_H
#include "Entity.h"
#include <QVariantMap>

class Ship : public Entity {

    Ship() {
        //this is false for trade ships!! set to false when subclassing for trade ship
        this->mobile = true;
    }

    ~Ship() {

    }

    void deserialize(QVariantMap data) {
        Entity::deserialize(data);
        //get shield and armor data here
    }

    void setShields(int shields) {
        this->shields = shields;
    }

    int getShields() {
        return this->shields;
    }

    void setArmor(int armor) {
        this->armor = armor;
    }

    int getArmor() {
        return this->armor;
    }


private:
    int shields;
    int armor;
};
#endif // SHIP_H
