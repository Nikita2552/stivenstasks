#ifndef EXAMPLEList_H
#define EXAMPLEList_H

template<typename T>
class exampleEvent;
template<typename T>
class exampleList;

template<typename T>
class exampleList
{
public:
    exampleList(unsigned int size = 10);
    ~exampleList();

    unsigned int getSize();
    unsigned int getNum();

    void appendEvent(const T& event);
    T* removeEvent(const unsigned int& index);

    void setEvent(const unsigned int& index, const T& event);
    T getEvent(const unsigned int& index);


    void clear();

private:
    unsigned int quSize;
    unsigned int quNum;
    exampleEvent<T>* head;
    exampleEvent<T>* tail;

    exampleEvent<T>* getEventfromIndex(const unsigned int& index);
};

template<typename T>
class exampleEvent
{
public:
    exampleEvent();
    exampleEvent(const T& data);
    ~exampleEvent();

    exampleEvent<T>* getNext();
    void setNext(exampleEvent<T>* next);

    exampleEvent<T>* getPrev();
    void setPrev(exampleEvent<T>* prev);

    T getData();

private:
    T daEvent;
    exampleEvent<T>* nextEvent;
    exampleEvent<T>* prevEvent;
};

template<typename T>
exampleList<T>::exampleList(unsigned int size): quSize(size), quNum(0)
{
    tail = new exampleEvent<T>();
    head = new exampleEvent<T>();
    head->setNext(tail);
    tail->setPrev(head);
}

template<typename T>
exampleList<T>::~exampleList()
{
    clear();
    delete head;
    delete tail;
}

template<typename T>
unsigned int exampleList<T>::getSize()
{
    return quSize;
}

template<typename T>
unsigned int exampleList<T>::getNum()
{
    return quNum;
}

template<typename T>
void exampleList<T>::appendEvent(const T& event)
{
    if (quNum < quSize)
    {
        exampleEvent<T> *eEvent = new exampleEvent<T>(event);

        exampleEvent<T> *prevEvent = tail->getPrev();
        exampleEvent<T> *nextEvent = tail;

        eEvent->setNext(nextEvent);
        eEvent->setPrev(prevEvent);

        nextEvent->setPrev(eEvent);
        prevEvent->setNext(eEvent);

        quNum++;
    }
}

template<typename T>
T *exampleList<T>::removeEvent(const unsigned int &index)
{
    if (quNum > index)
    {
        exampleEvent<T> *eEvent = getEventfromIndex(index);

        exampleEvent<T> *prevEvent = eEvent->getPrev();
        exampleEvent<T> *nextEvent = eEvent->getNext();

        prevEvent->setNext(nextEvent);
        nextEvent->setPrev(prevEvent);

        delete eEvent;

        quNum--;
    }

    return new T();
}

template<typename T>
void exampleList<T>::setEvent(const unsigned int& index, const T& event)
{
    if (quNum < quSize)
    {
        exampleEvent<T> *eEvent = new exampleEvent<T>(event);

        exampleEvent<T> *prevEvent = getEventfromIndex(index);
        exampleEvent<T> *nextEvent = prevEvent->getNext();

        eEvent->setNext(nextEvent);
        nextEvent->setPrev(eEvent);

        prevEvent->setNext(eEvent);
        eEvent->setPrev(prevEvent);

        quNum++;
    }
}

template<typename T>
T exampleList<T>::getEvent(const unsigned int& index)
{
    if (quNum > index)
    {
        exampleEvent<T> *eEvent = getEventfromIndex(index);

        return eEvent->getData();
    }

    return 0;
}



template<typename T>
void exampleList<T>::clear()
{
    unsigned int i = 0;
    while(i < quNum)
    {
        removeEvent(i);
        i++;
    }
}

template<typename T>
exampleEvent<T> *exampleList<T>::getEventfromIndex(const unsigned int &index)
{
    unsigned int i = 0;
    exampleEvent<T> *eEvent = head->getNext();
    while(i < index)
    {
        eEvent = eEvent->getNext();
        i++;
    }
    return eEvent;
}

template<typename T>
exampleEvent<T>::exampleEvent(): daEvent(0)
{

}

template<typename T>
exampleEvent<T>::exampleEvent(const T& data): daEvent(data)
{

}

template<typename T>
exampleEvent<T>::~exampleEvent()
{

}

template<typename T>
exampleEvent<T>* exampleEvent<T>::getNext()
{
    return nextEvent;
}

template<typename T>
void exampleEvent<T>::setNext(exampleEvent<T> *next)
{
    nextEvent = next;
}

template<typename T>
exampleEvent<T>* exampleEvent<T>::getPrev()
{
    return prevEvent;
}

template<typename T>
void exampleEvent<T>::setPrev(exampleEvent<T> *prev)
{
    prevEvent = prev;
}

template<typename T>
T exampleEvent<T>::getData()
{    
    return daEvent;
}

#endif // EXAMPLEEVENTQEUE_H
