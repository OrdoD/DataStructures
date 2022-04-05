// VectorT.cpp 
// Author: Daniel Ordonez

#include <iostream>

// Vector functions (Array Implementation): insert(), resizeArr(), ctor, dtor 
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
	VectorT(int); 
	~VectorT(); 
	void insert(T data); 
	int currIndex;
	size_t size;

private: 
	void resizeArr();

};


template <typename T>
VectorT<T>::VectorT(int s) {

	size = s; 
	currIndex = 0; 
	arr = new T[size];

}

template <typename T>
VectorT<T>::~VectorT() {

	delete [] arr; 
}

template <typename T>
void VectorT<T>::resizeArr() {

	if (currIndex >= size) {
		T* newArr = new T[2 * size];

		for (auto i = 0; i < size; i++) {
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