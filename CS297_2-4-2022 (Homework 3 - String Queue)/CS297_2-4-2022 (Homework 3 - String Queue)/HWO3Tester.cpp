
#include <queue>
#include <iostream> 
#include <vector>
#include "StringQueue.h" 
#include "StringTokens.h"




int main() {
    
    std::string text = "As she said these words her foot slipped, and in another "
       "moment, splash!she was up to her chin in salt water. Her first idea was that she "
        "had somehow fallen into the sea, and in that case I can go back by railway, she "
        "said to herself.";

    std::cout << "First String: " << text << "\n\n\n"; 

    std::vector<std::string> tokens = split(text, " ");



   std::cout << "The number of instances of she/She in the text is : " << wordInstance(tokens, "she") << "\n";
   std::cout << "The number of instances of her/Her in the text is : " << wordInstance(tokens, "Her") << "\n";

    std::cout << "\n\n";

    std::string text2 = "The dog The cat The wolf The bear The cat loves to play with other cat";

    std::cout << "Second String: " << text2 << "\n\n\n";

    std::vector<std::string> tokens2 = split(text2, " ");

    std::cout << "The number of instances of cat/Cat in the text is : " << wordInstance(tokens2, "cat") << "\n";
    std::cout << "The number of instances of the/The in the text is : " << wordInstance(tokens2, "the") << "\n";
    

    std::cout << "\n\n\n";

    std::queue<std::string> tokenQueue;

    std::queue<std::string> emptyQueue;

    for (auto i = 0; i < tokens.size(); i++) {

        tokenQueue.push(tokens[i]);

    }

    std::cout << "First Queue Has: " << tokenQueue.size() << " elements before QueueMultiRemove" << "\n";
    std::cout << "Removing 37 element from queue" << "\n";
    QueueMultiRemove(tokenQueue, 37);
    std::cout << "First Queue Has: " << tokenQueue.size() << " elements after QueueMultiRemove" << "\n";

    std::cout << "\n";

    std::cout << "First Queue Has: " << tokenQueue.size() << " elements before QueueMultiRemove" << "\n";
    std::cout << "Removing 10 element from queue" << "\n";
    QueueMultiRemove(tokenQueue, 10);
    std::cout << "First Queue Has: " << tokenQueue.size() << " elements after QueueMultiRemove" << "\n";

    std::cout << "\n\n\n";

    std::cout << "Second Queue Has: " << emptyQueue.size() << " elements before QueueMultiRemove" << "\n";
    std::cout << "Removing 20 element from queue" << "\n";
    QueueMultiRemove(emptyQueue, 20);
    std::cout << "Second Queue Has: " << emptyQueue.size() << " elements after QueueMultiRemove" << "\n";


}