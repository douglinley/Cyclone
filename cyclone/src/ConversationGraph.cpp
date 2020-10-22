#include "ConversationGraph.h"

using namespace Cyclone;

ConversationGraph::ConversationGraph() {
	// lets set up some test nodes
	InitGraph();
}

void ConversationGraph::InitGraph() {
	ConversationNode* node = new ConversationNode();

	node->Init("This is the root node for testing");
	node->AddConversationOption("This is option 1.");
	node->AddConversationOption("This is option 2.");
	node->AddConversationOption("This is option 3.");
	node->AddConversationOption("This is option 4.");

	conversation_nodes_.push_back(node);
}

void ConversationGraph::TriggerDialog() {
	if (!conversation_nodes_.empty())
		conversation_nodes_[0]->Print();
}

void ConversationGraph::DestroyGraph() {
	for (auto& n : conversation_nodes_)
		delete n;
}

ConversationGraph::~ConversationGraph() {
}

