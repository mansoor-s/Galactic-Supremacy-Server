/*
    Class manages the Arenas being processed by this process
*/
#ifndef ARENAMANAGER_H
#define ARENAMANAGER_H
#include "Arena.h"
#include <QMap>
#include "Flow.h"

class ArenaManager
{
public:
    ArenaManager();
    //load up and schedule arena
    void startArena(int id);
    //shut down arena and save state to DB
    void shutdownArena(int id);

private:
    QMap<int, Arena*> arenas;
};

#endif // ARENAMANAGER_H
