#include "sort.h"

using namespace std;

#define SIZE 10
#define RANGE 50
int *arr;

void initArray()
{
	arr = new int[SIZE];
	int i = 0;
	while (i < SIZE)
	{
		arr[i] = 0;
		i++;
	}
}

void deleteArray()
{
    delete arr;
}

void randomArray()
{
	srand(time(nullptr));
    int i = 0;
	while (i < SIZE)
	{
        arr[i] = rand()%RANGE;
		i++;
	}
}


void printArray()
{
	int i = 0;
    while (i < SIZE)
	{
		cout << "["<<i<<"] = " << arr[i] << endl;
		i++;
	}
}

void sortVS()
{
	int i = 0;
	while (i < SIZE)
	{
		int temp = arr[i];
		int j = 0;
		while(j < i)
		{
			if (temp < arr[j])
			 break;
			j++;
		}
		int k = i;
		while (k > j)
		{
		    arr[k] = arr[k-1];
		    k--;
		}
		arr[j] = temp;
	    i++;
	}
}

void sortVI()
{
	int i = 0;
	while (i < SIZE)
	{
		int j = 0;
		int jmax = j;
		while (j < SIZE-i)
		{
			if (arr[j] > arr[jmax])
			    jmax = j;
			j++;
		}
		j = jmax+1;
		int max = arr[jmax];
		while(j < SIZE-i)
		{
			arr[j-1] = arr[j];
			j++;
		}
		arr[SIZE-i-1] = max;
		i++;
	}
}

void sortPU()
{
	bool notSorted = true;
	
	while(notSorted)
	{
		notSorted = false;
		int i = 1;
		while(i < SIZE)
		{
			if (arr[i] < arr[i - 1])
			{
				int temp = arr[i];
				arr[i] = arr[i-1];
				arr[i-1] = temp;
				
				notSorted = true;
			}
			i++;
		}
	}
}

void sortFastPU()
{
    bool notSorted = true;

    while(notSorted)
    {
        notSorted = false;
        int temp = arr[0];
        int i = 1;
        while (i < SIZE)
        {
            if (temp < arr[i])
            {
                arr[i-1] = arr[i];

                if (i == SIZE-1)
                    arr[i] = temp;

                notSorted = true;
            }
            else
            {
                arr[i-1] = temp;
                temp = arr[i];
            }
            i++;
        }
     }
  }

int test[6] = {15, 3, 12, 8, 5, 7};
#define SIZET 6

//not debugged
void sortFastPUTest()
{
    bool notSorted = true;

    while(notSorted)
    {
        notSorted = false;
        int temp = test[0];
        int i = 1;
        while (i < SIZET)
        {
            if (temp < test[i])
            {
                test[i-1] = test[i];

                if (i == SIZET-1)
                    test[i] = temp;

                notSorted = true;
            }
            else
            {
                test[i-1] = temp;
                temp = test[i];
            }
            i++;
        }
     }
  }

void printTest()
{
    int i = 0;
    while (i < SIZET)
    {
        cout << "["<<i<<"] = " << test[i] << endl;
        i++;
    }
}
