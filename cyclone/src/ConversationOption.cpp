#include "ConversationOption.h";

using namespace Cyclone;

ConversationOption::ConversationOption() :
	next_node_(nullptr),
	id_(-1) {
}


GUID ConversationOption::GetId() const {
	return id_;
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