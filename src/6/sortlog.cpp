#include "sortlog.h"

using namespace std;

#define SIZE 10
#define RANGE 50

extern int *arr;



void makeHeap()
{
    int i = 0;
    while (i < SIZE)
    {
        int index = i;
        while (index)
        {
            int parent = (index-1)/2;
            if (arr[index] <= arr[parent]) break;

            int temp = arr[index];
            arr[index] = arr[parent];
            arr[parent] = temp;

            index = parent;
        }
        i++;
    }

}

int removeTopHeap()
{
    int result = arr[0];
    arr[0] = arr[SIZE - 1];

    int index = 0;
    while (true)
    {
        int child1 = 2*index+1;
        int child2 = 2*index+2;

        if (child1 >= SIZE) child1 = index;
        if (child2 >= SIZE) child2 = index;

        if ((arr[index] >= arr[child1])
                && (arr[index] >= arr[child2]))
            break;

        int swap_child;
        if (arr[child1] > arr[child2]) swap_child = child1;
        else swap_child = child2;

        int temp = arr[index];
        arr[index] = arr[swap_child];
        arr[swap_child] = temp;

        index = swap_child;
    }

    return result;
}

void sortPE()
{
    int i = SIZE-1;
    while (i > -1)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        int index = 0;
        while (true)
        {
            int child1 = 2*index+1;
            int child2 = 2*index+2;

            if (child1 >= i) child1 = index;
            if (child2 >= i) child2 = index;

            if ((arr[index] >= arr[child1])
                    && (arr[index] >= arr[child2]))
                break;

            int swap_child;
            if (arr[child1] > arr[child2]) swap_child = child1;
            else swap_child = child2;

            int temp = arr[index];
            arr[index] = arr[swap_child];
            arr[swap_child] = temp;

            index = swap_child;
        }

        i--;
    }
}

//need to debug
void sortSL(int *ourarray, int *scrarray, int startIndex, int endIndex)
{
    if (startIndex >= endIndex) return;

    int midpoint = (startIndex + endIndex)/2;

    sortSL(ourarray, scrarray, startIndex, midpoint);
    sortSL(ourarray, scrarray, midpoint+1, endIndex);

    int left_index = startIndex;
    int right_index = midpoint+1;
    int scr_index = left_index;

    while ((left_index <= midpoint) && (right_index <= endIndex))
    {
        if (ourarray[left_index] <= ourarray[right_index])
        {
            scrarray[scr_index] = ourarray[left_index];
            left_index++;
        }
        else
        {
            scrarray[scr_index] = ourarray[right_index];
            right_index++;
        }
        scr_index++;
    }

    for (int i = left_index; i <= midpoint; i++)
    {
        scrarray[scr_index] = ourarray[i];
        scr_index++;
    }

    for (int i = right_index; i <= endIndex; i++)
    {
        scrarray[scr_index] = ourarray[i];
        scr_index++;
    }

    for (int i = startIndex; i <= endIndex; i++)
        ourarray[i] = scrarray[i];
}

int test1[7] = {6, 12, 3, 15, 8, 5, 7};
#define SIZET 7

void sortQU()
{
    sortQU(arr, 0, SIZE-1);
}

void sortQU(int *ourarray, int startIndex, int endIndex)
{
    if (startIndex >= endIndex) return;

    int divider = ourarray[startIndex];
    int lo = startIndex;
    int hi = endIndex;

    while(true)
    {
        while(ourarray[hi] >= divider)
        {
            hi-=1;
            if (hi <= lo) break;
        }

        if (hi <= lo)
        {
            ourarray[lo] = divider;
            break;
        }

        ourarray[lo] = ourarray[hi];

        lo+=1;
        while(ourarray[lo] < divider)
        {
            lo+=1;
            if (lo >= hi) break;
        }

        if (lo >= hi)
        {
            lo = hi;
            ourarray[hi] = divider;
            break;
        }

        ourarray[hi] = ourarray[lo];
    }
        sortQU(ourarray, startIndex, lo-1);
        sortQU(ourarray, lo+1, endIndex);
}

//alternative, not working
void sortOldQU(int *ourarray, const unsigned int &startIndex, const unsigned int &endIndex)
{
    srand(time(nullptr));
    int senIndex = rand()%endIndex;
    int sen = ourarray[senIndex];    

    int i = 0;
    while (i < senIndex)
    {
        if (arr[i] > sen)
            senIndex = upOneIndex(ourarray, i, senIndex+1, SIZE, senIndex);
        else
            senIndex = downOneIndex(ourarray, senIndex-1, i, SIZE, senIndex);
        i++;
    }

    i = senIndex+1;
    while (i < SIZE-1)
    {
        if (arr[i] < sen)
            senIndex = upOneIndex(ourarray, i, senIndex-1, SIZE, senIndex);
        else
            senIndex = downOneIndex(ourarray, senIndex+1, i, SIZE, senIndex);
        i++;
    }

    sortOldQU(ourarray, 0, senIndex-1);
    sortOldQU(ourarray, senIndex-1, SIZE-1);

    cout << "test" << endl;
}

unsigned int upOneIndex(int *inputarray, const unsigned int &Index, const unsigned int &upIndex, const unsigned int &size, unsigned int oldIndex)
{
    if ((Index < upIndex) && (upIndex < size))
    {
        int el = inputarray[Index];

        unsigned int  i = Index+1;
        while(i <= upIndex)
        {
            inputarray[i-1] = inputarray[i];
            i++;
        }

        inputarray[upIndex] = el;

        if ((Index < oldIndex) && (oldIndex < upIndex))
            return --oldIndex;
    }

    return oldIndex;
}

unsigned int downOneIndex(int *inputarray, const unsigned int &Index, const unsigned int &downIndex, const unsigned int &size, unsigned int oldIndex)
{
    if ((downIndex < Index) && (Index < size))
    {
        int el = inputarray[Index];
        int di = (int) downIndex;

        int  i = Index-1;
        while(i >= di)
        {
            inputarray[i+1] = inputarray[i];
            i--;
        }

        inputarray[downIndex] = el;

        if ((downIndex < oldIndex) && (oldIndex < Index))
            return ++oldIndex;
    }

    return oldIndex;
}

void printTest1()
{
    int i = 0;
    while (i < SIZET)
    {
        cout << "["<<i<<"] = " << test1[i] << endl;
        i++;
    }
}
