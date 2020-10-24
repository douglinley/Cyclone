#pragma once

#include "ConversationNode.h"
#include "ConversationOption.h"

namespace Cyclone {

	class ConversationGraph {
	private:
		ConversationNode* conversation_node_;
		
	public:
		ConversationGraph();

		~ConversationGraph();
				
		void InitGraph();
	
		void TriggerDialog();

		void SetConversationNode(ConversationNode* conversation_node);

		// bool SaveTreeState();

		ConversationNode* GetConversationNode() const {
			return conversation_node_;
		}
	};
}