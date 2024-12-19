#ifndef ONEAXEARRAY_H
#define ONEAXEARRAY_H

#include <iostream>


using namespace std;

namespace arrays
{

    template<typename T> class OneAxeArray
    {
    public:
        OneAxeArray();
        OneAxeArray(const unsigned int i);
        ~OneAxeArray();

        bool append(const T &info);
        T *getElement(const unsigned int i);
        void setElement(const unsigned int i, const T &info);
        void insertElement(const unsigned int i, const T &info);
        void deleteElement(const unsigned int i);

        void printAll();

        T getMax();
        T getMin();
        T getAverage();
        T getMedian();

    private:
        inline void initarray(const unsigned int i);

        T* array;
        unsigned int size;
        unsigned int num;

    };

    template<typename T>
    OneAxeArray<T>::OneAxeArray()
    {
        initarray(5);
    }

    template<typename T>
    OneAxeArray<T>::OneAxeArray(const unsigned int i)
    {
        initarray(i);
    }

    template<typename T>
    OneAxeArray<T>::~OneAxeArray()
    {
        delete[] array;
    }

    template<typename T>
    bool OneAxeArray<T>::append(const T &info)
    {
        if (num == size)
            return false;

        array[num] = info;
        num++;
        return true;
    }

    template<typename T>
    T *OneAxeArray<T>::getElement(const unsigned int i)
    {
        if (i >= num)
            return nullptr;

        return (array+i);
    }

    template<typename T>
    void OneAxeArray<T>::setElement(const unsigned int i, const T &info)
    {
        if (i >= num)
            *(array+i) = info;
    }

    template<typename T>
    void OneAxeArray<T>::insertElement(const unsigned int i, const T &info)
    {
        if (num >= size)
            return;

        for (unsigned int j = num-1; j >= i; j--)
            *(array+j+1) = *(array+j);

        *(array+i) = info;

        printAll();
    }

    template<typename T>
    void OneAxeArray<T>::deleteElement(const unsigned int i)
    {

    }

    template<typename T>
    void OneAxeArray<T>::printAll()
    {
        for (unsigned int i = 0; i < num; i++)
            cout << "array[" << i << "]=" << array[i] << endl;
    }

    template<typename T>
    T OneAxeArray<T>::getMax()
    {
        if (!num)
            return NULL;

        T max = array[0];
        for (unsigned int i = 0; i < num; i++)
        {
            if (max < array[i])
                max = array[i];
        }
        return max;
    }

    template<typename T>
    T OneAxeArray<T>::getMin()
    {
        if (!num)
            return NULL;

        T min = array[0];
        for (unsigned int i = 0; i < num; i++)
        {
            if (min > array[i])
                min = array[i];
        }
        return min;
    }

    template<typename T>
    T OneAxeArray<T>::getAverage()
    {
        if (!num)
            return NULL;

        T total = array[0];
        for (unsigned int i = 0; i < num; i++)
        {
            total += array[i];
        }
        return total/num;
    }

    template<typename T>
    T OneAxeArray<T>::getMedian()
    {
        if (!num)
            return NULL;

        for (unsigned int i = 0; i < num; i++)
        {
            unsigned int num_larger = 0;
            unsigned int num_smaller = 0;

            for (unsigned int j = 0; j < num; j++)
            {
                if (array[i] > array[j]) num_larger++;
                else if (array[i] < array[j]) num_smaller++;
            }

            if (num_larger == num_smaller) return array[i];
        }
        return NULL;
    }

    template<typename T>
    void OneAxeArray<T>::initarray(const unsigned int i)
    {
        array = new T[i];
        size = i;
    }
}

#endif // ONEAXEARRAY_H
