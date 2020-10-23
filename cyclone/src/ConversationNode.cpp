#include "ConversationNode.h"

#include <Windows.h>

using namespace Cyclone;

GUID ConversationNode::Init(std::string line) {
	GUID g;
	HRESULT h = CoCreateGuid(&g);

	id_ = g;
	line_ = line;

	return g;
}

std::string ConversationNode::GetLine() const {
	return line_;
}

void ConversationNode::SetLine(std::string value) {
	line_ = value;
}

GUID ConversationNode::AddConversationOption(std::string line) {
	ConversationOption* option = new ConversationOption();
	GUID g;
	HRESULT h = CoCreateGuid(&g);

	option->id = g;
	option->line = line;

	conversation_options_.push_back(option);
	return option->id;
}

void ConversationNode::Print() {

	std::cout << line_ << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < conversation_options_.size(); i++) {
		std::cout << "    [" << i + 1 << "] " << conversation_options_[i]->line << std::endl;
	}
}

ConversationNode* ConversationNode::RegisterChoice(int choice) {

	if (choice < 1 || choice >= conversation_options_.size())
		return nullptr;

	return conversation_options_[choice-1]->next_node;
}

ConversationNode::~ConversationNode() {
	for (auto& o : conversation_options_)
		delete o;
}


