#include <QtCore/QCoreApplication>
#include "Server.h"
#include "log.h"

#include "Chat.h"

#define DB_HOST "localhost"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    Log *log = new Log();

    Server *server = new Server(log);

    return a.exec();
}
