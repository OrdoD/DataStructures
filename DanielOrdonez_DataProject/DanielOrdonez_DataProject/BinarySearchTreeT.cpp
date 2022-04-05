// BinarySearchTreT.cpp 
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
class BinarySearchTree {
	T data;
	BinarySearchTree* left; 
	BinarySearchTree* right; 

public: 

	BinarySearchTree(T);
	~BinarySearchTree(); 
	BinarySearchTree* append(BinarySearchTree*, T);
	void search(BinarySearchTree* root, T target);
	void Inorder(BinarySearchTree* root);


};


template <typename T>
BinarySearchTree<T>::BinarySearchTree(T data) {

	this->data = data; 
	left = NULL;
	right = NULL; 
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {

	free(left); 
	free(right); 
}


template <typename T>
BinarySearchTree<T>* BinarySearchTree<T>::append(BinarySearchTree* root, T data) {

	if (root == NULL) {return new BinarySearchTree<T>(data);}

	(data < root->data) ? root->left = append(root->left, data) : root->right = append(root->right, data); 

	return root;
	
}


template <typename T>
void BinarySearchTree<T>::search(BinarySearchTree* root, T target) {

	if (root == NULL || root == target) { return root; }

	if(root->data > target) {
		
		return search(root->right, target); 
	}

	return search(root->left, target);
}