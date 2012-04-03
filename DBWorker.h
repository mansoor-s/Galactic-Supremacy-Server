#ifndef DBWORKER_H
#define DBWORKER_H

#include <QObject>
#include <QString>
#include "Database.h"
#include <mongo/client/dbclient.h>
#include <mongo/bson/bson.h>


class DBWorker : public QObject
{
    Q_OBJECT
public:
    DBWorker(QObject *parent = 0);
    ~DBWorker();

private:
    mongo::DBClientConnection *connection;
signals:
    void ready();
    
public slots:
    void getUserId(Database *db, QString sessionId);
    
};

#endif // DBWORKER_H
