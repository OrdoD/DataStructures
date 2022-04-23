#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include "StackQ.cpp"  
#include "VectorT.cpp"
#include "BinarySearchTreeT.cpp"
#include <chrono>
#include <stack>
using namespace std::chrono;



int main() {


	// Binary Search Tree Object 
	//BinarySearchTree<std::string>* root = NULL;
	//BinarySearchTree<std::string> b(" ");

	//root = b.append(root, "Apple");
	std::string myText;
	//std::string myTextt;
	//////long long count=1; 

	std::string file = "test.txt";

	// Binary Search Insertion
	// Input Size: 100_000 
	// Using STL std::chrono 

	//std::ifstream MyReadFile(file);
	//std::ifstream MyReadFilee(file);

	//std::vector<std::string> vec; 

	//while (getline(MyReadFile, myText)) {

	//	b.append(root, myText);

	//}

	//auto start = high_resolution_clock::now();
	//
	//b.inorder(root);

	//auto stop = high_resolution_clock::now();

	//auto duration = duration_cast<nanoseconds>(stop - start);

	//std::ofstream myfile;
	//myfile.open("output_data.txt");
	//myfile << "Binary Search Tree Deletion \n";
	//myfile << "Time taken by function: " << duration.count() << " milliseconds \n";
	//myfile << "\n\n";
	//myfile.close();

	//MyReadFilee.close();
	//MyReadFile.close();



	//Vector Object 

	//VectorT<std::string> myVec;

	 //Vector using Array Implementation Insertion
	 //Input Size: 100_000 
	 //Using STL std::chrono 
	//std::ifstream VectorInsert(file);

	//
	//while (getline(VectorInsert, myText)) {
	//	
	//	myVec.insert(myText);

	//}
	//
	//auto startOne = high_resolution_clock::now();

	//myVec.qSort(); 

	//auto stopOne = high_resolution_clock::now();

	//auto durationOne = duration_cast<nanoseconds>(stopOne - startOne);

	//std::ofstream myfileOne;
	//myfileOne.open("output_data.txt", std::ios_base::app);
	//myfileOne << "Vector using Array Implementation Search Best Case\n";
	//myfileOne << "Time taken by function: " << durationOne.count() << " milliseconds \n";
	//myfileOne << "\n\n";
	//myfileOne.close();

	//VectorInsert.close();




	// Stack Object 

	Stack<std::string> myInt;

	////// Stack Using STL Queue Insertion
	////// Input Size: 100_000 
	////// Using STL std::chrono 
	std::ifstream StackInsert("DescedingOrder10k.txt");

	while (getline(StackInsert, myText)) {

		myInt.push(myText);

	}

	std::stack<std::string> s; 

	while (getline(StackInsert, myText)) {

		s.push(myText);

	}

	while(!s.empty()) {

		myInt.firstQ.push(s.top());
		s.pop();
	}

	std::cout << "\n\n\n";
	auto startTwo = high_resolution_clock::now();

	myInt.stackSort();

	auto stopTwo = high_resolution_clock::now();

	auto durationTwo = duration_cast<milliseconds>(stopTwo - startTwo);

	StackInsert.close();

	std::ofstream myfileTwo;
	myfileTwo.open("output_data.txt", std::ios_base::app);
	myfileTwo << "Worst Case 10k Items \n";
	myfileTwo << "Time taken by function: " << durationTwo.count() << " milliseconds \n";
	myfileTwo << "\n\n";
	myfileTwo.close();



	Stack<std::string> myInt1;

	////// Stack Using STL Queue Insertion
	////// Input Size: 100_000 
	////// Using STL std::chrono 
	std::ifstream StackInsert1("DescedingOrder50k.txt");

	while (getline(StackInsert1, myText)) {

		myInt1.push(myText);

	}

	std::stack<std::string> s1;

	while (getline(StackInsert1, myText)) {

		s1.push(myText);

	}

	while (!s1.empty()) {

		myInt1.firstQ.push(s1.top());
		s1.pop();
	}

	std::cout << "\n\n\n";
	auto startTwo1 = high_resolution_clock::now();

	myInt1.stackSort();

	auto stopTwo1 = high_resolution_clock::now();

	auto durationTwo1 = duration_cast<milliseconds>(stopTwo1 - startTwo1);

	StackInsert1.close();

	std::ofstream myfileTwo1;
	myfileTwo1.open("output_data.txt", std::ios_base::app);
	myfileTwo1 << "Worst Case 50k Items \n";
	myfileTwo1 << "Time taken by function: " << durationTwo1.count() << " milliseconds \n";
	myfileTwo1 << "\n\n";
	myfileTwo1.close();



	Stack<std::string> myInt2;

	////// Stack Using STL Queue Insertion
	////// Input Size: 100_000 
	////// Using STL std::chrono 
	std::ifstream StackInsert2("DescedingOrder100k.txt");

	while (getline(StackInsert2, myText)) {

		myInt2.push(myText);

	}

	std::stack<std::string> s2;

	while (getline(StackInsert2, myText)) {

		s2.push(myText);

	}

	while (!s2.empty()) {

		myInt2.firstQ.push(s2.top());
		s2.pop();
	}
	

	auto startTwo2 = high_resolution_clock::now();

	myInt2.stackSort();

	auto stopTwo2 = high_resolution_clock::now();

	auto durationTwo2 = duration_cast<milliseconds>(stopTwo2 - startTwo2);

	StackInsert2.close();

	std::ofstream myfileTwo2;
	myfileTwo2.open("output_data.txt", std::ios_base::app);
	myfileTwo2 << "Worst Case 100k Items \n";
	myfileTwo2 << "Time taken by function: " << durationTwo2.count() << " milliseconds \n";
	myfileTwo2 << "\n\n";
	myfileTwo2.close();



}