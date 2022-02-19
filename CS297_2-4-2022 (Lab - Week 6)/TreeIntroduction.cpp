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

    return 0;
}