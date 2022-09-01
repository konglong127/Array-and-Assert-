#pragma once
#ifndef ARRAY_H_
#define ARRAY_H_

#include <iostream>
using namespace std;

template<class T>
class Array {
private:
	T* pArr;
	int Array_Length;
	int Array_Size;
	void overflow();
public:
	// init.cpp
	Array(int size = 0);
	Array(const Array& arr);
	Array(const Array* arr);
	~Array();
	Array operator=(const Array& arr);
	Array* operator=(const Array* arr);
	
	// push.cpp
	Array& unshift(T value);
	Array& push(T value);

	// pop.cpp
	Array& shift();
	Array& pop();

	// insert.cpp
	int Length();
	int Size();
	int Capacity();
	Array& insert(int pos, T value);
	Array& splice(int pos);
	Array& update(int pos, T value);


	// destory();
	bool clear();
	bool destroy();

	bool operator==(const Array<T>& arr1);
	bool operator!=(const Array<T>& arr1);
	bool operator>=(const Array<T>& arr1);
	bool operator<=(const Array<T>& arr1);
	bool operator>(const Array<T>& arr1);
	bool operator<(const Array<T>& arr1);



	//get.cpp
	T& operator[](int pos) {
		return this->pArr[pos];
	}
	T& get(int pos) {
		return this->pArr[pos];
	}
};

#endif //TEST1_ARRAY_H