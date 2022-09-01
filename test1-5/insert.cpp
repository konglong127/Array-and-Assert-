#include "Array.h"

// -----------------------����ʹ�õ�λ��-----------------------
template<typename T>
int Array<T>::Length() {
  return this->Array_Length;
}

// -----------------------������λ��-----------------------
template<typename T>
int Array<T>::Size() {
	return this->Array_Size;
}

// -----------------------����洢�ռ�-----------------------
template<typename T>
int Array<T>::Capacity() {
	return this->Array_Size*sizeof(T);
}


// -----------------------��ָ��λ�����-----------------------
template<typename T>
Array<T>& Array<T>::insert(int pos, T value) {
	this->overflow();
	if (pos > this->Array_Length) {
		pos = this->Array_Length;
	}
	for (int i = this->Array_Length ; i > pos; i--) {
		this->pArr[i] = this->pArr[i-1];
	}
	this->pArr[pos] = value;
	this->Array_Length++;
	return *this;
}

// -----------------------��ָ��λ��ɾ��-----------------------
template<typename T>
Array<T>& Array<T>::splice(int pos) {
	if (pos<this->Array_Size) {
		for (int i = pos; i < this->Array_Length-1;i++) {
			this->pArr[i] = this->pArr[i + 1];
		}
		this->pArr[this->Array_Length - 1] = '/0';
		this->Array_Length--;
	}
	return *this;
}

// -----------------------��ָ��λ�ø���-----------------------
template<typename T>
Array<T>& Array<T>::update(int pos, T value) {
	if (pos<this->Array_Length) {
		this->pArr[pos] = value;
		this->Array_Length++;
	}
	return *this;
}