#ifndef INTERFACESFORSIX_H
#define INTERFACESFORSIX_H

#include <iostream>
#include <cinttypes>

using namespace std;

namespace sixchapter
{
    template <typename T>
    class entryinterface
    {
    public:
        virtual entryinterface<T>* getNext();
        virtual void setNext(entryinterface<T>* npoint);

        virtual T* getInfo();
        virtual void setInfo(T* ipoint);
    };

    template <typename T>
    class stackinterface
    {
    public:
        virtual void push(const T &info);
        virtual T pop();

        virtual uint getsize();
        virtual uint getnum();

    };
}

#endif // INTERFACESFORSIX_H
