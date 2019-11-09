#include "Heap.h"
#define PARENT(i) (i - 1) / 2
#define LEFT(i) (2 * i + 1)
#define RIGHT(i) (2 * i + 2)
template<typename T>
Heap<T>::Heap(){
}
template<typename T>
Heap<T>::Heap(const T elements[],int arraySize){
	for(int i=0;i<arraySize;i++)
		add(elements[i]);
}
template<typename T>
T Heap<T>::remove() throw (runtime_error){
	T ele=v[0];
	v[0]=v[getSize()-1];
	v.pop_back();
	int i=0;
	while(true){
		int smallest = i;
		if (LEFT(i) < getSize() && v[LEFT(i)] < v[i])
			smallest = LEFT(i);
		if ( RIGHT(i)< getSize() && v[RIGHT(i)] < v[smallest])
			smallest = RIGHT(i);
		if (smallest != i) {
			swap(v[i], v[smallest]);
			i=smallest;
		}
		else
			break;
	}
	return ele;
}
template<typename T>
void Heap<T>::add(const T& element){
	v.push_back(element);
	int i=getSize()-1;
	while (i!=0 && v[PARENT(i)] > v[i]) 
	{
		swap(v[i], v[PARENT(i)]);
		i=PARENT(i);
	}
}
template<typename T>
int Heap<T>::getSize() const{
	return v.size();
}