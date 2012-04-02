#ifndef EVENTLOOP_H
#define EVENTLOOP_H
#include <QObject>
#include <QTimer>

class EventLoop : public QObject{
    Q_OBJECT
public:
    EventLoop(QObject *parent);

public slots:
    void loop();
    void start();
    void stop();

private:
    QTimer *timer;
};

#endif // EVENTLOOP_H
