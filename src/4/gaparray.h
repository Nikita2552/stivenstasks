#ifndef GAPARRAY_H
#define GAPARRAY_H

#include <iostream>
#include "oneaxearray.h"
#include "../3/thislist.h"

using namespace std;
using namespace fourespace;

namespace arrays
{
    /* Запись содержащая массив для аллокатора */

    template <typename T>
    class AllocEntry
    {
    public:
        AllocEntry();
        AllocEntry(const unsigned int s);
        ~AllocEntry();

        void initarray(const unsigned int s);

        void setNext(AllocEntry *n);
        AllocEntry *getNext();

        void setArray(T *n);
        T *getArray();

        void setBlock(const unsigned int i, const T &b);
        T *getBlock(const unsigned int i);

        unsigned int getSize();

        void printAll();

    private:
        T *array;
        unsigned int size;

        AllocEntry *Next;
    };

    template<typename T>
    AllocEntry<T>::AllocEntry()
    {
        initarray(0);
    }

    template<typename T>
    AllocEntry<T>::AllocEntry(const unsigned int s)
    {
        initarray(s);
    }

    template<typename T>
    AllocEntry<T>::~AllocEntry()
    {
        if (size)
            delete[] array;
    }

    template<typename T>
    void AllocEntry<T>::initarray(const unsigned int s)
    {
        size = s;
        array = new T[size];

        unsigned int i = 0;
        while (i < size)
        {
            array[i] = 0;
            i++;
        }

        Next = nullptr;
    }

    template<typename T>
    void AllocEntry<T>::setNext(AllocEntry *n)
    {
        Next = n;
    }

    template<typename T>
    AllocEntry<T> *AllocEntry<T>::getNext()
    {
        return Next;
    }

    template<typename T>
    void AllocEntry<T>::setArray(T *n)
    {
        delete array;
        array = n;
    }

    template<typename T>
    T *AllocEntry<T>::getArray()
    {
        return array;
    }

    template<typename T>
    void AllocEntry<T>::setBlock(const unsigned int i, const T &b)
    {
        array[i] = b;
    }

    template<typename T>
    T *AllocEntry<T>::getBlock(const unsigned int i)
    {
        return (array + i);
    }

    template<typename T>
    unsigned int AllocEntry<T>::getSize()
    {
        return size;
    }

    template<typename T>
    void AllocEntry<T>::printAll()
    {
        unsigned int i = 0;
        while (i < size)
        {
            cout << "AllocEntry array[" << i << "] = " << array[i] << endl;
            i++;
        }
    }

    /* Строка содержащая записи массивов */

    template <typename T>
    class AllocRow
    {
    public:
        AllocRow();
        AllocRow(const unsigned int s);
        ~AllocRow();

        void initrows(const unsigned int s);

        void appendEmptyArray(const unsigned int e);

        unsigned int getNum();
        void setNum(unsigned int n);
        void setArray(const unsigned int &ArrayNum, AllocEntry<T> *ArrayInfo);
        AllocEntry<T> *getArray(const unsigned int &ArrayNum);

        void setBlock(const unsigned int &ArrayNum, const unsigned int &BlockNum, const T &BlockInfo);
        T *getBlock(const unsigned int &ArrayNum, const unsigned int &BlockNum);

        void setRow(AllocRow<T> *currow);
        AllocRow<T> *getRow();

        unsigned int getSize();
        void setSize(unsigned int n);

        AllocEntry<T> *getHead();
        void setHead(AllocEntry<T> *point);

        AllocEntry<T> *getEnd();
        void setEnd(AllocEntry<T> *point);

        void deleteArray(const unsigned int &ArrayNum);

        void setNext(AllocRow *n);
        AllocRow *getNext();

    private:
        AllocEntry<T> *head;
        AllocEntry<T> *end;
        unsigned int size;        
        unsigned int num;

        AllocRow<T> *Next;

    };

    template<typename T>
    AllocRow<T>::AllocRow()
    {
        initrows(0);
    }

    template<typename T>
    AllocRow<T>::AllocRow(const unsigned int s)
    {
        initrows(s);
    }

    template<typename T>
    AllocRow<T>::~AllocRow()
    {
        unsigned int i = 0;
        AllocEntry<T> *prev = head;
        AllocEntry<T> *sen;
        while (i < num)
        {
            sen = prev;
            prev = prev->getNext();
            delete sen;
            i++;
        }
    }

    template<typename T>
    void AllocRow<T>::initrows(const unsigned int s)
    {
        head = new AllocEntry<T>(0);
        end = head;
        size = s;
        num = 0;
    }

    template<typename T>
    void AllocRow<T>::appendEmptyArray(const unsigned int e)
    {
        AllocEntry<T> *sen = end;
        AllocEntry<T> *cellEntry = new AllocEntry<T>(e);
        end->setNext(cellEntry);
        end = cellEntry;

        num++;
    }

    template<typename T>
    unsigned int AllocRow<T>::getNum()
    {
        return num;
    }

    template<typename T>
    void AllocRow<T>::setNum(unsigned int n)
    {
        num = n;
    }

    template<typename T>
    void AllocRow<T>::setArray(const unsigned int &ArrayNum, AllocEntry<T> *ArrayInfo)
    {
        if (ArrayNum < num)
        {
            unsigned int i = 0;
            AllocEntry<T> *sen = head->getNext();
            while (i < ArrayNum)
            {
                sen = sen->getNext();
                i++;
            }

            AllocEntry<T> *next = ArrayInfo;
            next->setNext(sen->getNext());

            sen->setArray(ArrayInfo->getArray());
        }
    }

    template<typename T>
    AllocEntry<T> *AllocRow<T>::getArray(const unsigned int &ArrayNum)
    {
        if (ArrayNum < num)
        {
            unsigned int i = 0;
            AllocEntry<T> *sen = head->getNext();
            while (i < ArrayNum)
            {
                sen = sen->getNext();
                i++;
            }

            return sen;
        }
        return nullptr;
    }

    template<typename T>
    void AllocRow<T>::setBlock(const unsigned int &ArrayNum, const unsigned int &BlockNum, const T &BlockInfo)
    {
        AllocEntry<T> *array = getArray(ArrayNum);

        array->setBlock(BlockNum, BlockInfo);
    }

    template<typename T>
    T *AllocRow<T>::getBlock(const unsigned int &ArrayNum, const unsigned int &BlockNum)
    {
        AllocEntry<T> *array = getArray(ArrayNum);

        return array->getBlock(BlockNum);
    }

    template<typename T>
    void AllocRow<T>::setRow(AllocRow<T> *currow)
    {
        *head = *currow->getHead();
        *end = *currow->getEnd();
        num = currow->getNum();
        size = currow->getSize();
    }

    template<typename T>
    AllocRow<T> *AllocRow<T>::getRow()
    {
        return this;
    }

    template<typename T>
    unsigned int AllocRow<T>::getSize()
    {
        return size;
    }

    template<typename T>
    void AllocRow<T>::setSize(unsigned int n)
    {
        size = n;
    }

    template<typename T>
    AllocEntry<T> *AllocRow<T>::getHead()
    {
        return head;
    }

    template<typename T>
    void AllocRow<T>::setHead(AllocEntry<T> *point)
    {
        head = point;
    }

    template<typename T>
    AllocEntry<T> *AllocRow<T>::getEnd()
    {
        return end;
    }

    template<typename T>
    void AllocRow<T>::setEnd(AllocEntry<T> *point)
    {
        end = point;
    }

    template<typename T>
    void AllocRow<T>::deleteArray(const unsigned int &ArrayNum)
    {
        if (ArrayNum < num)
        {
            unsigned int i = 0;
            AllocEntry<T> *prev = head;
            AllocEntry<T> *sen = prev->getNext();
            while (i < ArrayNum)
            {
                prev = prev->getNext();
                sen = sen->getNext();
                i++;
            }

            prev->setNext(sen->getNext());

            if (sen == end)
                end = prev;

            delete sen;
        }
    }

    template<typename T>
    void AllocRow<T>::setNext(AllocRow *n)
    {
        Next = n;
    }

    template<typename T>
    AllocRow<T> *AllocRow<T>::getNext()
    {
        return Next;
    }

    /* Список строк */

    template <typename T>
    class AllocRows
    {
    public:
        AllocRows();
        AllocRows(const unsigned int s, const unsigned int rs, const unsigned int bs);
        ~AllocRows();

        void initrows(const unsigned int s, const unsigned int rs, const unsigned int bs);

        void appendEmptyRow();
        void appendEmptyArray(const unsigned int &RowNum);

        unsigned int getNum();
        void setRow(const unsigned int &RowNum, AllocRow<T> *RowInfo);
        AllocRow<T> *getRow(const unsigned int &RowNum);

        void setArray(const unsigned int &RowNum, const unsigned int &ArrayNum, AllocEntry<T> *ArrayInfo);
        AllocEntry<T> *getArray(const unsigned int &RowNum, const unsigned int &ArrayNum);

        void setBlock(const unsigned int &RowNum, const unsigned int &ArrayNum, const unsigned int &BlockNum, const T &BlockInfo);
        T *getBlock(const unsigned int &RowNum, const unsigned int &ArrayNum, const unsigned int &BlockNum);

        void deleteArray(const unsigned int &RowNum, const unsigned int &ArrayNum);
        void deleteRow(const unsigned int &RowNum);

        T *searchArray(const unsigned int &index);

    private:
        AllocRow<T> *head;
        AllocRow<T> *end;
        unsigned int size;
        unsigned int rowsize;
        unsigned int blocksize;
        unsigned int num;

    };

    template<typename T>
    AllocRows<T>::AllocRows()
    {
        initrows(5, 5, 3);
    }

    template<typename T>
    AllocRows<T>::AllocRows(const unsigned int s, const unsigned int rs, const unsigned int bs)
    {
        initrows(s, rs, bs);
    }

    template<typename T>
    AllocRows<T>::~AllocRows()
    {
        unsigned int i = 0;
        AllocRow<T> *prev = head;
        AllocRow<T> *sen;
        while (i < num)
        {
            sen = prev;
            prev = prev->getNext();
            delete sen;
            i++;
        }
    }

    template<typename T>
    void AllocRows<T>::initrows(const unsigned int s, const unsigned int rs, const unsigned int bs)
    {
        head = new AllocRow<T>(0);
        end = head;
        size = s;
        rowsize = rs;
        blocksize = bs;
        num = 0;
    }

    template<typename T>
    void AllocRows<T>::appendEmptyRow()
    {
        AllocRow<T> *sen = end;
        AllocRow<T> *cellRow = new AllocRow<T>(rowsize);
        end->setNext(cellRow);
        end = cellRow;

        num++;
    }

    template<typename T>
    void AllocRows<T>::appendEmptyArray(const unsigned int &RowNum)
    {
        AllocRow<T> *sen = getRow(RowNum);
        sen->appendEmptyArray(blocksize);
    }

    template<typename T>
    unsigned int AllocRows<T>::getNum()
    {
        return num;
    }

    template<typename T>
    void AllocRows<T>::setRow(const unsigned int &RowNum, AllocRow<T> *RowInfo)
    {
        if ((RowNum < num) && (RowInfo->getSize() == rowsize))
        {
            unsigned int i = 0;
            AllocRow<T> *sen = head->getNext();
            while (i < RowNum)
            {
                sen = sen->getNext();
                i++;
            }

            AllocRow<T> *next = RowInfo;
            next->setNext(sen->getNext());

            sen->setRow(RowInfo->getRow());
        }
    }

    template<typename T>
    AllocRow<T> *AllocRows<T>::getRow(const unsigned int &RowNum)
    {
        if (RowNum < num)
        {
            unsigned int i = 0;
            AllocRow<T> *sen = head->getNext();
            while (i < RowNum)
            {
                sen = sen->getNext();
                i++;
            }

            return sen;
        }
        return nullptr;
    }

    template<typename T>
    void AllocRows<T>::setArray(const unsigned int &RowNum, const unsigned int &ArrayNum, AllocEntry<T> *ArrayInfo)
    {
        AllocRow<T> *row = getRow(RowNum);

        if ((row) && (ArrayInfo->getSize() == blocksize))
            row->setArray(ArrayNum, ArrayInfo);
    }

    template<typename T>
    AllocEntry<T> *AllocRows<T>::getArray(const unsigned int &RowNum, const unsigned int &ArrayNum)
    {
        AllocRow<T> *row = getRow(RowNum);

        if (row)
            return row->getArray(ArrayNum);
        else
            return nullptr;
    }

    template<typename T>
    void AllocRows<T>::setBlock(const unsigned int &RowNum, const unsigned int &ArrayNum, const unsigned int &BlockNum, const T &BlockInfo)
    {
        AllocEntry<T> *entry = getArray(RowNum, ArrayNum);

        if (entry)
            entry->setBlock(BlockNum, BlockInfo);
    }

    template<typename T>
    T *AllocRows<T>::getBlock(const unsigned int &RowNum, const unsigned int &ArrayNum, const unsigned int &BlockNum)
    {
        AllocEntry<T> *entry = getArray(RowNum, ArrayNum);

        if (entry)
            return entry->getBlock(BlockNum);
        else
            return nullptr;
    }

    template<typename T>
    void AllocRows<T>::deleteArray(const unsigned int &RowNum, const unsigned int &ArrayNum)
    {        
        AllocRow<T> *row = getRow(RowNum);

        if (row)
            row->deleteArray(ArrayNum);
    }

    template<typename T>
    void AllocRows<T>::deleteRow(const unsigned int &RowNum)
    {
        AllocRow<T> *row = getRow(RowNum);

        if (row)
        {
            AllocRow<T> *prevrow = head;
            while (prevrow->getNext() != row)
                prevrow = prevrow->getNext();

            prevrow->setNext(row->getNext());

            if(row == end)
                end = prevrow;

            delete row;
        }
    }

    template<typename T>
    T *AllocRows<T>::searchArray(const unsigned int &index)
    {
        if (index < blocksize*rowsize*size)
        {
            unsigned int indexblock = index/blocksize;
            unsigned int indexblockdelta = index - indexblock*blocksize;

            unsigned int indexrow = indexblock/rowsize;
            unsigned int indexrowdelta = indexblock - indexrow*rowsize;

            unsigned int indexrows = indexrow/size;
            unsigned int indexrowsdelta = indexrow - indexrows*size;

            return getBlock(indexrowsdelta, indexrowdelta, indexblockdelta);
        }
        return nullptr;
    }
}

#endif // GAPARRAY_H
