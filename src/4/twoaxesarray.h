#ifndef TWOAXESARRAY_H
#define TWOAXESARRAY_H

#include <iostream>

using namespace std;

namespace arrays
{

    template<typename T> class TwoAxeArray
    {
    public:
        TwoAxeArray();
        TwoAxeArray(const unsigned int i, const unsigned int j);
        ~TwoAxeArray();

    private:
        inline void initarray(const unsigned int i, const unsigned int j);

        T* array;
        unsigned int rowsize, columnsize;
        unsigned int rownum, columnnum;

    };

    template<typename T>
    arrays::TwoAxeArray<T>::TwoAxeArray()
    {

    }

    template<typename T>
    arrays::TwoAxeArray<T>::TwoAxeArray(const unsigned int i, const unsigned int j)
    {

    }

    template<typename T>
    arrays::TwoAxeArray<T>::~TwoAxeArray()
    {

    }

    template<typename T>
    void TwoAxeArray<T>::initarray(const unsigned int i, const unsigned int j)
    {
        array = new T[i*j];
        rowsize = i;
        columnsize = j;
    }

}

#endif // TWOAXESARRAY_H
