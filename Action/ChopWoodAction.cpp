#include "ChopWoodAction.h"

namespace GOAP
{
	bool ChopWoodAction::ArePreconditionsSatisfied(const WorldState& state) const
	{
		return state.GetValue<bool>("HasAxe") == true;
	}

	void ChopWoodAction::ApplyEffects(WorldState& state) const
	{
		state.Set("HasChoppedWood", true);
	}
}