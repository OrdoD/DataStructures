#include <iostream>
#include <stack> 


//class Queue {
//
//	std::stack <int> stack1, stack2; 
//
//public: 
//	bool isEmpty();
//	void enqueue(int e); 
//	void dequeue(); 
//	void display(); 
//
//	void enqueue();
//
//};
//
//
//
//int main() {
//
//}
//

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    // val is the key or the value that
    // has to be added to the data part
    Node(int val)
    {
        data = val;

        // Left and right child for node
        // will be initialized to null
        left = NULL;
        right = NULL;
    }
};


void inOrder(Node* root) {

    if (root == NULL) {
        
        return; 
    }

    
    inOrder(root->left); 

    std::cout << root->data << " ";

    inOrder(root->right); 
}


void preOrder(Node* root) {

    std::cout << root->data << " ";

    if (root == NULL) {

        return;
    }

    inOrder(root->left);


    inOrder(root->right);


    
}

void postOrder(Node* root) {



    if (root == NULL) {

        return;
    }

    inOrder(root->left);


    inOrder(root->right);

    std::cout << root->data << " ";

}


//int findCount(Node* head, int dataToFind) {
//
//    unsigned int count = 0; 
//    
//    Node* ptrHead = head; 
//
//    while (ptrHead != NULL) {
//
//        
//        if (ptrHead->data == dataToFind) {
//
//            count++;
//
//        }
//        ptrHead = ptrHead->next;
//    }
//    return count; 
//}

int main(){

    struct Node* root = new Node(8);
    root->left = new Node(3);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->left->right->right = new Node(7);
    root->left->right->left = new Node(4);
    root->right = new Node(10);
    root->right->right = new Node(14);
    root->right->left = new Node(13);
    std::cout << "In Order" << "\n"; 
    inOrder(root); 

    std::cout << "\n\n\n"; 

    std::cout << "Pre Order" << "\n";

    preOrder(root); 


    std::cout << "\n\n\n";

    std::cout << "Post Order" << "\n";


    postOrder(root); 


}