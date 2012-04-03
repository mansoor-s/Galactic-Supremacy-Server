#include "EventLoop.h"

EventLoop::EventLoop(DatabasePool* pool, QObject *parent = 0)
    : QObject(parent)
{
    timer = new QTimer();
    timer->setInterval(250);
    connect(timer, SIGNAL(timeout()), this, SLOT(loop()));
    this->dbPool = pool;
}

void EventLoop::start() {
    this->timer->start();
}

void EventLoop::stop() {
    this->timer->stop();
}


void EventLoop::loop() {
    //this->dbPool->getUserId("dfsdfdsdf", EventLoop::someFunction);
}

