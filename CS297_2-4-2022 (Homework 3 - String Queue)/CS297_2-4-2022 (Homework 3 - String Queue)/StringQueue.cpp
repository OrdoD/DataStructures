#include <string>
#include <vector>
#include <queue>
#include <iostream>




unsigned int herWordInstance(std::vector<std::string> tokenVector, std::string target) {

	std::queue<std::string> tokenQueue;

	unsigned int foundCount = 0;

	std::string upperTarget; 

	std::string lowerTarget; 

	for (int y = 0; y < target.length(); y++) {

		target[y] = tolower(target[y]);

	}

	lowerTarget = target; 

	upperTarget = target; 

	upperTarget[0] = toupper(upperTarget[0]);


	for (auto i = 0; i < tokenVector.size(); i++) {

		tokenQueue.push(tokenVector[i]);

	}

	for (auto z = 0; z < tokenVector.size(); z++) {

		if ((tokenQueue.front() == upperTarget) || (tokenQueue.front() == lowerTarget)) {

			foundCount++;

		}
		tokenQueue.pop();
	}

	return foundCount;
}


void QueueMultiRemove(std::queue<std::string> &tokenQueue, unsigned int k) {

	if (tokenQueue.empty()) {
		std::cout << "The queue is empty" << "\n";
		return;
	}

	for (auto i = 0; i < k; i++) {
		if (!tokenQueue.empty()) {
			tokenQueue.pop();
		}
	}
	
	(tokenQueue.empty()) ? std::cout << "The queue is empty" << "\n" : std::cout << "The queue still has " << tokenQueue.size() << " elements." << "\n";

}