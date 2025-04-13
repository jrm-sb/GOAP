#include "CollectWoodAction.h"

namespace GOAP
{
	bool CollectWoodAction::ArePreconditionsSatisfied(const WorldState& state) const
	{
		return state.GetValue<bool>("HasChoppedWood") == true;
	}

	void CollectWoodAction::ApplyEffects(WorldState& state) const
	{
		state.Set("HasWood", true);
	}
}