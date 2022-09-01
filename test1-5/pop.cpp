#include "Array.h"

//----------------------头删-------------------------
template<typename T>
Array<T>& Array<T>::shift() {
	if (this->Array_Length!=0) {
		for (int i = 0; i < this->Array_Length-1; ++i) {
			this->pArr[i] = this->pArr[i + 1];
		}
		this->pArr[this->Array_Length - 1]='/0';
		this->Array_Length--;
	}
	return *this;
}


// ----------------------尾删-------------------------
template<typename T>
Array<T>& Array<T>::pop() {
	if (this->Array_Length != 0) {
		this->pArr[this->Array_Length - 1] = '/0';
		this->Array_Length--;
	}
	return *this;
}
