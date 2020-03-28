#include "NumberArray.h"
#include<iostream>
#include<cstdlib>
using namespace std;

NumberArray::NumberArray(): arrayPointer(nullptr), size(0){ } //initialize arrayPointer to nullptr and size to 0

NumberArray::NumberArray(int size) :arrayPointer(new double[size]),size(size){ }

NumberArray::~NumberArray(){
	if(arrayPointer!= nullptr){
		delete[] arrayPointer; //remove the array and free the space
	}
}

int NumberArray::getSize() {
	return size;
}

void NumberArray::setElement(int index, double element){
	if(index<0 || index>=size){ //if invalid index
		cout<<"Invalid index number. Bye!\n";
		exit(0);
	}
	arrayPointer[index] = element;
}

double NumberArray::getElement(int index){
	if(index<0 || index>=size){ //if invalid index
		cout<<"Invalid index number. Bye!\n";
		exit(0);
	}
	return arrayPointer[index];
}

double NumberArray::getHighest() {
	double max = arrayPointer[0]; //initialize max to first variable
	for(int i=0;i<size;i++){
		if(max<arrayPointer[i]){// if max is less than current change max
			max = arrayPointer[i];
		}
	}
	return max;
}

double NumberArray::getLowest() {
	double min = arrayPointer[0];
	for(int i=0;i<size;i++){
		if(min>arrayPointer[i]){ //if min is greater than current change min
			min = arrayPointer[i];
		}
	}
	return min;
}

double NumberArray:: getAverage() {
	double sum = 0;
	for(int i=0;i<size;i++){
		sum += arrayPointer[i];//accumulate sum in variable
	}
	return sum/size; //caculate average
}