#ifndef DATABASE_H
#define DATABASE_H
#include "mongo/client/dbclient.h"

class Database : public mongo::DBClientConnection
{
public:
    typedef void (*cursorCallback)(mongo::DBClientCursor cursor);
    typedef void (*callback)();

    Database(bool _autoReconnect = false, mongo::DBClientReplicaSet *cp = 0, double so_timeout = 0)
        : mongo::DBClientConnection(_autoReconnect, cp, so_timeout){}

    void setCursorCallback(cursorCallback cursorFn) {
        this->cursorFn = cursorFn;
    }

    cursorCallback getCursorCallback() {
        return this->cursorFn;
    }

    void setCallback(callback fn) {
        this->fn = fn;
    }

private:
    cursorCallback cursorFn;
    callback fn;
};

#endif // DATABASE_H
