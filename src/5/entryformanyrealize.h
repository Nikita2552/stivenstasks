#ifndef ENTRYFORMANYREALIZE_H
#define ENTRYFORMANYREALIZE_H

#include <iostream>

using namespace std;


namespace sixchapter
{

    template<typename T>
    class Entry
    {
    public:
        Entry();
        Entry(const T& ipoint);
        ~Entry();

        Entry<T>* getNext();
        void setNext(Entry<T>* npoint);

        T* getInfo();
        void setInfo(T* ipoint);
    private:
        Entry<T>* next;
        T info;
    };

    template<typename T>
    Entry<T>::Entry()
    {
        next = nullptr;
    }

    template<typename T>
    Entry<T>::Entry(const T& ipoint)
    {
        info = ipoint;
        next = nullptr;
    }

    template<typename T>
    Entry<T>::~Entry()
    {

    }

    template<typename T>
    Entry<T> *Entry<T>::getNext()
    {
        return next;
    }

    template<typename T>
    void Entry<T>::setNext(Entry<T> *npoint)
    {
        next = npoint;
    }

    template<typename T>
    T *Entry<T>::getInfo()
    {
        return &info;
    }

    template<typename T>
    void Entry<T>::setInfo(T *ipoint)
    {
        info = ipoint;
    }
}

#endif // ENTRYFORMANYREALIZE_H
