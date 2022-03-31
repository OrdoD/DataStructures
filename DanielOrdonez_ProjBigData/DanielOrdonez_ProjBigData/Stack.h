// Stack.h 
// Author: Daniel Ordonez


#ifndef STACK_H
#define STACK_H

#include <queue>

template <typename T>
class Stack {

	std::queue<T> firstQ, secondQ;

public:

	~Stack();
	T peek();
	void push(T data);
	void pop();




};


#endif