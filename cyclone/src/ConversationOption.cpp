#include "ConversationOption.h"
#include "ConversationNode.h"

using namespace Cyclone;

ConversationOption::ConversationOption() :
	next_node_(nullptr) {
}

GUID ConversationOption::GetId() const {
	return id_;
}

void ConversationOption::CreateOption(std::string line) {
	GUID g;
	CoCreateGuid(&g);
	id_ = g;
	line_ = line;
}

std::string ConversationOption::GetLine() const {
	return line_;
}

ConversationNode* ConversationOption::GetNextNode() const {
	return next_node_;
}

void ConversationOption::SetLine(std::string value) {
	line_ = value;
}

void ConversationOption::SetNextNode(ConversationNode* value) {
	next_node_ = value;
}

ConversationOption::~ConversationOption() {
	if (next_node_) delete next_node_;
}