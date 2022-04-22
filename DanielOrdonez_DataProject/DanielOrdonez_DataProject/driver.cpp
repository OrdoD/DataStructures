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


	// Binary Search Tree Object 
	//BinarySearchTree<int>* root = NULL;
	//BinarySearchTree<int> b = NULL;

	//root = b.append(root, 1004353);

	std::string myText;
	std::string myTextt;
	////long long count=1; 

	std::string file = "002_Data_Set_Buisiness_Names_50kitems.txt";

	// Binary Search Insertion
	// Input Size: 100_000 
	// Using STL std::chrono 

	//std::ifstream MyReadFile(file);
	//std::ifstream MyReadFilee(file);
	//while (getline(MyReadFile, myText)) {

	//	b.append(root, stoi(myText));
	//}

	//auto start = high_resolution_clock::now();

	//while (getline(MyReadFilee, myTextt)) {

	//	root = b.remove(root, stoi(myTextt));

	//}

	//auto stop = high_resolution_clock::now();

	//auto duration = duration_cast<milliseconds>(stop - start);

	//std::ofstream myfile;
	//myfile.open("output_data.txt");
	//myfile << "Binary Search Tree Deletion \n";
	//myfile << "Time taken by function: " << duration.count() << " milliseconds \n";
	//myfile << "\n\n";
	//myfile.close();

	//MyReadFilee.close();
	//MyReadFile.close();



	// Vector Object 

	//VectorT<int> myVec;

	// //Vector using Array Implementation Insertion
	// //Input Size: 100_000 
	// //Using STL std::chrono 
	//std::ifstream VectorInsert(file);

	//while (getline(VectorInsert, myText)) {
	//	
	//	myVec.insert(stoi(myText));
	//}

	//auto startOne = high_resolution_clock::now();

	//for (auto i = 0; i < 50001; i++) {

	//	myVec.remove();
	//}

	//auto stopOne = high_resolution_clock::now();

	//auto durationOne = duration_cast<milliseconds>(stopOne - startOne);

	//std::ofstream myfileOne;
	//myfileOne.open("output_data.txt", std::ios_base::app);
	//myfileOne << "Vector using Array Implementation Deletion \n";
	//myfileOne << "Time taken by function: " << durationOne.count() << " milliseconds \n";
	//myfileOne << "\n\n";
	//myfileOne.close();

	//VectorInsert.close();




	//// Stack Object 

	//Stack<int> myInt;

	////// Stack Using STL Queue Insertion
	////// Input Size: 100_000 
	////// Using STL std::chrono 
	//std::ifstream StackInsert(file);

	//while (getline(StackInsert, myText)) {

	//	myInt.push(stoi(myText));

	//}

	//auto startTwo = high_resolution_clock::now();

	//myInt.stackSort();

	//auto stopTwo = high_resolution_clock::now();

	//auto durationTwo = duration_cast<milliseconds>(stopTwo - startTwo);

	//StackInsert.close();

	//std::ofstream myfileTwo;
	//myfileTwo.open("output_data.txt", std::ios_base::app);
	//myfileTwo << "Stack Insertion \n";
	//myfileTwo << "Time taken by function: " << durationTwo.count() << " milliseconds \n";
	//myfileTwo << "\n\n";
	//myfileTwo.close();



}