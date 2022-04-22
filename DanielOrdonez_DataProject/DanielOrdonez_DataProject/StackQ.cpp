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
	void push(T);
	void qpop();
	int searchStack(T); 
	void stackSort(); 
	bool empty(); 
	std::queue<T> firstQ, secondQ;
	size_t size;

};


template<typename T>
Stack<T>::Stack() {
	size = 0;
}

template<typename T>
Stack<T>::~Stack() {
	std::queue<T> emptyQ;

	if (!(firstQ.empty())) {

		firstQ = emptyQ;
		secondQ = emptyQ;
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

	secondQ = emptyQ;

}

template<typename T>
bool Stack<T>::empty() {

	return firstQ.empty(); 

}


template<typename T>
void Stack<T>::qpop() {
	
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


template<typename T> 
int Stack<T>::searchStack(T data) {

	while (!(firstQ.empty())) {
		 
		if (peek() == data) {
			std::cout << "Found" << "\n"; 
			return 1;
		}

		firstQ.pop(); 
	} 

	return -1; 
}


template<typename T>
void Stack<T>::stackSort() {

	Stack<T> stackTemp;
	Stack<T> stack;

	stack.firstQ = firstQ;

	if (stack.empty()) { return; }

	while (!(stack.empty())) {

		T data = stack.peek(); 
		stack.qpop();

		while (!(stackTemp.empty())
			&& stackTemp.peek() < data) {

			stack.push(stackTemp.peek());
			stackTemp.qpop();
		}

		stackTemp.push(data);

	}

	firstQ = stackTemp.firstQ; 
}