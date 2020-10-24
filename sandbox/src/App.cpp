#include <iostream>

#include "ConversationGraph.h"

using namespace Cyclone;

int main() {
	int response = 0;

	std::cout << "Hello, from Cyclone, a Directed Graph Conversation System from Confused Chicken Games." << std::endl;
	std::cout << std::endl << std::endl;

	ConversationGraph graph;
	graph.InitGraph();
	graph.TriggerDialog();
		
	std::cout << std::endl << "What will you do?" << std::endl << std::endl;
	std::cin >> response;
	
	ConversationNode* new_node = graph.GetConversationNode()->RegisterChoice(response);
	graph.SetConversationNode(new_node);
	graph.TriggerDialog();

	std::cin.get();
}

