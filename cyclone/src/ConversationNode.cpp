#include "ConversationNode.h"
#include "ConversationOption.h"

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
	option->CreateOption(line);

	conversation_options_.push_back(option);
	return option->GetId();
}

void ConversationNode::Print() {

	std::cout << line_ << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < conversation_options_.size(); i++) {
		std::cout << "    [" << i + 1 << "] " << conversation_options_[i]->GetLine() << std::endl;
	}
}

ConversationNode* ConversationNode::RegisterChoice(int choice) {

	if (choice < 1 || choice >= conversation_options_.size())
		return nullptr;

	return conversation_options_[choice - 1]->GetNextNode();
}

ConversationNode::~ConversationNode() {
	for (auto& o : conversation_options_)
		delete o;
}


