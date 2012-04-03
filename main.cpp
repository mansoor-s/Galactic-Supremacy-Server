#include <QtCore/QCoreApplication>
#include "DatabasePool.h"
#include "Server.h"
#include "log.h"
#include "Ship.h"
#include "Flow.h"
#include "Chat.h"

#define DB_HOST "localhost"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    Log *log = new Log();

    DatabasePool *db = new DatabasePool(DB_HOST);
    //Ship::setDatabasePool(db);

    Server *server = new Server(db, log);

    return a.exec();
}
