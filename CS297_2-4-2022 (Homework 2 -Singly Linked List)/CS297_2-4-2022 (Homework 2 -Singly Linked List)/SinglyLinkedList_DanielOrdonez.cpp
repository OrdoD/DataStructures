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
    void deleteFirst();
    void deleteLast();
    void deleteAtPosition(T i);

    void concatenateList(Node<T>*& head1, Node<T>*& head2);

    LinkedList<T> operator+(LinkedList<T>& other);

};

template <class T>
LinkedList<T> ::LinkedList() {
    length = 0;
    head = NULL;
    tail = NULL;
}

template <class T>
LinkedList<T>::~LinkedList() {
   
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
void concatenateList(Node<T>*& head1, Node<T>*& head2) {

    Node<T>* ptr = head1;

    // Check if ptr -> head1 == NULL
    if (ptr->next == NULL) {

        head1 = head2;
        return;
    }

    while (ptr->next != NULL) {

        ptr = ptr->next;

    }

    ptr->next = head2;
    return;

}

template <class T>
LinkedList<T> LinkedList<T>::operator+(LinkedList<T>& other) {

    LinkedList<T> temp;

    for (Node<T>* cur = head; cur != NULL; cur = cur->next) {
        temp.addToTail(cur->data);
    }

    for (Node<T>* cur = other.head; cur != NULL; cur = cur->next) {
        temp.addToTail(cur->data);
    }

    return temp;
}



int main(int argc, char const* argv[])
{
    LinkedList<int> list;
    list.addToHead(111);
    list.print();
    std::cout << "Add to head, List Length: " << list.length << "\n\n";


    list.addToTail(222);
    list.print();
    std::cout << "Add to tail, List Length: " << list.length << "\n\n";


    LinkedList<int> list2;
    cout << "LinkedList list2 Printed" << "\n";
    list2.addToHead(340);
    list2.addToHead(350);
    list2.addToHead(500);
    list2.addToHead(400);

    list2.print();

    LinkedList<int> list3 = list + list2; 

    cout << "New combined LinkedList list3 Printed Using Overloaded + operator" << "\n";

    list3.print();

    cout << "concatenateList()" << "\n\n\n";

    cout << "New list4 and list5 combined together with concatenateList()" << " \n";
    LinkedList<int>* list4 = new LinkedList<int>();
    list4->addToHead(111);
    list4->print();
    std::cout << "Add to head, List Length: " << list4->length << std::endl;

    list4->addToTail(222);
    list4->print();
    std::cout << "Add to tail, List Length: " << list4->length << std::endl;


    LinkedList<int>* list5 = new LinkedList<int>();

    list5->addToHead(340);
    list5->addToHead(350);
    list5->addToHead(500);
    list5->addToHead(400);


    concatenateList(list4->head, list5->head);


    list4->print();

    //delete list;
    return 0;
}


