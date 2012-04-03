#include "DBWorker.h"

DBWorker::DBWorker(QObject *parent) :
    QObject(parent)
{
    this->connection = new mongo::DBClientConnection();
    this->connection->connect("localhost");
}
DBWorker::~DBWorker() {
    delete this->connection;
}

//void DBWorker::getUserId(Database *db, QString sessionId) {
//}
