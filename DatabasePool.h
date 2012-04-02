#ifndef DATABASEPOOL_H
#define DATABASEPOOL_H

#include <QList>
#include "Database.h"

class DatabasePool
{
public:
    struct DBContainer {
        Database *db;
        bool isAvailable;
    };

    DatabasePool(const char* host);

private:
    QList<DBContainer*> *dbs;
};

#endif // DATABASEPOOL_H
