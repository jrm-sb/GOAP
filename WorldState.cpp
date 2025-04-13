#include "WorldState.h"

namespace GOAP
{
	bool WorldState::MatchesGoal(const WorldState& goalState) const
	{
		for (const auto& [key, value] : goalState.GetStates())
		{
			auto it = m_States.find(key);
			if (it == m_States.end() || it->second != value)
				return false;
		}
		return true;
	}
}
