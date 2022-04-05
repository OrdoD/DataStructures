// StackQ.cpp 
// Author: Daniel Ordonez


#include <queue>
#include <iostream>

// Stack functions: (pop, push, peek) , ctor, dtor
// Example:
//    Stack<int> nums; 
//    nums.push(10); 
//	  nums.push(30); 
//    nums.push(40); 
//	  nums.pop(); 
//	  nums.peek();

template <typename T>
class Stack {


public:
	Stack();
	~Stack();
	T peek() ;
	void push(T data);
	void pop();
	std::queue<T> firstQ, secondQ;
	size_t size;

};


template<typename T>
Stack<T>::Stack() {
	size = 0;
}

template<typename T>
Stack<T>::~Stack() {
	std::queue<T> emptyQ, emptyQ1;

	if (!firstQ.empty()) {
		swap(firstQ, emptyQ);
		swap(secondQ, emptyQ1);
	}

}

template<typename T>
void Stack<T>::push(T data) {

	secondQ.push(data);

	while (!(firstQ.empty())) {
		secondQ.push(peek());
		firstQ.pop();
	}

	firstQ = secondQ;

	std::queue<T> emptyQ;

	std::swap(secondQ, emptyQ);

}

template<typename T>
void Stack<T>::pop() {
	
	if (firstQ.empty()) { std::cout << "Stack is empty" << "\n"; }
	firstQ.pop();

}

template<typename T>
T Stack<T>::peek() {
	
	if (firstQ.empty()) { 

		std::cout << "Stack is empty" << "\n"; 
		return 0; 
	}

	return firstQ.front();

}
