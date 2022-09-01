#include "Array.h"


// ------------------------数组初始化、析构、拷贝构造、溢出判断--------------------
template<typename T>
Array<T>::Array(int size) {
	this->Array_Size = size;
	this->Array_Length = 0;
	this->pArr = new T[size*sizeof(T)];
}

template<typename T>
Array<T>::~Array() {
	this->destroy();
}

template<typename T>
Array<T>::Array(const Array& arr) {
	this->Array_Length = arr.Array_Length;
	this->Array_Size = arr.Array_Size;
	this->pArr = new T[arr.Array_Size * sizeof(T)];

	for (int i = 0; i < this->Array_Length;++i) {
		this->pArr[i] = arr.pArr[i];
	}
}

template<typename T>
Array<T>::Array(const Array* arr) {
	this->Array_Length = arr->Array_Length;
	this->Array_Size = arr->Array_Size;
	this->pArr = new T[arr->Array_Size * sizeof(T)];

	for (int i = 0; i < this->Array_Length; ++i) {
		this->pArr[i] = arr->pArr[i];
	}
}

template<typename T>
void Array<T>::overflow() {
	if (this->Array_Size == this->Array_Length) {
		T* tmp = new T[this->Array_Size + 100];
		memcpy(tmp, this->pArr, this->Array_Size * sizeof(T));
		delete this->pArr;
		this->pArr = tmp;
		this->Array_Size += 100;
	}
}

template<typename T>
Array<T> Array<T>::operator=(const Array& arr) {
	cout << "operator=1" << endl;
	this->Array_Length = arr.Array_Length;
	this->Array_Size = arr.Array_Size;

	if (this->pArr != NULL)
		delete[]this->pArr;

	this->pArr = new T[arr.Array_Size * sizeof(T)];

	for (int i = 0; i < this->Array_Length; ++i) {
		this->pArr[i] = arr.pArr[i];
	}
	return *this;
}

template<typename T>
Array<T>* Array<T>::operator=(const Array* arr) {
	cout << "operator=2" << endl;
	this->Array_Length = arr.Array_Length;
	this->Array_Size = arr.Array_Size;

	if (this->pArr != NULL)
		delete[]this->pArr;

	this->pArr = new T[arr.Array_Size * sizeof(T)];

	for (int i = 0; i < this->Array_Length; ++i) {
		this->pArr[i] = arr.pArr[i];
	}
	return this;
}