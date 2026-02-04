#include <iostream>
#include "DynamicArray.h"
#include "SortedArray.h"
#include "UniqueArray.h" 

using namespace std;

int main()
{
	cout << "------------DynamicArray Testi...--------------" << endl;

	DynamicArray arr;

	// isEmpty testi
	cout << "Dizi bos mu? " << (arr.isEmpty() ? "Evet" : "Hayir") << endl;


	// push ve print testi
	arr.push(15);
	arr.push(23);
	arr.push(7);
	arr.push(78);
	arr.print();

	// Operator[] testi
	arr[2] = 50;
	cout << "2. indeksteki deger: " << arr[2] << endl;
	arr.print();


	// getSize ve getCapacity testi
	cout << "boyut: " << arr.getSize() << endl;
	cout << "kapasite: " << arr.getCapacity() << endl;

	// get testi
	cout << "3. indeksteki deger: " << arr.get(3) << endl;

	// set testi
	arr.set(2, 182);
	cout << "set fonksiyonundan sonra dizi: " << endl;
	arr.print();

	// pop testi
	arr.pop();
	arr.pop();
	cout << "pop fonksiyonundan sonra dizi: " << endl;
	arr.print();



	// clear testi
	arr.clear();
	cout << "clear fonksiyonundan sonra dizi: " << endl;
	arr.print();

	// Copy Constructor testi

	arr.push(12);
	arr.push(58);
	arr.push(45);

	// Copy Constructor	operator=
	//Yeni nesne oluþturulurken çaðrýlýr
	DynamicArray arrCopy(arr);
	cout << "Kopyalandi: " << endl;
	arrCopy.print();

	//Var olan nesneye atama yapýlýrken
	// Operator= testi
	DynamicArray arrAssign;
	arrAssign = arr;
	cout << "Atandi: " << endl;
	arrAssign.print();

	// Operator+ testi
	DynamicArray arr1;
	arr1.push(27);
	arr1.push(62);

	DynamicArray arrPlus = arr + arr1;
	arrPlus.print();

	// Operator== ve Operator!= testi

	cout << "arr ve arrCopy " << (arr == arrCopy ? "esit." : "esit degil.") << endl;
	cout << "arr ve arr1 " << (arr != arr1 ? "esit degil." : "esit.") << endl;

	arr.clear();

	cout << endl;
	cout << endl;
	cout << endl;

	cout << "------------SortedArray Testi...--------------" << endl;

	SortedArray sortedTestArr;

	sortedTestArr.push(45);
	sortedTestArr.push(12);
	sortedTestArr.push(78);
	sortedTestArr.push(23);
	sortedTestArr.push(150);
	sortedTestArr.push(15);


	sortedTestArr.print();


	cout << "Index 2: " << sortedTestArr.get(2) << endl;


	// Binary Search Testi
	int searchVal = 45;
	int index = sortedTestArr.binarySearch(searchVal);
	if (index == -1)
	{
		cout << searchVal << " bulunamadi!!!" << endl;
	}
	else
	{
		cout << searchVal << " icin indeks: " << index << endl;
	}


	cout << endl;
	cout << endl;
	cout << endl;

	cout << "------------UniqueArray Testi...--------------" << endl;

	UniqueArray uniqueTestArr;

	// 1. Normal Ekleme Testi
	cout << "10, 20, 30 ekleniyor..." << endl;
	uniqueTestArr.push(10);
	uniqueTestArr.push(20);
	uniqueTestArr.push(30);
	uniqueTestArr.print();

	// 2. Tekrar Eden Eleman Ekleme Testi (Duplicate Push)
	cout << "Tekrar eden (20) eklenmeye calisiliyor..." << endl;
	uniqueTestArr.push(20);
	uniqueTestArr.print();

	cout << "Tekrar eden (10) eklenmeye calisiliyor..." << endl;
	uniqueTestArr.push(10);
	uniqueTestArr.print();

	// 3. Yeni Farklý Eleman Ekleme Testi
	cout << "Yeni deger (40) ekleniyor..." << endl;
	uniqueTestArr.push(40);
	uniqueTestArr.print();

	// 4. contains Fonksiyonu Testi
	cout << "30'u iceriyor mu? " << (uniqueTestArr.contains(30) ? "Evet" : "Hayir") << endl;
	cout << "99'u iceriyor mu? " << (uniqueTestArr.contains(99) ? "Evet" : "Hayir") << endl;

	return 0;
}