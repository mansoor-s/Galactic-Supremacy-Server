#ifndef EVENTLOOP_H
#define EVENTLOOP_H
#include <QObject>
#include <QTimer>
#include <DatabasePool.h>

class EventLoop : public QObject{
    Q_OBJECT
public:
    EventLoop(DatabasePool* pool, QObject *parent);

public slots:
    void loop();
    void start();
    void stop();

private:
    QTimer *timer;
    DatabasePool *dbPool;
};

#endif // EVENTLOOP_H
