#include <iostream>

#include "src/3/main3.h"
#include "src/4/main4.h"
#include "src/5/main5.h"
#include "src/6/main6.h"
#include "src/7/main7.h"
#include "src/8/main8.h"
#include "src/9/main9.h"
#include "src/10/main10.h"
#include "src/11/main11.h"
#include "src/12/main12.h"
#include "src/13/main13.h"
#include "src/14/main14.h"
#include "src/15/main15.h"
#include "src/16/main16.h"
#include "src/17/main17.h"
#include "src/18/main18.h"
#include "src/19/main19.h"

using namespace std;

typedef enum
{
    CHAPTER3 = 3, CHAPTER4, CHAPTER5, CHAPTER6, CHAPTER7, CHAPTER8, CHAPTER9,
    CHAPTER10, CHAPTER11, CHAPTER12, CHAPTER13, CHAPTER14, CHAPTER15,
    CHAPTER16, CHAPTER17, CHAPTER18, CHAPTER19,
} STIVENSCHAPTERS;


int main()
{


    STIVENSCHAPTERS chapter = CHAPTER9;
    cout << "Def chapter is " << chapter << endl;

    switch (chapter)
    {
        case (CHAPTER3): main3(); break;
        case (CHAPTER4): main4(); break;
        case (CHAPTER5): main5(); break;
        case (CHAPTER6): main6(); break;
        case (CHAPTER7): main7(); break;
        case (CHAPTER8): main8(); break;
        case (CHAPTER9): main9(); break;
        case (CHAPTER10): main10(); break;
        case (CHAPTER11): main11(); break;
        case (CHAPTER12): main12(); break;
        case (CHAPTER13): main13(); break;
        case (CHAPTER14): main14(); break;
        case (CHAPTER15): main15(); break;
        case (CHAPTER16): main16(); break;
        case (CHAPTER17): main17(); break;
        case (CHAPTER18): main18(); break;
        case (CHAPTER19): main19(); break;
        default: cout << "other chapter not found! << endl"; break;
    }

    return 0;
}
