#include "log.h"

Log::Log()
{
}


void Log::log(QString val)
{
    qDebug() << val;
}

void Log::log(int val)
{
    qDebug() << val;
}

void Log::log(float val)
{
    qDebug() << val;
}
