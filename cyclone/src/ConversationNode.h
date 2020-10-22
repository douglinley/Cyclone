#pragma once

#include <string>
#include <iostream>
#include <vector>

namespace Cyclone {

	struct ConversationOption {
		std::string text;
		ConversationNode* next_node;
	};

	class ConversationNode {
	private:
		std::string text_;
	public:
		std::vector<ConversationOption*> conversation_options_;

		std::string GetText() const {
			return text_;
		}
	};
}
