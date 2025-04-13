#pragma once
#include "Action.h"

namespace GOAP
{
    class PickupAxeAction : public Action
    {
    public:
        PickupAxeAction(const std::string& name = "PickupAxe", float cost = 1.0f) : Action(name, cost) {}

        bool ArePreconditionsSatisfied(const WorldState& state) const override;
        void ApplyEffects(WorldState& state) const override;
    };
}

