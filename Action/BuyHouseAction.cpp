#include "BuyHouseAction.h"

namespace GOAP
{
	bool BuyHouseAction::ArePreconditionsSatisfied(const WorldState& state) const
	{
		return state.GetValue<bool>("HasMoney") == true;
	}

	void BuyHouseAction::ApplyEffects(WorldState& state) const
	{
		state.Set("HasHouse", true);
	}
}