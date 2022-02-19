#include <cstddef>
#include <string>
#include <stack>
#include <iostream>

using namespace std;
#define COUNT 10

struct Node {
    char data;
    struct Node* left;
    struct Node* right;

    // val is the key or the value that
    // has to be added to the data part
    Node(char val)
    {
        data = val;

        // Left and right child for node
        // will be initialized to null
        left = NULL;
        right = NULL;
    }
};

Node* expressionTree(string str) {
    
    stack<Node*> bt; 

    struct Node* root = new Node(NULL);

    for (auto i = 0; i < str.length(); i++) {

        if (str[i] == '+' || str[i] == '*' || str[i] == '-') {

            root = new Node(str[i]);
            root->right = bt.top(); 

            bt.pop();
            root->left = bt.top(); 
       
            bt.pop();
            bt.push(root);
            continue;
        }

        struct Node* node = new Node(str[i]);

        bt.push(node);
    }
    
    
    return root;
}


Node* btToBST(struct Node* node) {
    
    if ((node->data > node->left->data) && (node->data < node->right->data)) {
        return node; 
    }

    


}
void printInorder(struct Node* node)
{
    if (node == NULL)
        return;

    /* first recur on left child */
    printInorder(node->left);

    /* then print the data of node */
    cout << node->data << " ";

    /* now recur on right child */
    printInorder(node->right);
}



int main()
{   
    expressionTree("ab+cde+**");
    
    printInorder(expressionTree("ab+cde+**"));

    struct Node* root = new Node(8);
    root->left = new Node(4);
    root->right = new Node(10);
    root->left->left = new Node(2);
    root->left->right = new Node(7);

    btToBST(root);

    return 0;
}