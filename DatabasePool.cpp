#include "DatabasePool.h"

DatabasePool::DatabasePool(const char* host) {
    this->dbs = new QList<DBContainer*>();
    //create DB pool
    for(int i = 0; i < 2; ++i) {
        Database *db = new Database();
        db->connect(host);
        DBContainer *container = new DBContainer;
        container->db = db;
        container->isAvailable = true;
        this->dbs->append(container);
    }
}
