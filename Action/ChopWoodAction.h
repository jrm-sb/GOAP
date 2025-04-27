#pragma once
#include "Action.h"

namespace GOAP
{
    class ChopWoodAction : public Action
    {
    public:
        ChopWoodAction(const std::string& name = "ChopWood", float cost = 4.0f) : Action(name, cost) {}

        bool ArePreconditionsSatisfied(const WorldState& state) const override;
        void ApplyEffects(WorldState& state) const override;
    };
}

