#ifndef MULTILIST_H
#define MULTILIST_H

#include <iostream>


using namespace std;

namespace fourespace
{
    typedef enum
    {
        FORWARDWAY,
        BACKYARDWAY,
        OTHERWAY
    } WAYS;

    template<typename T> struct MultiWay
    {
        WAYS way;
        T *cell;
    };

    template<typename T> class MultiCell
    {
    public:
        MultiCell();
        MultiCell(const T &curtype);
        ~MultiCell();

        void setType(const T &curtype);
        T getType();

        void appendNext(MultiCell *point, WAYS *way);
        MultiCell<T> *getNextArr();
        void deleteNext(const unsigned int n, WAYS *way);

    private:
        T thistype;
        MultiWay<MultiCell<T>> ways[];
    };

    template<typename T> class MultiList
    {
    public:
        MultiList();
        MultiList(const unsigned int sz[]);
        ~MultiList();

    private:
       MultiCell<T> *heads;
       MultiCell<T> *ends;
       unsigned int *sizes;
       unsigned int *nums;
    };

    template<typename T>
    MultiList<T>::MultiList()
    {

    }

}

#endif // MULTILIST_H
