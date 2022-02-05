//#include <iostream>
//#include <cstdlib>
//
//class Node
//{
//public:
//    Node* next;
//    Node* prev = next;
//    int data;
//};
//using namespace std;
//class LinkedList
//{
//public:
//    int length;
//    Node* head;
//    LinkedList();
//    ~LinkedList();
//    void add(int data);
//    void print();
//    void deleteFirst();
//    void deleteLast();
//    void printInReverse(); 
//    void deleteAtPosition(Node* head, int pos);
//};
//LinkedList::LinkedList() {
//    this->length = 0;
//    this->head = NULL;
//}
//LinkedList::~LinkedList() {
//    std::cout << "LIST DELETED";
//}
//void LinkedList::add(int data) {
//    Node* node = new Node();
//    node->data = data;
//    node->next = this->head;
//    this->head = node;
//    this->length++;
//}
//void LinkedList::deleteFirst()
//{
//    Node* temp = new Node();
//    temp = head;
//    head = head->next;
//    delete temp;
//}
//void LinkedList::deleteLast()
//{
//    Node* current = new Node();
//    Node* previous = new Node();
//    current = head;
//    while (current->next != NULL)
//    {
//        previous = current;
//        current = current->next;
//    }
//    Node* tail = previous;
//    previous->next = NULL;
//    delete current;
//}
//
//void LinkedList::deleteAtPosition(Node* head, int pos)
//{
//    Node* current = new Node;
//    Node* previous = new Node;
//    current = head;
//    for (int i = 1; i < pos; i++)
//    {
//        previous = current;
//        current = current->next;
//    }
//    previous->next = current->next;
//}
//void LinkedList::print() {
//    Node* head = this->head;
//    int i = 1;
//    while (head) {
//        std::cout << i << ": " << head->data << std::endl;
//        head = head->next;
//        i++;
//    }
//}
//
//void LinkedList::printInReverse() {
//    Node* head = this->head;
//    Node* pos = NULL; 
//
//    while (head) {
//
//        pos = head; 
//        head = head->next; 
//        
//        if (head->next == NULL) {
//
//            break; 
//        }
//
//    }
//
//
//    
//}
//
//int main(int argc, char const* argv[])
//{
//    LinkedList* list = new LinkedList();
//    for (int i = 0; i < 100; ++i)
//    {
//        list->add(rand() % 100);
//    }
//    list->print(); 
//    std::cout << "List Length: " << list->length << std::endl;
//    delete list;
//    return 0;
//}