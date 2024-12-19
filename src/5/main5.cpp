#include "main5.h"

void main5()
{
    cout << "main6 Hello World! test" << endl;

    StackList<int> *st = new StackList<int>();

    st->push(5);
    st->push(3);
    st->push(8);

    int num = st->pop();

    StackArray<int> *at = new StackArray<int>();

    at->push(5);
    at->push(3);
    at->push(8);

    //num = at->pop();

    StackTwoSideArray<int> *tst = new StackTwoSideArray<int>();

    tst->push1(5);
    tst->push1(3);
    tst->push1(8);
    tst->push2(5);
    tst->push2(3);
    tst->push2(8);

    //tst->printall();

    int num1 = tst->pop1();
    int num2 = tst->pop2();

    //tst->printall();


    StackArray<int> *vs = sortstack_vs(at);
    //at->printall();
    //vs->printall();

    at->push(5);
    at->push(3);
    at->push(8);

    StackArray<int> *vi = sortstack_vi(at);
    //at->printall();
    //vi->printall();

    cout << "test x" << endl;

    delete st;
    delete at;
    delete tst;
    //delete vi;
    delete vs;

    cout << "***queues***" << endl;

    ThisQueueElement<int> *te = new ThisQueueElement<int>();

    te->setInfo(155);
    int nu = te->getInfo();
    cout << "returned nu is " << nu  << endl;

    ThisQueueArray<int> *tq = new ThisQueueArray<int>();

    tq->printAll();

    tq->enQueue(5);
    tq->enQueue(3);

    cout << "~~~" << endl;
    tq->printAll();

    tq->enQueue(6);
    tq->enQueue(2);
    tq->enQueue(4);

    cout << "~~~" << endl;

    cout << "test " << tq->deQueue() << endl;
    cout << "test " << tq->deQueue() << endl;
    cout << "test " << tq->deQueue() << endl;
    cout << "test " << tq->deQueue() << endl;
    cout << "test " << tq->deQueue() << endl;

    tq->enQueue(1);
    tq->enQueue(8);
    tq->enQueue(10);
    tq->enQueue(7);
    tq->enQueue(9);

    cout << "~~~" << endl;
    tq->printAll();

    delete te;
    delete tq;

    cout << "test y" << endl;
}
