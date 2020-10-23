#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <windows.h>

#include "ConversationOption.h"

namespace Cyclone {
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

		ConversationNode* RegisterChoice(int choice);
	};
}
