#include "Array.h"


// ---------------------Í·²å----------------------
template<typename T>
Array<T>& Array<T>::unshift(T value) {
	this->overflow();
	for (int i = this->Array_Length; i >0;--i) {
		this->pArr[i] = this->pArr[i - 1];
	}
	this->pArr[0] = value;
	this->Array_Length++;
	return *this;
}

// ---------------------Î²²å----------------------
template<typename T>
Array<T>& Array<T>::push(T value) {
	this->overflow();
	this->pArr[this->Array_Length] = value;
	this->Array_Length++;
	return *this;
}
