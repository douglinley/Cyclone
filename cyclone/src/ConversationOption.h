#pragma once
#include <windows.h>
#include <iostream>

#include "ConversationNode.h"

namespace Cyclone {

class ConversationOption {
	private:
		GUID id_;
		std::string line_;
		ConversationNode* next_node_;
	public:
		ConversationOption();
		~ConversationOption();

		GUID GetId() const;

		std::string GetLine() const;

		ConversationNode* GetNextNode() const;

		void SetLine(std::string value);

		void SetNextNode(ConversationNode* value);
	};
}