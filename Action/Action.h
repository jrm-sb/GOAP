#pragma once
#include <string>
#include <unordered_map>

#include "WorldState.h"

namespace GOAP
{
	class Action
	{
	public:
		Action(const std::string& name = "Action", float cost = 0.0f) : m_Name(name), m_Cost(cost) {}
		virtual ~Action() = default;

		virtual bool Execute(WorldState& state) const
		{
			if (ArePreconditionsSatisfied(state))
			{
				ApplyEffects(state);
				return true;
			}
			return false;
		}

		virtual bool ArePreconditionsSatisfied(const WorldState& state) const = 0;
		virtual void ApplyEffects(WorldState& state) const = 0;

		virtual std::string GetName() const { return m_Name; }
		virtual float GetCost() const { return m_Cost; }

	private:
		std::string m_Name;
		float m_Cost;
	};
}

