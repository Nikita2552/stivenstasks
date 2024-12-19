#ifndef LISTSTACK_H
#define LISTSTACK_H

#include <iostream>
#include <cinttypes>
#include "entryformanyrealize.h"


using namespace std;
using namespace sixchapter;

namespace sixchapter
{

    template<typename T>
    class StackList
    {
    public:
        StackList();
        StackList(const uint &esize);
        ~StackList();

        void initstruct(const uint &esize);

        void push(const T &info);
        T pop();

        uint getsize();
        uint getnum();
    private:
        Entry<T>* head;
        uint num;
        uint size;
    };

    template<typename T>
    StackList<T>::StackList()
    {
        initstruct(5);
    }

    template<typename T>
    StackList<T>::StackList(const uint &esize)
    {
        initstruct(esize);
    }

    template<typename T>
    StackList<T>::~StackList()
    {
        unsigned int i = 0;
        Entry<T> *prev = head;
        Entry<T> *sen;
        while (i < num)
        {
            sen = prev;
            prev = prev->getNext();
            delete sen;
            i++;
        }
    }

    template<typename T>
    void StackList<T>::initstruct(const uint &esize)
    {
        head = new Entry<T>();
        num = 0;
        size = esize;
    }

    template<typename T>
    void StackList<T>::push(const T &info)
    {
        if (num < size)
        {
            Entry<T>* entry = new Entry<T>(info);
            entry->setNext(head);
            head = entry;
            num++;
         }
    }

    template<typename T>
    T StackList<T>::pop()
    {
        if (size)
        {
            Entry<T>* entry = head;
            head = entry->getNext();
            T info = *entry->getInfo();
            delete entry;

            return info;
        }
        return *head->getInfo();
    }

    template<typename T>
    uint StackList<T>::getsize()
    {
        return size;
    }

    template<typename T>
    uint StackList<T>::getnum()
    {
        return num;
    }
}

#endif // LISTSTACK_H
