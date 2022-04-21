#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "StackQ.cpp"
#include "VectorT.cpp"
#include "BinarySearchTreeT.cpp"
#include <chrono>
using namespace std::chrono;

int main() {


	//// Binary Search Tree Object 
	//BinarySearchTree<int>* root = NULL;
	//BinarySearchTree<int> b = NULL;

	//root = b.append(root, NULL);

	std::string myText;
	//long long count=1; 

	std::string file = "003_Data_Set_Zipcode_5_Digit_10kitems.txt";

	//// Binary Search Insertion
	//// Input Size: 100_000 
	//// Using STL std::chrono 
	//std::ifstream MyReadFile(file);

	//auto start = high_resolution_clock::now();
	//
	//while (getline(MyReadFile, myText)) {

	//	b.append(root, stoi(myText));
	//}

	//auto stop = high_resolution_clock::now();

	//auto duration = duration_cast<milliseconds>(stop - start);

	//std::ofstream myfile;
	//myfile.open("output_data.txt");
	//myfile << "Binary Search Tree Insertion \n";
	//myfile << "Time taken by function: " << duration.count() << " milliseconds \n";
	//myfile << "\n\n";
	//myfile.close();


	//MyReadFile.close();



	//// Vector Object 

	VectorT<int> myVec;

	//// Vector using Array Implementation Insertion
	//// Input Size: 100_000 
	//// Using STL std::chrono 
	std::ifstream VectorInsert(file);

	auto startOne = high_resolution_clock::now();

	while (getline(VectorInsert, myText)) {

		myVec.insert(stoi(myText));
	}

	auto stopOne = high_resolution_clock::now();

	auto durationOne = duration_cast<milliseconds>(stopOne - startOne);

	std::ofstream myfileOne;
	myfileOne.open("output_data.txt", std::ios_base::app);
	myfileOne << "Vector using Array Implementation Insertion Insertion \n";
	myfileOne << "Time taken by function: " << durationOne.count() << " milliseconds \n";
	myfileOne << "\n\n";
	myfileOne.close();

	VectorInsert.close();


	//// Stack Object 

	//Stack<int> myInt;

	//// Stack Using STL Queue Insertion
	//// Input Size: 100_000 
	//// Using STL std::chrono 
	//std::ifstream StackInsert(file);

	//auto startTwo = high_resolution_clock::now();

	//while (getline(StackInsert, myText)) {

	//	myInt.push(stoi(myText));

	//}

	//auto stopTwo = high_resolution_clock::now();

	//auto durationTwo = duration_cast<milliseconds>(stopTwo - startTwo);

	//StackInsert.close();

	//std::ofstream myfileTwo;
	//myfileTwo.open("output_data.txt", std::ios_base::app);
	//myfileTwo << "Stack Insertion \n";
	//myfileTwo << "Time taken by function: " << durationTwo.count() << " milliseconds \n";
	//myfile << "\n\n";
	//myfileTwo.close();



}