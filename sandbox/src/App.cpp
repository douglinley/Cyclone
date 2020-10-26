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


		if (!conversation.IsValidInput(input)) {
			std::cout << "Input is not valid" << std::endl;
			continue;
		}

		conversation.Run(input);
		if (conversation.IsOver()) break;

		std::cout << conversation.GetConversationNode()->GetLine() << std::endl << std::endl;
		std::cout << "What do you want to do?" << std::endl;
		for (int i = 0; i < conversation.GetConversationNode()->conversation_options_.size(); i++) {
				std::cout << "[" << i + 1 << "]  " << conversation.GetConversationNode()->conversation_options_[i]->GetLine() << std::endl;
		}
	}

	std::cout << "Conversation has ended." << std::endl;
	std::cin.get();
}

