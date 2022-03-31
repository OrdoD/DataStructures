// Stack.cpp 
// Author: Daniel Ordonez


#include <queue>

template <typename T>
class Stack {


public:
	Stack(); 
	~Stack();
	T peek();
	void push(T data);
	void pop();
	std::queue<T> firstQ, secondQ;
	int size;

};


template<typename T>
Stack<T>::Stack() {
	size = 0;
}

template<typename T>
Stack<T>::~Stack() {
	std::queue<T> emptyQ, emptyQ1;

	swap(firstQ, emptyQ);
	swap(secondQ, emptyQ1);

}

template<typename T>
void Stack<T>::push(T data) {

	if (data == NULL) {
		return; 
	}

	secondQ.push(data); 

	while (!(firstQ.empty())) {
		secondQ.push(firstQ.peek()); 
		firstQ.pop(); 
	}

	firstQ = secondQ; 

	std::queue<T> emptyQ; 

	std::swap(secondQ, emptyQ); 

}


template<typename T>
void Stack<T>::pop() {

	firstQ.pop(); 

}

template<typename T>
T Stack<T>::peek() {

	return firstQ.front(); 
	
}
