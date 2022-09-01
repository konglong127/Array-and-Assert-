#include "Array.h"

template<typename T>
bool Array<T>::clear() {
	this->Array_Length = 0;
	this->pArr[0] = '/0';
	return true;
}

template<typename T>
bool Array<T>::destroy() {
	if (this->pArr != NULL) {
		this->clear();
		this->Array_Size = 0;
		delete[] this->pArr;
		this->pArr = NULL;
	}
	return true;
}