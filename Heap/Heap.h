#ifndef HEAP_H
#define HEAP_H
#include<vector>
#include <stdexcept>
using namespace std;
template<typename T>
class Heap{
public:
	Heap();
	Heap(const T elements[],int arraySize);
	T remove() throw (runtime_error);
	void add(const T& element);
	int getSize() const;
private:
	vector<T> v;
};
#endif