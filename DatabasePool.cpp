#include "DatabasePool.h"

DatabasePool::DatabasePool(const char* host) {

    this->dbs = new QList<DBContainer*>();
    //create DB pool
    for(int i = 0; i < 2; ++i) {
        DBWorker *worker = new DBWorker();
        QThread *thread = new QThread();
        worker->moveToThread(thread);

        DBContainer *container = new DBContainer;
    }
}


void DatabasePool::finished(DBContainer* container, mongo::BSONObj obj) {
    container->isAvailable = true;
    //container->
}
