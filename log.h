#ifndef LOG_H
#define LOG_H

//for now we use qdebug until something better is implemented
#include <QDebug>

class Log
{
public:
    Log();
    void log(QString val);
    void log(int val);
    void log(float val);
};

#endif // LOG_H
