#include <iostream>

int sumOfNums(int n); 
bool isMultiple(int n, int m);
void printMultiArray(int** A, int m, int n); 

int main() {
	int x[3][2] = { {3,5}, {5,4} ,{3,4} }; 

	int* ptr1; 
	int** ptr2; 

	ptr1 = &x;

	ptr2 = &ptr1; 

	std::cout << sumOfNums(1000) << "\n";
	std::cout << isMultiple(6, 54) << "\n";
	printMultiArray(ptr2, 2, 3);
}


int sumOfNums(int n) {

	return (n * (1 + n)) / (2);
	
}

bool isMultiple(int n, int m) { 

	return (m % n == 0);


}


void printMultiArray(int** A, unsigned int m, unsigned int n) {

	for (int i = 0; i < m; i++) {

		for (int z = 0; z < n; z++) {

			std::cout << A[i][z] << "\n";

		}
		std::cout << std::endl;
	}

}