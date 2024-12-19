#ifndef TWOSIDETwoSideArraySTACK_H
#define TWOSIDETwoSideArraySTACK_H

#include <iostream>
#include <cinttypes>
#include "entryformanyrealize.h"


using namespace std;
using namespace sixchapter;

namespace sixchapter
{

    template<typename T>
    class StackTwoSideArray
    {
    public:
        StackTwoSideArray();
        StackTwoSideArray(const uint &esize);
        ~StackTwoSideArray();

        void initstruct(const uint &esize);

        void push1(const T &info);
        T pop1();

        void push2(const T &info);
        T pop2();

        unsigned int getsize();
        unsigned int getforwardnum();
        unsigned int getbackyardnum();

        void printall();
    private:
        T* head;
        unsigned int forwardnum;
        unsigned int backyardnum;
        unsigned int size;
    };

    template<typename T>
    StackTwoSideArray<T>::StackTwoSideArray()
    {
        initstruct(5);
    }

    template<typename T>
    StackTwoSideArray<T>::StackTwoSideArray(const uint &esize)
    {
        initstruct(esize);
    }

    template<typename T>
    StackTwoSideArray<T>::~StackTwoSideArray()
    {
        delete head;
    }

    template<typename T>
    void StackTwoSideArray<T>::initstruct(const uint &esize)
    {
        head = new T[esize*2];
        forwardnum = 0;
        backyardnum = esize*2 - 1;
        size = esize;
    }

    template<typename T>
    void StackTwoSideArray<T>::push1(const T &info)
    {
        if (forwardnum < size)
        {
            head[forwardnum] = info;
            forwardnum++;
         }
    }

    template<typename T>
    T StackTwoSideArray<T>::pop1()
    {
        if (size)
        {
            --forwardnum;
            T entry = head[forwardnum];
            head[forwardnum] = 0;
            return entry;
        }
        return 0;
    }

    template<typename T>
    void StackTwoSideArray<T>::push2(const T &info)
    {
        if ((backyardnum < size*2) && (backyardnum >= size))
        {
            head[backyardnum] = info;
            backyardnum--;
         }
    }

    template<typename T>
    T StackTwoSideArray<T>::pop2()
    {
        if (size)
        {
            ++backyardnum;
            T entry = head[backyardnum];
            head[backyardnum] = 0;
            return entry;
        }
        return 0;
    }

    template<typename T>
    unsigned int StackTwoSideArray<T>::getsize()
    {
        return size;
    }

    template<typename T>
    unsigned int StackTwoSideArray<T>::getforwardnum()
    {
        return forwardnum;
    }

    template<typename T>
    unsigned int StackTwoSideArray<T>::getbackyardnum()
    {
        return backyardnum;
    }

    template<typename T>
    void StackTwoSideArray<T>::printall()
    {
        unsigned int i = 0;
        while(i < size*2)
        {
            cout << "TwoSideArraystack[" << i << "] = " << head[i] << endl;
            i++;
        }
    }
}

#endif // TWOSIDETwoSideArraySTACK_H
