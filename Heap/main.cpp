#include<iostream>
#include "Heap.h"
#include "Heap.cpp"
using namespace std;


// template<typename T>
void heapSort(int list[],int arraySize){
	Heap<int> *h=new Heap<int>(list,arraySize);
	// for(int i=0;i<arraySize;i++)
	// 	h.add(list[i]);
	for(int i=0;i<arraySize;i++){
		list[i]=h->remove();
	}
}


int main(){
	const int SIZE=9;
	int list[] = {1,7,3,4,9,11,3,1,2};
	heapSort(list,SIZE);
	cout<<"Sorted elements using heap: \n";
	for(int i=0;i<SIZE;i++){
		cout<<list[i]<<" ";
	}
	cout<<endl;
	return 0;
}