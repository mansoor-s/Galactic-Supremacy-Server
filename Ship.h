#ifndef SHIP_H
#define SHIP_H

#include "Request.h"
#include "DatabasePool.h"
class Ship
{
public:
    Ship();

    static void movement(Request *req);
    static void setDatabasePool(DatabasePool *db) {
        Ship::db = db;
    }
    static DatabasePool *getDatabsePool() {
        return Ship::db;
    }

    static void move(Request *request);
    static void attack(Request *request);


private:
    static DatabasePool *db;
};

#endif // SHIP_H
