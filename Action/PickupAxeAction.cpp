#include "PickupAxeAction.h"

namespace GOAP
{
	bool PickupAxeAction::ArePreconditionsSatisfied(const WorldState& state) const
	{
		return state.GetValue<bool>("HasAxe") == false;
	}

	void PickupAxeAction::ApplyEffects(WorldState& state) const
	{
		state.Set("HasAxe", true);
	}
}
