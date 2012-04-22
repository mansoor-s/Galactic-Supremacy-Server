#ifndef DATABASE_H
#define DATABASE_H

#include <functional>
#include <QString>
#include <QNetworkAccessManager>

class Database {
public:
    struct Reply {
        int status;
        QString ETag;
    };
    typedef std::function<void*> Callback;

    Database();
};

#endif // DATABASE_H
