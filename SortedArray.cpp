#include "SortedArray.h"
#include <iostream>

using namespace std;

// Parametresiz Constructor
SortedArray::SortedArray() : DynamicArray()
{
}

// Parametreli Constructor 
SortedArray::SortedArray(int capacity) : DynamicArray(capacity)
{
}


void SortedArray::push(int value)
{
	DynamicArray::push(value);

	int i = getSize() - 1; // Eklediðimiz son elemanýn indeksi

	while (i > 0 && get(i - 1) > get(i))
	{
		// Deðerleri al
		int temp = get(i);
		int prevVal = get(i - 1);

		// Yer deðiþtir
		set(i, prevVal);    // Büyüðü saða at
		set(i - 1, temp);   // Küçüðü sola al

		i--;
	}
}

int SortedArray::binarySearch(int value) const
{
	int leftIndex = 0;
	int rightIndex = getSize() - 1;

	while (leftIndex <= rightIndex)

	{
		int middleIndex = (leftIndex + rightIndex) / 2;
		int midVal = get(middleIndex);

		if (midVal == value)
			return middleIndex;
		
		
		else if (midVal < value)
			leftIndex = middleIndex + 1;

		else
			rightIndex = middleIndex - 1;
	}
	return -1;
}