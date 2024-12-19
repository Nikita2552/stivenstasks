#ifndef THISLIST_H
#define THISLIST_H

#include <iostream>


using namespace std;

namespace fourespace
{
    template<typename T> class ThisCell
    {
    public:
        ThisCell();
        ThisCell(const T &curtype);
        ~ThisCell();

        void setType(const T &curtype);
        T getType();

        void setNext(ThisCell *point);
        ThisCell *getNext();
        void deleteNext();

        void setflag(bool flag);
        bool getflag();

    private:
        T thistype;
        ThisCell<T> *next = nullptr;

        bool visited;
    };

    template<typename T> class ThisList
    {
    public:
        ThisList();
        ThisList(unsigned int s);
        ~ThisList();

        void initptrs();
        void resetcell(ThisCell<T> *point);
        ThisCell<T> *searchcell(const unsigned int n);

        ThisCell<T> *getfirst();
        ThisCell<T> *getlast();

        unsigned int getsize();
        unsigned int getnum();
        void setnum(unsigned int n);
        void setlast(ThisCell<T> *point);

        void appendcell(const T &info);
        void insertcell(const unsigned int n, const T &info);
        void deletecell(unsigned int n);

        void loopendtocell(const unsigned int n);
        void markalg();
        void tracealg();
        bool reversealg();

        ThisCell<T> *reverse(ThisCell<T> *sent);

    private:
       ThisCell<T> *head = nullptr;
       ThisCell<T> *end = nullptr;
       unsigned int size = 0;
       unsigned int num = 0;
};

    template<typename T> class IteratorList
    {
    public:
        IteratorList(ThisList<T> *thlist);
        ~IteratorList();

        ThisCell<T> *first();
        ThisCell<T> *last();

    private:
        ThisList<T> *list;
    };

    template<typename T>
    IteratorList<T>::IteratorList(ThisList<T> *thlist)
    {
        list = thlist;
        //cell = list->getfirst();
    }

    template<typename T>
    IteratorList<T>::~IteratorList()
    {

    }

    template<typename T>
    ThisCell<T> *IteratorList<T>::first()
    {
        return list->getfirst();
    }

    template<typename T>
    ThisCell<T> *IteratorList<T>::last()
    {
        return list->getlast();
    }

    template<typename T>
    ThisList<T>::ThisList()
    {
        cout << "Thislist create" << endl;
        initptrs();
    }

    template<typename T>
    ThisList<T>::ThisList(unsigned int s)
    {
        cout << "Thislist create" << endl;
        size = s;
        initptrs();
    }

    template<typename T>
    ThisList<T>::~ThisList()
    {
        cout << "Thislist delete" << endl;
    }

    template<typename T>
    void ThisList<T>::initptrs()
    {
        ThisCell<T> *cell = new ThisCell<T>(0);
        head = cell;

        cell = new ThisCell<T>(0);
        end = cell;

        head->setNext(end);
        end = head;
    }

    template<typename T>
    void ThisList<T>::appendcell(const T &info)
    {
        ThisCell<T> *cell = new ThisCell<T>(info);
        cell->setNext(end->getNext());
        end->setNext(cell);
        end = cell;
        num++;
    }

    template<typename T>
    void ThisList<T>::insertcell(const unsigned int n, const T &info)
    {

        if (n < num)
        {
            ThisCell<T> *cur = searchcell(n);

            ThisCell<T> *cell = new ThisCell<T>(info);
            cell->setNext(cur->getNext());
            cur->setNext(cell);
            cur = cell;
            num++;
        }
    }

    template<typename T>
    void ThisList<T>::deletecell(unsigned int n)
    {
        if (n < num)
        {
            ThisCell<T> *cur = searchcell(n);
            resetcell(cur);
        }
    }

    template<typename T>
    void ThisList<T>::resetcell(ThisCell<T> *point)
    {
        ThisCell<T> *cell = point->getNext();

        //if (cell->getNext())
        point->setNext(cell->getNext());

        delete cell;
        num--;
    }

    template<typename T>
    ThisCell<T> *ThisList<T>::searchcell(const unsigned int n)
    {
        ThisCell<T> *cur = head;
        unsigned int i = 0;
        while((cur->getNext()) && (i < n))
        {
            cur = cur->getNext();
            i++;
        }

        return cur;
    }

    template<typename T>
    ThisCell<T> *ThisList<T>::getfirst()
    {
        return head;
    }

    template<typename T>
    ThisCell<T> *ThisList<T>::getlast()
    {
        return end;
    }

    template<typename T>
    fourespace::ThisCell<T>::ThisCell()
    {
        cout << "Thiscell create" << endl;
        thistype = nullptr;
        next = nullptr;
    }

    template<typename T>
    fourespace::ThisCell<T>::ThisCell(const T &curtype)
    {
        cout << "Thiscell create" << endl;
        thistype = curtype;
        next = nullptr;
    }

    template<typename T>
    fourespace::ThisCell<T>::~ThisCell()
    {
        cout << "Thiscell delete" << endl;
    }

    template<typename T>
    void fourespace::ThisCell<T>::setType(const T &curtype)
    {
        thistype = curtype;
    }

    template<typename T>
    T fourespace::ThisCell<T>::getType()
    {
        return thistype;
    }

    template<typename T>
    void ThisCell<T>::setNext(ThisCell<T> *point)
    {
        next = point;
    }

    template<typename T>
    ThisCell<T> *ThisCell<T>::getNext()
    {
        return next;
    }

    template<typename T>
    unsigned int ThisList<T>::getsize()
    {
        return size;
    }

    template<typename T>
    unsigned int ThisList<T>::getnum()
    {
        return num;
    }

    template<typename T>
    void ThisList<T>::setnum(const unsigned int n)
    {
        num = n;
    }

    template<typename T>
    void ThisList<T>::setlast(ThisCell<T> *point)
    {
        end = point;
    }

    /* копирование */

    template<typename T>
    void copylist(ThisList<T> *list1, ThisList<T> *list2)
    {
        ThisCell<T> *cell = list1->getfirst()->getNext();

        while(cell != list1->getlast()->getNext())
        {
            list2->appendcell(cell->getType());
            cell = cell->getNext();
        }
    }

    /* сортировка вставкой */

    template<typename T>
    ThisList<T> *sortlist_vs(ThisList<T> *inputlist)
    {
       ThisList<T> *outputlist = new ThisList<T>(inputlist->getsize());
       ThisCell<T> *inputcell = inputlist->getfirst()->getNext();

        while (inputcell->getNext())
        {
            ThisCell<T> *outputcell = outputlist->getfirst()->getNext();

            while (outputcell->getNext())
            {
                if (outputcell->getNext()->getType() < inputcell->getType())
                    outputcell = outputcell->getNext();
                else break;
            }

            ThisCell<T> *cell = new ThisCell<T>(inputcell->getType());
            cell->setNext(outputcell->getNext());
            outputcell->setNext(cell);

            unsigned int curnum = outputlist->getnum();
            outputlist->setnum(++curnum);

            inputcell = inputcell->getNext();
        }

        ThisCell<T> *fin = outputlist->getlast();
        while (fin->getNext())
            fin = fin->getNext();

        fin->setNext(outputlist->getlast()->getNext());
        ThisCell<T> *start = outputlist->getlast()->getNext()->getNext();
        outputlist->getfirst()->setNext(start);
        fin->getNext()->setNext(nullptr);
        outputlist->setlast(fin);

        return outputlist;
    }

    /* сортировка выбором */

    template<typename T>
    ThisList<T> *sortlist_vi(ThisList<T> *inputlist)
    {
        ThisList<T> *outputlist = new ThisList<T>(inputlist->getsize());
        ThisCell<T> *inputcell = inputlist->getfirst()->getNext();

        unsigned int n = inputlist->getnum();
        while (n)
        {
            ThisCell<T> *outputcell = inputlist->getfirst();
            ThisCell<T> *cell = outputcell;

            T temp = outputcell->getNext()->getType();
            while (outputcell->getNext()->getNext())
            {
               if (temp <= outputcell->getNext()->getType())
               {
                   temp = outputcell->getNext()->getType();
                   cell = outputcell;
               }

                   outputcell = outputcell->getNext();
            }
            outputlist->appendcell(temp);            
            inputlist->resetcell(cell);
            n--;
        }

        return outputlist;
    }

    /* Алгоритмы поиска замыкания */
    /* Написать алгоритм генерации списка с лупом для примера */

    template<typename T>
    void ThisList<T>::loopendtocell(const unsigned int n)
    {
        if (n < size)
        {
            ThisCell<T> *cell = head;
            unsigned int i = 0;
            while (i < n)
            {
                cell = cell->getNext();
                i++;
            }

            end->setNext(cell);
        }
    }

    /* Написать алгоритм маркировки */

    template<typename T>
    void ThisCell<T>::setflag(bool flag)
    {
        visited = flag;
    }

    template<typename T>
    bool ThisCell<T>::getflag()
    {
        return visited;
    }

    template<typename T>
    void ThisList<T>::markalg()
    {
        ThisCell<T> *cell = head;

        while(cell->getNext())
        {
            if (!cell->getNext()->getflag())
                cell->getNext()->setflag(true);
            else
            {
                cell->setNext(nullptr);
                return;
            }

            cell = cell->getNext();
        }
    }

    /* Написать алгоритм повторной трассировки */

    template<typename T>
    void ThisList<T>::tracealg()
    {

    }

    /* Написать алгоритм реверсирования */

    template<typename T>
    bool ThisList<T>::reversealg()
    {
        if (head->getNext() == end->getNext()) return false;

        ThisCell<T> *sentinell = reverse(head);
        ThisCell<T> *new_sentinell = reverse(sentinell);

        if (sentinell == new_sentinell) return true;
        else return false;

    }

    template<typename T>
    ThisCell<T> *ThisList<T>::reverse(ThisCell<T> *sent)
    {
        ThisCell<T> *prevcell = nullptr;
        ThisCell<T> *currcell = sent;
        while(currcell != nullptr)
        {
            ThisCell<T> *newcell = currcell->getNext();
            currcell->setNext(prevcell);

            prevcell = currcell;
            currcell = newcell;
        }
        return prevcell;
    }
}

#endif // THISLIST_H
