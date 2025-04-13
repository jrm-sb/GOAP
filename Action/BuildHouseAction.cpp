#include "BuildHouseAction.h"

namespace GOAP
{
	bool BuildHouseAction::ArePreconditionsSatisfied(const WorldState& state) const
	{
		return state.GetValue<bool>("HasWood") == true;
	}

	void BuildHouseAction::ApplyEffects(WorldState& state) const
	{
		state.Set("HasHouse", true);
	}
}