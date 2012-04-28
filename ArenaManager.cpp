#include "ArenaManager.h"

ArenaManager::ArenaManager() {
}

void ArenaManager::startArena(int id) {
    if(!this->arenas.contains(id)) {
        Arena *arena = new Arena(id);
        arena->load([this, id, arena](){
            this->arenas.insert(id, arena);
        });

    } else {
        //TODO: log error, arena already started
    }
}

void ArenaManager::shutdownArena(int id) {
    if(this->arenas.contains(id)) {
        Arena *arena = this->arenas.value(id);
        arena->shutdown([](bool success) {
            //TODO: arena shutdown log
            emit arena->deleteLater();
        });
    } else {
        //TODO: log error
    }
}
