#include <iostream>
#include <cstdlib>

#define FOR(i,c,a) for (int i = c; i <= a; i++)


template <class T> class Node {


public:
    Node<T>* next;
    T data;
};


using namespace std;


template <class T> class LinkedList {

public:
    T length;
    Node<T>* head;
    Node<T>* tail;

    LinkedList();
    ~LinkedList();
    void addToHead(T data);
    void addToTail(T data);
    void addAtPosition(T position, T data);
    void print();
    void concatenateList(LinkedList<T>& head1, LinkedList<T>& head2);
    void concatenateList();
    void deleteFirst();
    void deleteLast();
    void deleteAtPosition(T i);

    void operator+(LinkedList<T>& head);

};

template <class T>
LinkedList<T> ::LinkedList() {
    length = 0;
    head = NULL;
    tail = NULL;
}

template <class T>
LinkedList<T>::~LinkedList() {
    std::cout << "LIST DELETED";
}

template <class T>
void LinkedList<T>::addToHead(T data) {
    Node<T>* node = new Node<T>();
    node->data = data;
    node->next = head;
    head = node;
    if (length == 0) {
        tail = node;
    }
    length++;
}

template <class T>
void LinkedList<T>::addToTail(T data) {
    Node<T>* node = new Node<T>();
    node->data = data;
    node->next = NULL;
    if (length == 0) {
        node->next = head;
        head = node;
        tail = node;
    }
    else {
        tail->next = node;
        tail = node;
    }
    length++;
}

template <class T>
void LinkedList<T>::addAtPosition(T position, T data) {


    Node<T>* ptr = head;
    int count = 1;
    while (ptr->next != NULL) {
        count++;
        if (count == position) {
            Node<T>* node = new Node<T>();
            node->data = data;
            node->next = ptr->next;

            ptr->next = node;

        }
        else {
            ptr = ptr->next;
        }
    }

    length++;
}


template <class T>
void LinkedList<T>::deleteFirst()
{
    Node<T>* temp = new Node<T>();
    temp = head;
    head = head->next;
    delete temp;
}

template <class T>
void LinkedList<T>::deleteLast()
{
    Node<T>* current = new Node<T>();
    Node<T>* previous = new Node<T>();
    current = head;
    while (current->next != NULL)
    {
        previous = current;
        current = current->next;
    }
    tail = previous;
    previous->next = NULL;
    delete current;
}

template <class T>
void LinkedList<T>::deleteAtPosition(T pos)
{
    Node<T>* current = new Node<T>();
    Node<T>* previous = new Node<T>();
    current = head;
    for (int i = 1; i < pos; i++)
    {
        previous = current;
        current = current->next;
    }
    previous->next = current->next;
}


template <class T>
void LinkedList<T>::print() {
    Node<T>* ptr = head;
    int i = 1;
    while (ptr != NULL) {
        std::cout << i << ": " << ptr->data << std::endl;
        ptr = ptr->next;
        i++;
    }
}


template <class T> 
void LinkedList<T>::concatenateList(LinkedList<T> &head1, LinkedList<T> &head2) {

    Node<T>* ptr = head1;

    // Check if ptr -> head1 == NULL
    if (ptr == NULL) {

        head1 = head2;
        return head1;

    }

    while (ptr->next != NULL) {

        ptr = ptr->next;

    }

    ptr->next = head2;
    return head1;
    
}

template <class T>
void LinkedList<T>::operator+( LinkedList<T> &head) {
    
}


int main(int argc, char const* argv[])
{
    LinkedList<int>* list = new LinkedList<int>();
    list->addToHead(111);
    list->print();
    std::cout << "Add to head, List Length: " << list->length << std::endl;

    list->addToTail(222);
    list->print();
    std::cout << "Add to tail, List Length: " << list->length << std::endl;
    for (int i = 0; i < 6; ++i)
    {
        //list->addToHead(rand() % 100);
        list->addToHead((i + 1) * 10);
    }
    list->print();
    std::cout << "Add multiple nodes to head, List Length: " << list->length << std::endl;

    list->addToTail(333);
    list->print();
    std::cout << "Add to tail again, List Length: " << list->length << std::endl;

    list->addAtPosition(3, 007);
    list->print();
    std::cout << "Add to position 3, List Length: " << list->length << std::endl;

    list->deleteFirst();
    list->deleteLast();
    list->print();
    std::cout << "delete first delete last, List Length: " << list->length << std::endl;
    list->deleteAtPosition(6);
    list->print();
    std::cout << "delete node at position 6, List Length: " << list->length << std::endl;

    LinkedList<int>* list2 = new LinkedList<int>(); 

    list2->addToHead(340); 
    list2->addToHead(350); 
    list2->addToHead(500); 
    list2->addToTail(400);

    //delete list;
    return 0;
}