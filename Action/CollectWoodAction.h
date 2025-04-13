#pragma once
#include "Action.h"

namespace GOAP
{
    class CollectWoodAction : public Action
    {
    public:
        CollectWoodAction(const std::string& name = "CollectWood", float cost = 1.0f) : Action(name, cost) {}

        bool ArePreconditionsSatisfied(const WorldState& state) const override;
        void ApplyEffects(WorldState& state) const override;
    };
}

