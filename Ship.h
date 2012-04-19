#ifndef SHIP_H
#define SHIP_H

#include "Request.h"
class Ship
{
public:
    Ship();

    static void movement(Request *req);
    static void move(Request *request);
    static void attack(Request *request);


private:
};

#endif // SHIP_H
