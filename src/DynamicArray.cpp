#include "DynamicArray.h"
#include<iostream>

using namespace std;

//Varsayýlan Constructor

DynamicArray::DynamicArray() : size(0), capacity(2) {
	data = new int[capacity];
}

//Parametreli Constructor
DynamicArray::DynamicArray(int capacity) : size(0), capacity(capacity) {
	data = new int[capacity];
}

//Copy Constructor (Deep Copy)
//Bir diziyi kopyalarken pointerý deðil veriyi kopyalarýz

DynamicArray::DynamicArray(const DynamicArray& other) : size(other.size), capacity(other.capacity) {
	data = new int[capacity];

	//Verileri tek tek kopyalýyor
	for (int i = 0; i < size; i++) {
		data[i] = other.data[i];
	}
}

//Destructor

DynamicArray::~DynamicArray() {
	if (data != nullptr) {
		delete[] data;
	}
}

// Push: sona eleman ekler, büyür.
void DynamicArray::push(int value) {
	if (size == capacity) {
		capacity = capacity * 2;
		int* newData = new int[capacity]; // yeni büyük yer aç

		//eski verileri taþý
		for (int i = 0; i < size; i++) {
			newData[i] = data[i];
		}

		//eski küçük belleði sil ve pointerý güncelle
		delete[] data;
		data = newData;
	}

	//eleman ekle
	data[size] = value;
	size++;
}

//Pop: sondan eleman siler
void DynamicArray::pop() {
	if (isEmpty()) {
		cout << "Hata: Dizi bos, eleman silinmez!!" << endl;
		return;
	}

	size--;
}

//Get: Ýndeksteki elemaný getirir
int DynamicArray::get(int index) const {
	if (index < 0 || index >= size) {
		cout << "Hata: Yazdiginiz indeks gecersizdir!!" << endl;
		return -1;
	}
	return data[index];
}

//Set: Ýndeksteki elemaný deðiþtirir
void DynamicArray::set(int index, int value) {
	if (index < 0 || index >= size) {
		cout << "Hata: Yazdiginiz indeks gecersizdir!!" << endl;
		return;
	}
	data[index] = value;
}

int DynamicArray::getSize() const { return size; } //dizideki eleman sayýsýný döndürür
int DynamicArray::getCapacity() const { return capacity; } //dizinin kapasitesini döndürür
bool DynamicArray::isEmpty() const { return size == 0; } // dizi boþ mu kontrol eder

//Clear: tüm elemanlarý siler
void DynamicArray::clear() {
	size = 0;
}

//Print: ekrana yazdýrýr
void DynamicArray::print() const {
	cout << "Dizi: ";
	for (int i = 0; i < size; i++) {
		cout << data[i] << " ";
	}
	cout << endl;
}

//[]: Ýndeks operatörü
int& DynamicArray::operator[](int index) {
	return data[index];
}

// this b nýn adresi
// other a nýn kendisi
// =: Atama operatörü
DynamicArray& DynamicArray::operator=(const DynamicArray& other) {
	if (this == &other) {       // &other = a nýn adresi
		return *this;           // *this = b nin kendisi
	}

	delete[] data;

	size = other.size;
	capacity = other.capacity;
	data = new int[capacity];                    

	for (int i = 0; i < size; i++) {
		data[i] = other.data[i];
	}

	return *this;      
}

//+: birleþtirme operatörü
DynamicArray DynamicArray::operator+(const DynamicArray& other) {

	DynamicArray result(size + other.size);

	for (int i = 0; i < size; i++) {
		result.push(data[i]);
	}

	for (int i = 0; i < other.size; i++) {
		result.push(other.data[i]);
	}
	return result;
}

//==: Eþitlik Operatörü
bool DynamicArray::operator==(const DynamicArray& other)const {
	if (size != other.size) {
		return false;
	}
	for (int i = 0; i < size; i++) {
		if (data[i] != other.data[i]) {
			return false;
		}
	}
	return true;
}

//!=: Eþitsizlik Kontrolü
bool DynamicArray::operator!=(const DynamicArray& other) const {
	return !(*this == other);
}

//<<: Çýktý Operatörü 
ostream& operator<<(ostream& os, const DynamicArray& arr) {
	os << "Dizi: ";
	for (int i = 0; i < arr.size; i++) {
		os << arr.data[i];
		os << " ";
	}
	return os;
}