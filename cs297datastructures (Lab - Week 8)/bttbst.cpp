#include <iostream> 
#include <stack>
#include <vector>
#include <algorithm>

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


void inorderTravers(Node* root, std::vector<int>& inorder) {



    if (root == NULL) {

        return;

    }

    inorderTravers(root->left, inorder);


    inorder.push_back(root->data);



    inorderTravers(root->right, inorder);

}


std::vector<int> inorderTraversal(Node* root) {

    std::vector<int> inorder;

    inorderTravers(root, inorder);


    std::sort(std::begin(inorder), std::end(inorder));

    return inorder;

}


void BST(Node*& root) {
    
    static std::vector<int> in = inorderTraversal(root);
    static int counter = 0; 

    if (root == NULL) {

        return; 
    }
    
    BST(root->left);

    root->data = in[counter];
    counter++; 

    BST(root->right); 

}


void inOrder(Node* root) {

    if (root == NULL) {

        return;
    }


    inOrder(root->left);

    std::cout << root->data << " ";

    inOrder(root->right);
}



void minimum(Node* root, int& min) {

    static int val = root->data; 


    if(root == NULL){

        return;

    }

    minimum(root->left, min); 

    if (val > root->data) {
        val = root->data; 
    }


    minimum(root->left,min);


    min = val; 

    
}

int minimumVal(Node*& root) {
    int min = 0;
    minimum(root, min);

    return min;

}



int main() {
    struct Node* root = new Node(10);
    root->left = new Node(2);
    root->left->left = new Node(8);
    root->left->right = new Node(4);
    root->right = new Node(7);
    
     BST(root); 

     inOrder(root);


     std::cout << minimumVal(root) << "\n"; 
}