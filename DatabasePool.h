#ifndef DATABASEPOOL_H
#define DATABASEPOOL_H

#include <QList>
#include <QThread>
#include "DBWorker.h"

class DatabasePool
{
public:
    typedef void (*Callback)(mongo::BSONObj obj);

    struct DBContainer {
        QThread *thread;
        DBWorker *worker;
        bool isAvailable;
        Callback callback;
    };

    DatabasePool(const char* host);

private:
    QList<DBContainer*> *dbs;
    //QList<

public slots:

    void finished(DBContainer* container, mongo::BSONObj obj);



};

#endif // DATABASEPOOL_H
