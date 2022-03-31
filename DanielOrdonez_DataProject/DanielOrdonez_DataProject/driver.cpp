#include <iostream>
#include <queue>
#include <string>
#include <iostream>
#include "StackQ.cpp"
#include <fstream>
#include <chrono>
using namespace std::chrono;

int main() {

	Stack<std::string> mystr;

	std::string myText;
	long long count=0; 
	// Read from the text file
	std::ifstream MyReadFile("001_Data_Set_Zipcode_5_Digit.txt");

	auto start = high_resolution_clock::now();
	// Use a while loop together with the getline() function to read the file line by line
	while (getline(MyReadFile, myText)) {
		// Output the text from the file
		mystr.push(myText);

	}

	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<microseconds>(stop - start);

	std::cout << "Time taken by function: "
		<< duration.count() << " microseconds" << "\n";
	
	// Close the file
	MyReadFile.close();




}