#ifndef T_THISQUEL
#define T_THISQUEL

template <typename T>
class ThisQueueElement
{
  public:
	ThisQueueElement();
	ThisQueueElement(const T &inf);
	~ThisQueueElement();
	
	void setInfo(const T &inf);
	T getInfo();
	
	void setNextPtr(ThisQueueElement<T> **ptr);
	void setPrevPtr(ThisQueueElement<T> **ptr);
	
	ThisQueueElement<T> *getNextPtr();
	ThisQueueElement<T> *getPrevPtr();
	

  private:
	T info;
	ThisQueueElement *next;
	ThisQueueElement *prev;	
};

template <typename T> ThisQueueElement<T>::ThisQueueElement(){
	};

template <typename T> ThisQueueElement<T>::ThisQueueElement(const T &inf){
	info = inf;
	};

template <typename T> ThisQueueElement<T>::~ThisQueueElement(){};

template <typename T> 
void ThisQueueElement<T>::setInfo(const T &inf){
	info =inf;
};

template <typename T>		
T ThisQueueElement<T>::getInfo(){
	return info;
};
	
template <typename T> 
void ThisQueueElement<T>::setNextPtr(ThisQueueElement<T> **ptr){
	next = ptr;
};

template <typename T> 
void ThisQueueElement<T>::setPrevPtr(ThisQueueElement<T> **ptr){
	prev = ptr;
};
	
template <typename T> 
ThisQueueElement<T> *ThisQueueElement<T>::getNextPtr(){
	return next;
};

template <typename T> 
ThisQueueElement<T> *ThisQueueElement<T>::getPrevPtr(){
	return prev;
};

#endif