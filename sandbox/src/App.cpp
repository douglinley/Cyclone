#include <iostream>

#include "ConversationGraph.h";

using namespace Cyclone;

int main() {
	std::cout << "Hello, from Cyclone, a Directed Graph Conversation System from Confused Chicken Games." << std::endl;
	std::cout << std::endl << std::endl;

	ConversationGraph graph;
	graph.InitGraph();
	graph.TriggerDialog();

	std::cin.get();

	graph.DestroyGraph();
}

