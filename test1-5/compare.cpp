#include "./Array.h"

template<typename T>
bool Array<T>::operator==(const Array<T>& arr1) {
	if (this->Array_Length == arr1.Array_Length) {
		for (int i = 0; i < this->Array_Length; ++i) {
			if (this->pArr[i] != arr1.pArr[i]) {
				return false;
			}
		}
		return true;
	}
	else {
		return false;
	}
}

template<typename T>
bool Array<T>::operator!=(const Array<T>& arr1) {
	if (this->Array_Length == arr1.Array_Length) {
		for (int i = 0; i < this->Array_Length; ++i) {
			if (this->pArr[i] != arr1.pArr[i]) {
				return true;
			}
		}
		return false;
	}
	else {
		return true;
	}
}

template<typename T>
bool Array<T>::operator>=(const Array<T>& arr1) {
	if (this->Array_Length>=arr1.Array_Length) {
		return true;
	}
	else {
		return false;
	}
}

template<typename T>
bool Array<T>::operator<=(const Array<T>& arr1) {
	if (this->Array_Length <= arr1.Array_Length) {
		return true;
	}
	else {
		return false;
	}
}

template<typename T>
bool Array<T>::operator>(const Array<T>& arr1) {
	if (this->Array_Length > arr1.Array_Length) {
		return true;
	}
	else {
		return false;
	}
}

template<typename T>
bool Array<T>::operator<(const Array<T>& arr1) {
	if (this->Array_Length < arr1.Array_Length) {
		return true;
	}
	else {
		return false;
	}
}