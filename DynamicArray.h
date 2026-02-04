#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>

using namespace std;

class DynamicArray {
private:
	int* data;
	int size;
	int capacity;

public:
	DynamicArray();
	DynamicArray(int capacity);
	DynamicArray(const DynamicArray& other);
	virtual ~DynamicArray();

	virtual void push(int value);
	void pop();
	int get(int index) const;
	void set(int index, int value);
	int getSize() const;
	int getCapacity() const;
	bool isEmpty() const;
	void clear();
	void print() const;

	int& operator[](int index);
	DynamicArray operator+(const DynamicArray& other);
	DynamicArray& operator=(const DynamicArray& other);
	bool operator==(const DynamicArray& other) const;
	bool operator!=(const DynamicArray& other) const;

	friend ostream& operator<<(ostream& os, const DynamicArray& arr);

};
#endif