#ifndef LINSHASHLIST_H
#define LINSHASHLIST_H

#include <iostream>
#include <vector>
#include <optional>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef enum
{
    LIN = 00,
    QUAD = 01,
    RAD = 03,
    DOUBLEHASH = 04
} PROBS;

class linShashList
{
public:
    linShashList(unsigned int ts = 10, PROBS pr = LIN);
    ~linShashList();

    void appendElement(unsigned int key);
    void removeElement(unsigned int key);
    bool searchElement(unsigned int key);

    unsigned int hashing(unsigned int info);
    unsigned int hashing2(unsigned int info);
    unsigned int doublehashing(unsigned int info, unsigned int attm);
    unsigned int linprob(unsigned int info);
    unsigned int quadprob(unsigned int info, unsigned int attm);
    unsigned int radprob(unsigned int info);

    void print();

private:
    vector<optional<unsigned int>> array;
    unsigned int table_size;
    PROBS prob;
};

#endif // LINSHASHLIST_H
