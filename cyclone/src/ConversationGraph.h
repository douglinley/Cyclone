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
				
		void Load();
	
		void Begin();

		void Run(int response);

		void SetConversationNode(ConversationNode* conversation_node);

		// bool SaveTreeState();
		bool IsOver();

		bool IsValidInput(int input);

		ConversationNode* GetConversationNode() const;	
	};
}