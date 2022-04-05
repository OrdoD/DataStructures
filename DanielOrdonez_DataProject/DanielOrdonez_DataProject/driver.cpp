#include <iostream>
#include <queue>
#include <string>
#include <iostream>
#include "StackQ.cpp"
#include "VectorT.cpp"
#include "BinarySearchTreeT.cpp"
#include <fstream>
#include <chrono>
using namespace std::chrono;

int main() {

	Stack<std::string> mystr;

	VectorT<int> myVec(9);

	BinarySearchTree<int>* root = NULL;
	BinarySearchTree<int> b = NULL;

	root = b.append(root, 99324);

	std::string myText;
	long long count=1; 


	std::ifstream MyReadFile("001_Data_Set_Zipcode_5_Digit_100kitems.txt");

	auto start = high_resolution_clock::now();
	
	while (getline(MyReadFile, myText)) {

		b.append(root, stoi(myText));
		std::cout << count++ << "\n";
	}

	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<microseconds>(stop - start);


	std::cout << "Time taken by function: "
		<< duration.count() << " microseconds" << "\n";
	
	// Close the file
	MyReadFile.close();



}