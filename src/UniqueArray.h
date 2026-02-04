#ifndef UNIQUEARRAY_H
#define UNIQUEARRAY_H
#include "DynamicArray.h" //Temel sýnýfý projeye dahil ediyoruz

//": public DynamicArray" diyerek miras alýyoruz
class UniqueArray : public DynamicArray {
public:

	UniqueArray();
	UniqueArray(int capacity);

	void push(int value) override;

	bool contains(int value) const;
};

#endif