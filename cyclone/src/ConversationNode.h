#pragma once


#include <string>
#include <iostream>
#include <vector>
#include <windows.h>

namespace Cyclone {
	class ConversationNode;

	struct ConversationOption {
		GUID id;
		std::string line;
		ConversationNode* next_node;
	};

	class ConversationNode {
	private:
		GUID id_;
		std::string line_;

	public:
		~ConversationNode();

		GUID Init(std::string line);

		std::vector<ConversationOption*> conversation_options_;

		std::string GetLine() const;
		
		void SetLine(std::string value);

		GUID AddConversationOption(std::string line);

		void Print();
	};
}
