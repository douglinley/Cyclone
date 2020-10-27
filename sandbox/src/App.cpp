#include <iostream>

#include "ConversationGraph.h"

using namespace Cyclone;

int main() {

	std::cout << "Hello, from Cyclone, a Directed Graph Conversation System from Confused Chicken Games." << std::endl;

	// load the scene's conversation graph
	ConversationGraph conversation;
	conversation.Load();
	
	// show the root node
	conversation.Begin();

	// cycle dialog for scene	
	while(true) {
		int input = 0;

		std::cout << "What will you do?" << std::endl;
		std::cin >> input;
		std::cout << std::endl;

		if (!conversation.IsValidInput(input)) {
			std::cout << "Input is not valid" << std::endl;
			continue;
		}

		conversation.Run(input);
		if (conversation.IsOver()) break;

		conversation.GetConversationNode()->Print();
	}

	std::cout << "Conversation has ended." << std::endl;
	std::cin.get();
}

