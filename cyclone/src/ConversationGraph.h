#pragma once

#include "ConversationNode.h"

#include <vector>

namespace Cyclone {

	class ConversationGraph {
	private:
		std::vector<ConversationNode*> conversation_nodes_;
		
	public:
		ConversationGraph();
		~ConversationGraph();
				
		void InitGraph();
		void DestroyGraph();
	
		void TriggerDialog();

		// bool SaveTreeState();
	};
}