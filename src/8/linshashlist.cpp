#include "linshashlist.h"

linShashList::linShashList(unsigned int ts, PROBS pr): table_size(ts), prob(pr)
{
    array.resize(table_size, nullopt);
}

linShashList::~linShashList()
{

}

void linShashList::appendElement(unsigned int key)
{
    unsigned int index = 0;
    unsigned int attempt = 0;

    if (prob != DOUBLEHASH)
        index = hashing(key);
    else
        index = doublehashing(key, attempt);

    while((attempt < 3) && (array[index].has_value()))
    {
        if (prob == LIN)
            index = linprob(index);
        else if (prob == QUAD)
            index = quadprob(index, attempt);
        else if(prob == RAD)
            index = radprob(index);
        if (prob == DOUBLEHASH)
            index = doublehashing(index, attempt);

        attempt++;
    }

    if (!array[index].has_value())
        array[index] = key;
    else
        cout << "array is full" << endl;
}

void linShashList::removeElement(unsigned int key)
{
    unsigned int index = 0;
    unsigned int attempt = 0;

    if (prob != DOUBLEHASH)
        index = hashing(key);
    else
        index = doublehashing(key, attempt);

    while((attempt < 3) && (array[index].value() != key))
    {
        if (prob == LIN)
            index = linprob(index);
        else if (prob == QUAD)
            index = quadprob(index, attempt);
        else if(prob == RAD)
            index = radprob(index);
        if (prob == DOUBLEHASH)
            index = doublehashing(index, attempt);

        attempt++;
    }

    if (array[index].value() == key)
    {
        array[index] = nullopt;
    }
    else
    {
        cout << "array is not remove" << endl;
    }
}

bool linShashList::searchElement(unsigned int key)
{
    unsigned int index = 0;
    unsigned int attempt = 0;

    if (prob != DOUBLEHASH)
        index = hashing(key);
    else
        index = doublehashing(key, attempt);

    while((attempt < 3) && (array[index].has_value()))
    {
        if (prob == LIN)
            index = linprob(index);
        else if (prob == QUAD)
            index = quadprob(index, attempt);
        else if(prob == RAD)
            index = radprob(index);
        if (prob == DOUBLEHASH)
            index = doublehashing(index, attempt);

        attempt++;
    }

    if (array[index].value() == key)
    {
        array[index] = nullopt;
        return true;
    }
    else
    {
        cout << "array is not searched" << endl;
        return false;
    }
}

//Хекширование
unsigned int linShashList::hashing(unsigned int info)
{
    return (info % table_size);
}

unsigned int linShashList::hashing2(unsigned int info)
{
    return (info / table_size) % (table_size - 1) + 1;
}

//Двойное хеширование
unsigned int linShashList::doublehashing(unsigned int info, unsigned int attm)
{
    return (hashing(info) + attm * hashing2(info)) % table_size;
}

//Линейное пробирование
unsigned int linShashList::linprob(unsigned int info)
{
    return (info + 1) % table_size;
}

//Квадратичное пробирование
unsigned int linShashList::quadprob(unsigned int info, unsigned int attm)
{
    return (info + attm*attm) % table_size;
}

//Псевдослучайное пробирование
unsigned int linShashList::radprob(unsigned int info)
{
    srand(time(nullptr));
    return (info + rand() % table_size) % table_size;
}

void linShashList::print()
{
    for (unsigned int index = 0; index < table_size; index++)
    {
        if (array[index].has_value())
            cout << "array[" << index << "] = " << array[index].value() << endl;
        else
            cout << "array[" << index << "] = empty" << endl;
    }
}
