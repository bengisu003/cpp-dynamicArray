#include "UniqueArray.h"
#include<iostream>

#include "DynamicArray.h"

using namespace std;

UniqueArray::UniqueArray() : DynamicArray() {}

UniqueArray::UniqueArray(int capacity) : DynamicArray(capacity) {}

//contains: dizide eleman var mý
bool UniqueArray::contains(int value) const {
	//"data" deðiþkeni private olduðu için "getSize()" ve "get(i)" fonksiyonlarýný kullanýyoruz
	for (int i = 0; i < getSize(); i++) {
		if (get(i) == value) {
			return true;
		}
	}
	return false;
}

//push: eleman yoksa ekleme yapar
void UniqueArray::push(int value) {
	//önce kontrol yap
	if (contains(value)) {
		return;
	}

	DynamicArray::push(value);
}