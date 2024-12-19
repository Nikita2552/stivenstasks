#ifndef MANYAXESARRAY_H
#define MANYAXESARRAY_H

#include <iostream>

using namespace std;

namespace arrays
{

    template<typename T> class ManyAxesArray
    {
    public:
        ManyAxesArray();
        ManyAxesArray(const unsigned int i, const unsigned int j);
        ~ManyAxesArray();

    private:
        inline void initarray(const unsigned int i, const unsigned int j);

        T* array;
        unsigned int rowsize, columnsize;
        unsigned int rownum, columnnum;

    };
};

#endif // MANYAXESARRAY_H
