#ifndef FLOW_H
#define FLOW_H

#include <QList>
/**
    Class handles flow control for async DB calls


*/
class Flow
{
    typedef void (*Function)();

    typedef void (*InnerCallback)(int);//this defines a type for the lambda that we are going to pass in
                                // to intercept the results

    // defines type for the async function
    typedef void (*Callback)(InnerCallback);
    //defines type for final callback function which will take array of results for all of the async calls
    typedef void (*ResultFn)(QList<int>);

public:
    Flow() {}

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
