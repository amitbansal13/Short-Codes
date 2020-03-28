#include <iostream>
#include "NumberArray.h"
using namespace std;

int main()
{
	int number;   // The number of elements
	int count;     // Loop counter
	double val;    // To hold a value
	int index;

	// Get the number of numbers to store.
	cout << "How many numbers do you want to store? ";
	cin >> number;

	// Create a NumberArray object.
	NumberArray numbers(number);

	// Get the numbers.
	cout << "\nEnter the " << number << " numbers:\n";
	for (count = 0; count < number; count++)
	{
		// Get a number.
		cout << "\tNumber " << (count + 1) << ": ";
		cin >> val;

		// Store it in the object.
		numbers.setElement(count, val);
	}

	// Display the values in the object.
	cout << "\n---------------------------------\n";
	cout << "\nHere are the numbers you entered:\n";
	for (count = 0; count < number; count++)
	{
		cout << "Number " << (count + 1) << ": "
			<< numbers.getElement(count)
			<< endl;
	}

	// Display the average of the values.
	cout << "\n---------------------------------\n";
	cout << "The average of those numbers is: ";
	cout << numbers.getAverage() << endl;

	// Display the highest of the values.
	cout << "The highest of those numbers is: ";
	cout << numbers.getHighest() << endl;

	// Display the lowest of the values.
	cout << "The lowest  of those numbers is: ";
	cout << numbers.getLowest() << endl << endl;

	// Set an element
	cout << "\Enter the index of the element you want to set its value: ";
	cin >> index;
	cout << "Enter the new value: ";
	cin >> val;
	numbers.setElement(index, val);

	cout << "\nThe array elements after set ...\n";
	for (count = 0; count < numbers.getSize(); count++)
	{
		cout << "Number " << (count + 1) << ": "
			<< numbers.getElement(count)
			<< endl;
	}

	cout << "\nTo get the value of an element, enter the index of the element: ";
	cin >> index;
	val = numbers.getElement(index);
	cout << "The value of element " << index << " is " << val << endl;

	return 0;
}