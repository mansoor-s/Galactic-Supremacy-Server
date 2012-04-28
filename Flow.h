#ifndef FLOW_H
#define FLOW_H

#include <QList>
#include <functional>
/**
    Class handles flow control for async DB calls


*/
typedef std::function<void(QList<void*>)> Fn;
typedef std::function<void(bool)> Callback;
class Flow {

public:

    Flow() {}
/*
    void parallel(QList<Fn> fnList, Callback callback) {
        int count = fnList.count();
        int curr = 0;
        QList<void*> results;
        Fn func;
        foreach(func, fnList) {
            auto innerCallback = [&curr, count, callback, &results](void* result) {
                curr++;
                results.push_back(result);

            };

            //func(innerCallback);
        }
    }*/

    /*
    void parallel(QList<Callback> fnList, ResultFn func) {
        int count = fnList.count();
        int currCount = 0;

        for (int i = 0, len = fnList.count(); i < len; ++i) {
            Callback fn = this->fnList.at(i);
            //just execute the function.
            //it will emit an event to execute the actual function in a seperate thread
            //it will then call the

            fn([](int result) {
                results.append(result);
                currCount++;
                if(currCount == count) {
                    ResultFn func = self->resultFunc;
                    func(results)
                }
            });
        }
    }


    void serial(QList<Callback> fnList, ResultFn func) {
        int count = fnList.count();

        if (count < 1) {
            QList<int> q;
            func(q);
            return;
        }
        QList<int> results;

        //use recursion to achieve serial execution
        Function lam = [](curr) {
            Callback fn = fnList.at(curr);

            fn([](int result) {
                results.append(result);
                if (curr == count) {
                    //we are done
                    func(results)
                } else {
                    lam(++curr);
                }
            });
        };
    }
*/
};

#endif // FLOW_H


/*

//USAGE:

typedef void (*func)();
typedef void (*ResultCatcher)(QList<int>);
typedef void (*Callback)(InnerCallback);

Flow flow;
QList<func> functions;
for(int i = 0; i < 20; ++i) {
    functions.append([](Callback fn){
        //DO SOMETHING ASYYYNC!!
        SomeLib::DoSomethingAsync(fn);
    });

    flow.parallel(functions, []() {
        //if we get here we are all done!!!!
        qDebug() << "WOOT WOOOOt!!";
    });

    flow.init();

}





*/
