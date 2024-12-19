#include "main3.h"

void main3()
{
    cout << "main4 Hello World!" << endl;

    ThisList<int> *test = new ThisList<int>(10);
    test->appendcell(10);
    test->appendcell(12);
    test->appendcell(5);
    test->appendcell(7);

    test->insertcell(3, 14);
    test->deletecell(2);

    ThisList<int> *copy = new ThisList<int>(10);
    copylist(test, copy);

    ThisList<int> *sortvs = sortlist_vs(test);
    ThisList<int> *sortvi = sortlist_vi(test);

    ThisList<int> *tloop = new ThisList<int>(10);
    tloop->appendcell(8);
    tloop->appendcell(4);
    tloop->appendcell(5);
    tloop->appendcell(9);
    tloop->appendcell(1);
    tloop->appendcell(10);
    tloop->appendcell(3);
    tloop->loopendtocell(5);

    //tloop->markalg();
    bool flag = tloop->reversealg();

    delete test;
    delete copy;
    delete sortvs;
    delete sortvi;
    delete tloop;
}
