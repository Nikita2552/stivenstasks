#ifndef HASHLIST_H
#define HASHLIST_H

#include <iostream>
#include "examplelist.h"

using namespace std;

class hashList
{
public:
    hashList(unsigned int ts = 10);
    ~hashList();

    void appendElement(unsigned int key);
    void removeElement(unsigned int key);
    bool searchElement(unsigned int key);

    unsigned int hashing(unsigned int info);

    void print();

private:
    exampleList<unsigned int> *list;
    unsigned int table_size;

};

#endif // HASHLIST_H
