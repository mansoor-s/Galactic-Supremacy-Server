#include "EventLoop.h"

EventLoop::EventLoop(QObject *parent = 0)
    : QObject(parent)
{
    timer = new QTimer();
    timer->setInterval(250);
    connect(timer, SIGNAL(timeout()), this, SLOT(loop()));
}

void EventLoop::start() {
    this->timer->start();
}

void EventLoop::stop() {
    this->timer->stop();
}




void EventLoop::loop() {

}

