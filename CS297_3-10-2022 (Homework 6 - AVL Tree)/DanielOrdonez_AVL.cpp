#include <string>
#include <iostream>
#include <vector>
#include <vector>


#define COUNT 15

template <typename T>
class Node
{
public:
    T key;
    Node<T>* left;
    Node<T>* right;
    int height;
    int getHeight(Node<T>* N);
    int max(int a, int b);
    Node<T>* newNode(T key);
    Node<T>* rightRotate(Node<T>* y);
    Node<T>* leftRotate(Node<T>* x);
    int getBalance(Node<T>* N);
    Node<T>* insert(Node<T>* node, T key);
    void preOrder(Node<T>* root);
    void print2DUtil(Node<T>* root, int space);
    void print2D(Node<T>* root);
    Node<T>* deleteNode(Node<T>* root, T key);
    Node<T>* minValueNode(Node<T>* node);
};


int max(int a, int b);

template <typename T>
int Node<T>::getHeight(Node<T>* N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

template <typename T>
int Node<T>::max(int a, int b)
{
    return (a > b) ? a : b;
}


template <typename T>
Node<T>* Node<T>::newNode(T key)
{
    Node<T>* node = new Node<T>();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; 
    return(node);
}

template <typename T>
Node<T>* Node<T>::rightRotate(Node<T>* y)
{
    Node<T>* x = y->left;
    Node<T>* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(getHeight(y->left),
        getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left),
        getHeight(x->right)) + 1;

    // Return new root
    return x;
}

template <typename T>
Node<T>* Node<T>::leftRotate(Node<T>* x)
{
    Node<T>* y = x->right;
    Node<T>* T2 = y->left;

    y->left = x;
    x->right = T2;


    x->height = max(getHeight(x->left),
        getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left),
        getHeight(y->right)) + 1;


    return y;
}
template <typename T>
int Node<T>::getBalance(Node<T>* N)
{
    if (N == NULL)
        return 0;
    return getHeight(N->left) - getHeight(N->right);
}



template <typename T>
Node<T>* Node<T>::insert(Node<T>* node, T key)
{
   
    if (node == NULL)
        return(newNode(key));

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else 
        return node;

   
    node->height = 1 + max(getHeight(node->left),
        getHeight(node->right));


    int balance = getBalance(node);


    if (balance > 1 && key < node->left->key) {
        return rightRotate(node);
    }


    if (balance < -1 && key > node->right->key) {
        return leftRotate(node);
    }


    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }


    return node;
}

template <typename T>
void Node<T>::preOrder(Node<T>* root)
{
    if (root != NULL)
    {
        std::cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

template <typename T>
void Node<T>::print2DUtil(Node<T>* root, int space)
{

    if (root == NULL)
        return;

   
    space += COUNT;


    print2DUtil(root->right, space);


    std::cout << std::endl;
    for (int i = COUNT; i < space; i++)
        std::cout << " ";
    std::cout << root->key << "\n";

    // Process left child
    print2DUtil(root->left, space);
}

template <typename T>

void Node<T>::print2D(Node<T>* root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}

template <typename T>
Node<T>* Node<T>::minValueNode(Node<T>* node)
{
    Node<T>* current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

template <typename T>
Node<T>* Node<T>::deleteNode(Node<T>* root, T key)
{


    if (root == NULL)
        return root;


    if (key < root->key)
        root->left = deleteNode(root->left, key);

    else if (key > root->key)
        root->right = deleteNode(root->right, key);


    else
    {

        if ((root->left == NULL) ||
            (root->right == NULL))
        {
            Node<T>* temp = root->left ?
                root->left :
                root->right;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else {

                *root = *temp;
                free(temp);
            }
                
        }
        else
        {
          
            Node<T>* temp = minValueNode(root->right);

       
            root->key = temp->key;

            root->right = deleteNode(root->right,
                temp->key);
        }
    }


    if (root == NULL)
        return root;


    root->height = 1 + max(getHeight(root->left),
        getHeight(root->right));


    int balance = getBalance(root);


    if (balance > 1 &&
        getBalance(root->left) >= 0)
        return rightRotate(root);


    if (balance > 1 &&
        getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }


    if (balance < -1 &&
        getBalance(root->right) <= 0)
        return leftRotate(root);


    if (balance < -1 &&
        getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}


int main() {

    Node<std::string>* root = NULL;

    std::vector<std::string> presidents = { "Harry S.Truman", "Dwight D.Eisenhower",
            "John F.Kennedy", "Lyndon B.Johnson", "Richard M.Nixon",
            "Gerald R.Ford", "Jimmy Carter", "Ronald Reagan", "George Bush",
            "Bill Clinton", "George W.Bush", "Barak Obama", "Donald J.Trump", "Joseph R.Biden" };


    for (auto i = 0; i < presidents.size(); i++) {

            root = root->insert(root, presidents[i]);

        }


    root->print2D(root);

    root->deleteNode(root, "Lyndon B.Johnson");
    std::cout << "\n\n\n\n\n\n\n\n\n\n"; 
    root->print2D(root);

    return 0;


}