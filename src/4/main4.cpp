#include "main4.h"

void main4()
{
    cout << "main5 Hello World!" << endl;

    OneAxeArray<int> *arr = new OneAxeArray<int>(7);

    arr->append(4);
    arr->append(2);
    arr->append(13);
    arr->append(9);
    arr->append(6);

    arr->printAll();

    cout << "test getElement -- " << *arr->getElement(3) << endl;
    cout << "test getMax -- " << arr->getMax() << endl;
    cout << "test getMin -- " << arr->getMin() << endl;
    cout << "test getAverage -- " << arr->getAverage() << endl;
    cout << "test getMedian -- " << arr->getMedian() << endl;

    arr->insertElement(3, 50);

    AllocEntry<int> *ac = new AllocEntry<int>();
//    ac->printAll();

    ac->setBlock(0, 12);
    ac->setBlock(3, 15);
//    ac->printAll();

    AllocRow<int> *ar = new AllocRow<int>();
    ar->appendEmptyArray(4);
    ar->appendEmptyArray(4);
    ar->appendEmptyArray(4);
    ar->appendEmptyArray(4);

    AllocEntry<int> *row0 = ar->getArray(0);
    ar->setArray(1, ac);

    int *block1 = ar->getBlock(1, 0);
    ar->setBlock(1, 0, 33);

    AllocRows<int> *ars = new AllocRows<int>();
    ars->appendEmptyRow();
    ars->appendEmptyRow();
    ars->appendEmptyRow();
    ars->appendEmptyRow();

    ars->appendEmptyArray(0);
    ars->appendEmptyArray(1);
    ars->appendEmptyArray(2);
    ars->appendEmptyArray(3);

    ars->setBlock(1, 0, 1, 54);
    cout << "info from the block -- " << *ars->getBlock(1, 0, 1) << endl;

    AllocEntry<int> *currow = ars->getArray(1, 0);
    currow->printAll();

    ars->deleteArray(1, 0);
    int *num = ars->getBlock(1, 0, 1);
    if (num)
        cout << "info from the block -- " << *num << endl;
    else
        cout << "conteiner num not found! " << endl;

    ars->appendEmptyArray(1);

    currow = ars->getArray(1, 0);
    currow->printAll();

    ars->setBlock(1, 0, 1, 38);
    cout << "info from the block -- " << *ars->getBlock(1, 0, 1) << endl;

    ars->setBlock(1, 0, 0, 25);
    cout << "info from the block -- " << *ars->getBlock(1, 0, 0) << endl;

    int *snum = ars->searchArray(15);
    cout << "info from the searchArray() -- " << *snum << endl;

    int *serr = ars->searchArray(20);
    if (serr)
        cout << "info from the searchArray() -- " << *serr << endl;
    else
        cout << "conteiner serr not found! " << endl;

    delete arr;
    delete ac;
    delete ar;
    delete ars;
}
