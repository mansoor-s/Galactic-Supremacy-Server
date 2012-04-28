/*
    Note:
    Arena extends QObject so that it can take advantage of Qt's scheduled object deletion mech.
    It will reduce complexity as the arena object needs to perform async IO (persisting to DB) before being deleted
*/
#ifndef ARENA_H
#define ARENA_H
#include <QObject>
#include <QList>
#include <QQueue>
#include "Request.h"
#include <QVector>
#include "Units/Entity.h"
#include <functional>

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
    Arena(int id) {
        this->id = id;

    }
    ~Arena() {}

    int getId() {
        return this->id;
    }

    //non-blocking method
    void shutdown(std::function<void(bool)> fn) {
        //call callback when finished saving state to DB
        fn(true);
    }

    //non blocking method
    void load(std::function<void(bool)> fn) {
        //load assets from Db

        fn(true);
    }

private:
    QList<Request*> turnRequests;
    QQueue<Request*> requestsNotFinished;
    int id;
};
#endif // ARENA_H
