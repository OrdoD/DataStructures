// StackQ.h
// Author: Daniel Ordonez


#ifndef STACKQ_H  
#define STACKQ_H  


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



#endif