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
		float cost = 0.0f;
	};


	class Planner
	{
	public:
		static std::vector<std::shared_ptr<Action>> Plan(
			const WorldState& startState,
			const WorldState& goalState,
			const std::vector<std::shared_ptr<Action>>& actions
		);

	private:
		static bool MatchesGoal(const WorldState& currentState, const WorldState& goalState);
	};
}

