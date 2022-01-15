#include <iostream>


int sumOfNums(int n);

int main() {

	std::cout << sumOfNums(1000);

}


int sumOfNums(int n) {

	return (n * (1 + n)) / (2);

}