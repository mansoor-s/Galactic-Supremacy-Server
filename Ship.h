#ifndef SHIP_H
#define SHIP_H
#include "Request.h"

class Ship
{
public:
    Ship();

    static void movement(Request *req);
};

#endif // SHIP_H
