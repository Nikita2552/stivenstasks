#ifndef T_THISQUARR
#define T_THISQUARR

#include <iostream>

using namespace std;

template <typename T>
class ThisQueueArray
{
  public:
	ThisQueueArray();
	ThisQueueArray(const unsigned int &si);
	~ThisQueueArray();
	
    void enQueue(const T &inf);
	T deQueue();

     void setSize(const unsigned int &si);		  unsigned int getSize();

      void printAll();

private:
   unsigned int size;
    int front = -1;
	int rear = -1;
	
	T *head;
	
	void initQueue(const unsigned int &si);	bool isFull();
	bool isEmpty();
};

template <typename T> ThisQueueArray<T>::ThisQueueArray(){
		initQueue(5);
	};

template <typename T> ThisQueueArray<T>::ThisQueueArray(const unsigned int &si){
	initQueue(si);
	};
	
template <typename T> void ThisQueueArray<T>::
initQueue(const unsigned int &si)
{
	size = si;
	
	head = new T[si];
	
    unsigned int i = 0;
    while (i < si)
    {
	    *(head+i) = 0;
	    i++;
    }
};
	
template <typename T> ThisQueueArray<T>::~ThisQueueArray(){};

template <typename T> 
void ThisQueueArray<T>::enQueue(const T &inf){
	if (!isFull()) 
	{
		if (front == -1) front++;
		rear = (rear+1)%size;
		*(head+rear)=inf;
	}
	
};

template <typename T>		
T ThisQueueArray<T>::deQueue(){
 if (!isEmpty())
 {
 	T el = *(head+front);
 	
 	if (front == rear)
 	{
 		front = -1;
 		rear = -1;
 	}
 	else
 	    front = (front +1)%size;
 	
 	return el;
  }
 else
      return 0;
};
	
template <typename T> 
void ThisQueueArray<T>::setSize(const unsigned int &si){
	size = si;
};

template <typename T> 
unsigned int ThisQueueArray<T>::getSize(){
	return size;
};

template <typename T>
void ThisQueueArray<T>::printAll()
{
	 unsigned int i = 0;
    while (i < size)
    {
	    cout << "arr["<<i<<"]="<<*(head+i)<<endl;
	    i++;
    }
};

template <typename T>
bool ThisQueueArray<T>::isFull()
{
	if (front == 0 && rear == size - 1)
	 return true;
	if (front == rear + 1)
	 return true;
	 
	 return false;
};

template <typename T>
bool ThisQueueArray<T>::isEmpty()
{
	if (front == -1)
	 return true;
	else
	return false;
};

#endif