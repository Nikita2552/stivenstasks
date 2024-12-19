#include "hashlist.h"

hashList::hashList(unsigned int ts): table_size(ts)
{
    list = new exampleList<unsigned int>[table_size];
}

hashList::~hashList()
{
    delete[] list;
}

void hashList::appendElement(unsigned int key)
{
    unsigned int index = hashing(key);
    list[index].appendEvent(key);
}

void hashList::removeElement(unsigned int key)
{
    unsigned int index = hashing(key);
    for (unsigned int i = 0; i < table_size; i++)
    {
        if (list[index].getEvent(i) == key)
        {
            list[index].removeEvent(i);

            return;
        }
    }
}

bool hashList::searchElement(unsigned int key)
{
    unsigned int index = hashing(key);
    for (unsigned int i = 0; i < list->getNum(); i++)
    {
        if (list[index].getEvent(i) == key)
        {
            return true;
        }
    }
    return false;
}

unsigned int hashList::hashing(unsigned int info)
{
    return (info % table_size);
}

void hashList::print()
{
    for (unsigned int i = 0; i < table_size; i++)
    {
        cout << i;
        for (unsigned int j = 0; j < list[i].getNum(); j++)
        {
            cout << " ==> " << list[i].getEvent(j);
        }
        cout << endl;
    }
}
