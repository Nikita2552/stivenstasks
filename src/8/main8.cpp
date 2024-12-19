#include "main8.h"

/*
 *
 * Создать хэш на оснве ссылок:
 * https://www.educba.com/c-plus-plus-hash-table/
 * https://habr.com/ru/articles/509220/
 * https://www.8host.com/blog/xesh-tablica-v-c-c-polnaya-realizaciya/
 *
 */

void main8()
{
    cout << "main8 Hello World!" << endl;
    
    exhash();
    linshash();

}

void exhash()
{
    cout << "list test: done!" << endl;
    //list test
    exampleList<unsigned int> *list = new exampleList<unsigned int>();

    list->appendEvent(32);
    list->appendEvent(35);
    list->appendEvent(40);

    list->setEvent(1, 23);

    list->removeEvent(2);

    delete list;

    cout << "hash test:" << endl;

    hashList *hash = new hashList();

    hash->appendElement(32);
    hash->appendElement(50);
    hash->appendElement(80);
    hash->appendElement(75);
    hash->appendElement(23);
    hash->appendElement(43);
    hash->appendElement(63);
    hash->appendElement(507);

    hash->removeElement(75);

    if (hash->searchElement(80))
        cout << "yes!" << endl;
    else
        cout << "no!" << endl;

    hash->print();

    delete hash;
}

void linshash()
{
    cout << "lin shash:" << endl;

    linShashList *linshash = new linShashList(20, DOUBLEHASH);

    linshash->appendElement(32);
    linshash->appendElement(80);
    linshash->appendElement(20);

    linshash->removeElement(80);

    linshash->print();

    delete linshash;
}
