// VectorT.cpp 
// Author: Daniel Ordonez

#include <iostream>

// Vector functions (Array Implementation): insert(), resizeArr(), ctor 
// Example:
//    Vector<int> myVec; 
//    
//	  myVec.insert(10);
//    myVec.insert(30);
//	  myVec.insert(40); 
//	  myVec.insert(50); 


template <typename T>
class VectorT {


public: 
	T* arr;
	VectorT(); 
	void insert(T); 
	int currIndex;
	size_t size;
	void remove();
	int getSize();
	void printArr();
	int vectorSearch(T);

private: 
	void resizeArr();

};



template <typename T>
VectorT<T>::VectorT() {

	size = 10; 
	currIndex = 0; 
	arr = new T[size];

}



template <typename T>
void VectorT<T>::resizeArr() {

	if (currIndex >= size) {
		T* newArr = new T[2 * size];

		for (auto i = 0; i <= currIndex - 1; i++) {
			newArr[i] = arr[i];
		}

		size = 2 * size;
		delete[] arr;
		arr = newArr;
		return;
	}

	std::cout << "Size is still not at max capacity" << "\n"; 

}

template <typename T>
int VectorT<T>::getSize() {

	return size;

}

template <typename T>
void VectorT<T>::insert(T data) {
	
	if (!(currIndex >= size)) {
		arr[currIndex] = data;
		currIndex++;
		return;
	}

	resizeArr();
	arr[currIndex] = data;
	currIndex++;
	return;

}

template <typename T>
void VectorT<T>::printArr() {

	for (auto i = 0; i < currIndex; i++) {
		std::cout << "arr[" << arr[i] << "]" << "\n";
	}
}

template <typename T> 
void VectorT<T>::remove() {

		if(currIndex == 0) { 
			return;
		}
		if (currIndex <= (size / 2) && (size != 10)) {

			T* newArr = new T[(size / 2)];

			for (auto i = 0; i <= currIndex - 1; i++) {
				newArr[i] = arr[i];
			}

			size /= 2;
			delete[] arr;
			arr = newArr;
			currIndex--; 
			return;
		}


	currIndex--;
	arr[currIndex] = 0; 
}



template <typename T>
int VectorT<T>::vectorSearch(T data) {

	for (auto i = 0; i < currIndex; i++) {
		std::cout << arr[i] << "\n";
		if (arr[i] == data) {
			std::cout << "Found " << arr[i]  << " at " << currIndex-1 <<  "\n";
			return 1; 
		}
	}

	return -1; 
}
