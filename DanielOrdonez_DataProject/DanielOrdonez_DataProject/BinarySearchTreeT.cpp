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
	BinarySearchTree<T>* search(BinarySearchTree* root, T target);
	BinarySearchTree<T>* minVal(BinarySearchTree* root);
	BinarySearchTree<T>* remove(BinarySearchTree* root, T data);
	void inorder(BinarySearchTree* root);
	

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
BinarySearchTree<T>* 
BinarySearchTree<T>::append(BinarySearchTree* root, T data) {

	if (root == NULL) {return new BinarySearchTree<T>(data);}

	(data < root->data) ? root->left = append(root->left, data) 
		: root->right = append(root->right, data); 

	return root;
	
}


template <typename T>
BinarySearchTree<T>* BinarySearchTree<T>::search(BinarySearchTree* root, T target) {

	if (root == NULL || root->data == target) { return root; }

	if(root->data > target) { return search(root->left, target);}

	return search(root->right, target);
}


template <typename T>
BinarySearchTree<T>* BinarySearchTree<T>::minVal(BinarySearchTree* root) {

	BinarySearchTree* curr = root; 

	while (curr && curr->left != NULL) {
		curr = curr->left; 
	}
	return curr; 

}


template <typename T>
void BinarySearchTree<T>::inorder(BinarySearchTree* root) {

	if (root == NULL) { return;  }

	inorder(root->left);

	std::cout << root->data << " "; 

	inorder(root->right);
}

template <typename T>
BinarySearchTree<T>* BinarySearchTree<T>::remove(BinarySearchTree* root, T data) {

	if (root == NULL) { return root; } 

	if (data > root->data) { root->right = remove(root->right, data); }

	else if (data < root->data) { root->left = remove(root->left, data); }

	else {

		if (root->left == NULL &&
			root->right == NULL) {
			return NULL;
		}

		
		if (root->left == NULL) {
			BinarySearchTree* tree = root->right;
			free(root); 
			return tree;
		}

		if (root->right == NULL) {
			BinarySearchTree* tree = root->left;
			free(root);
			return tree;
		}

		BinarySearchTree* bst = minVal(root->right);

		root->data = bst->data; 

		root->right = remove(root->right, bst->data); 
	}
	return root; 

}