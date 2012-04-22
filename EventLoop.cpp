#include "EventLoop.h"

EventLoop::EventLoop(QObject *parent = 0)
    : QObject(parent)
{
    timer = new QTimer();
    timer->setInterval(250);
    connect(timer, SIGNAL(timeout()), this, SLOT(loop()));
}

void EventLoop::start() {
    /*
        load system state from DB before starting event loop
        including task queues
     */
    this->timer->start();
}

void EventLoop::stop() {

    /*
        save system state to DB before stoping.
        including task queues
     */
    this->timer->stop();
}


void EventLoop::loop() {
    //this->dbPool->getUserId("dfsdfdsdf", EventLoop::someFunction);
}

