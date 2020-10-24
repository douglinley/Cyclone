#include "ConversationGraph.h"

using namespace Cyclone;

ConversationGraph::ConversationGraph() {
	conversation_node_ = nullptr;

	// lets set up some test nodes
	InitGraph();
}

void ConversationGraph::InitGraph() {
	ConversationNode* node0 = new ConversationNode();
	ConversationNode* node1 = new ConversationNode();
	ConversationNode* node2 = new ConversationNode();
	ConversationNode* node3 = new ConversationNode();
	ConversationNode* node4 = new ConversationNode();

	node0->Init("This is node0 for testing");
	node0->AddConversationOption("This node0 is option 1.");
	node0->AddConversationOption("This node0 is option 2.");
	node0->AddConversationOption("This node0 is option 3.");
	node0->AddConversationOption("This node0 is option 4.");

	node1->Init("This is node1 for testing");
	node1->AddConversationOption("This node1 is option 1.");
	node1->AddConversationOption("This node1 is option 2.");
	node1->AddConversationOption("This node1 is option 3.");

	node2->Init("This is node2 for testing");
	node2->AddConversationOption("This node2 is option 1.");
	node2->AddConversationOption("This node2 is option 2.");
	node2->AddConversationOption("This node2 is option 3.");

	node3->Init("This is node3 for testing");
	node3->AddConversationOption("This node3 is option 1.");
	node3->AddConversationOption("This node3 is option 2.");

	node4->Init("This is node4 for testing");
	node4->AddConversationOption("This node4 is option 1.");

	node0->conversation_options_[0]->SetNextNode(node1);
	node0->conversation_options_[1]->SetNextNode(node2);
	node0->conversation_options_[2]->SetNextNode(node3);
	node0->conversation_options_[3]->SetNextNode(node3);

	conversation_node_ = node0;
}

void ConversationGraph::TriggerDialog() {
	if(conversation_node_)
		conversation_node_->Print();
}

void ConversationGraph::SetConversationNode(ConversationNode* conversation_node) {
	conversation_node_ = conversation_node;
}

ConversationGraph::~ConversationGraph() {
	delete conversation_node_;
}
