#pragma once
#include <memory>
#include <vector>

#include "Action/Action.h"

namespace GOAP
{
	namespace Utils
	{
		inline std::string HashString(const WorldState& state)
		{
			std::string hashedString;
			for (const std::pair<std::string, bool>& p : state.GetStates())
			{
				hashedString += p.first + "=" + (p.second ? "1" : "0") + ";";
			}
			return hashedString;
		}
	}

	struct Node
	{
		WorldState state;
		std::vector<std::shared_ptr<Action>> plan;
		float gCost; // cost to reach this node
		float hCost; // estimated cost to reach the goal from this node
		float fCost() const { return gCost + hCost; }
	};

	struct CompareNodes
	{
		bool operator()(const Node& l, const Node& r) const { return l.fCost() > r.fCost(); }
	};

	class Planner
	{
	public:
		static std::vector<std::shared_ptr<Action>> Plan(
			const WorldState& startState,
			const WorldState& goalState,
			const std::vector<std::shared_ptr<Action>>& actions
		);

		static float Heuristic(const WorldState& current, const WorldState& goal)
		{
			float cost = 0.0f;
			for (const auto& [key, value] : goal.GetStates())
			{
				const auto& currentStates = current.GetStates();
				auto it = currentStates.find(key);
				if (it == currentStates.end() || it->second != value)
					cost += 1.0f;
			}
			return cost;
		}
	};
}

