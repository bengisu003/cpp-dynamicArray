#ifndef SORTEDARRAY_H
#define SORTEDARRAY_H

#include "DynamicArray.h"

class SortedArray : public DynamicArray    // inheritance 
{
public:
	SortedArray();

	SortedArray(int capacity);

	void push(int value) override;  // override yapýldý sýralayarak eklemek icin geri kalanlar miras alýncak

	int binarySearch(int value) const;
};
#endif