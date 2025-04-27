#pragma once
#include "Action.h"

namespace GOAP
{
    class BuildHouseAction : public Action
    {
    public:
        BuildHouseAction(const std::string& name = "BuildHouse", float cost = 4.0f) : Action(name, cost) {}

        bool ArePreconditionsSatisfied(const WorldState& state) const override;
        void ApplyEffects(WorldState& state) const override;
    };
}

