#ifndef SORTLOG6_H
#define SORTLOG6_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sort.h"

using namespace std;

void makeHeap();
int removeTopHeap();
void sortPE();
void sortSL();
void sortQU();
void sortQU(int *ourarray, int startIndex, int endIndex);
void sortOldQU(int *ourarray, const unsigned int &startIndex, const unsigned int &endIndex);
unsigned int upOneIndex(int *inputarray, const unsigned int &Index, const unsigned int &upIndex, const unsigned int &size, unsigned int oldIndex);
unsigned int downOneIndex(int *inputarray, const unsigned int &Index, const unsigned int &downIndex, const unsigned int &size, unsigned int oldIndex);
void printTest1();

#endif // SORTLOG6_H
