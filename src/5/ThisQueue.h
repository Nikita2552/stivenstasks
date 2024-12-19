#ifndef T_THISQU
#define T_THISQU

#include "ThisQueueElement.h"

template <typename T>
class ThisQueue
{
  public:
	ThisQueue();
	ThisQueue(const unsigned int &si);
	~ThisQueue();
	
    void enQueue(const T &inf);
	T deQueue();

void setSize(const unsigned int &si);		
unsigned int getSize();

private:
	unsigned int size;
	unsigned int num;
	ThisQueueElement<T> *first;
	ThisQueueElement<T> *last;
	
	void initQueue(const unsigned int &si);	
};

template <typename T> ThisQueue<T>::ThisQueue(){
		initQueue(5);
	};

template <typename T> ThisQueue<T>::ThisQueue(const unsigned int &si){
	initQueue(si);
	};
	
template <typename T> void ThisQueue<T>::
initQueue(const unsigned int &si)
{
	size = si;
	first = new ThisQueueElement<T>();
	last = new ThisQueueElement<T>();
	first->setNextPtr(last);
	last->setPrevPtr(first);
	
};
	
template <typename T> ThisQueue<T>::~ThisQueue(){};

template <typename T> 
void ThisQueue<T>::enQueue(const T &inf){
	
};

template <typename T>		
T ThisQueue<T>::deQueue(){
};
	
template <typename T> 
void ThisQueue<T>::setSize(const unsigned int &si){
	size = si;
};

template <typename T> 
unsigned int ThisQueue<T>::getSize(){
	return size;
};

#endif