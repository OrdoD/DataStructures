/*
Daniel Ordonez
CS297
Homework 1
*/
#include <string>
#include <iostream>
#include <exception>


class ParallelException: std::exception {
public: 

	ParallelException(std::string errorMessage)
		: errorMessage(errorMessage) {}


	std::string returnMessage() {

		return errorMessage; 
	}

private: 
	 const std::string errorMessage;
};


class Line {

private: 
	double a, b; 

public: 
	// Line constructor to create a line w/ two points
	Line(double a, double b) 
		: a(a), b(b) {}


	double intersect(Line& objLine) {

		double intersection; 

		(objLine.a == a) ? throw(ParallelException("The lines are parallel")) : intersection = ((objLine.b - b) / (a - objLine.a));
		
		return intersection;

	}

};

int main() {

	double x, y, xp, yp; 

	std::cout << "Please enter the first pair of coordinates separated by space: "; 
	std::cin >> x >> y; 
	std::cout << "Please enter the second pair of coordinates separated by space: ";
	std::cin >> xp >> yp;

	Line fLine(x, y); 
	Line sLine(xp, yp);
	
	try {

		std::cout << "The x coordinate of the intersection is: " << (fLine.intersect(sLine)) << "\n";

	}
	catch (ParallelException& exception) {


		std::cout << "Exception thrown: " << exception.returnMessage() << "\n";


		}
}
	

