#ifndef NUMBERARRAY_H
#define NUMBERARRAY_H

class NumberArray {
private:
	double *arrayPointer;
	int size;
public:
	NumberArray();
	NumberArray(int);
	~NumberArray();

	int getSize();
	void setElement(int, double);
	double getElement(int);
	double getHighest();
	double getLowest();
	double getAverage();
};

#endif