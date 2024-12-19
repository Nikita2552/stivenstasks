#include "sortlog.h"

using namespace std;

extern int *arr;

//need to debug
void sortPDCH(int *ourarray, int maxvalue)
{
    int counts[maxvalue];
    int i = 0;
    while (i < maxvalue)
    {
        counts[i] = 0;
        i++;
    }

    for (int j = 0; j < maxvalue; j++)
        counts[ourarray[j]] += 1;

    int index = 0;
    for (int j = 0; j < maxvalue; j++)
        for (int k = 1; k < counts[j]; k++)
        {
            ourarray[index] = i;
            index += 1;
        }
}

void sorBL()
{

}
