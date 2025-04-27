#pragma once
#include "Action.h"

namespace GOAP
{
    class BuyHouseAction : public Action
    {
    public:
        BuyHouseAction(const std::string& name = "BuyHouse", float cost = 1.0f) : Action(name, cost) {}

        bool ArePreconditionsSatisfied(const WorldState& state) const override;
        void ApplyEffects(WorldState& state) const override;
    };
}

