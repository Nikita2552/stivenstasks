#ifndef SIMPLEARRAY_H
#define SIMPLEARRAY_H

#include <iostream>
#include <time.h>

using namespace std;

template<typename T>
class simpleArray
{
public:
    simpleArray(unsigned int s = 10);
    ~simpleArray();

    void print();
    void randomset();

    bool searchLinear(T& se);
    bool searchBipolar(T& se);
    bool searchInterpolar(T& se);

private:
    T *head;
    unsigned int size;
};


template<typename T>
simpleArray<T>::simpleArray(unsigned int s): size(s)
{
    head = new T[size];
}

template<typename T>
simpleArray<T>::~simpleArray()
{
    delete[] head;
}

template<typename T>
void simpleArray<T>::print()
{
    for (int i = 0; i < size; i++)
    {
        cout << "array[" << i << "] = " << head[i] << ";" << endl;
    }
}

template<typename T> //requires is_same<T, int>::value || is_same<T, float>::value || is_same<T, double>::value
void simpleArray<T>::randomset()
{
    int start = 0;
    int end = 100;

    srand(time(0));

    for (int i = 0; i < size; i++)
    {
        head[i] = (T) rand() % (end - start + 1) + start;
    }
}

template<typename T>
bool simpleArray<T>::searchLinear(T &se)
{
    for (int i = 0; i < size; i++)
    {
        if (head[i] == se)
        {
            return true;
        }
    }
    return false;
}

template<typename T>
bool simpleArray<T>::searchBipolar(T &se)
{
    unsigned int min = 0;
    unsigned int max = size - 1;

    while (min <= max)
    {
        int mid = (mid + max) / 2;

        if (se < head[mid]) max = mid - 1;
        else if (se > head[mid]) min = mid + 1;
        else return true;
    }
    return false;
}

template<typename T>
bool simpleArray<T>::searchInterpolar(T &se)
{
    unsigned int min = 0;
    unsigned int max = size - 1;

    while (min <= max)
    {
        int mid = min + (max - min) *
                (se - head[min]) / (head[max] - head[min]);

        if (head[mid] == se) return true;
    }
    return false;
}

#endif // SIMPLEARRAY_H
