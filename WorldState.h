#pragma once
#include <optional>
#include <string>
#include <unordered_map>

namespace GOAP
{
	class WorldState
	{
	public:
        WorldState(const std::unordered_map<std::string, bool>& states) : m_States(states) {}

        template<typename T>
        std::optional<T> GetValue(const std::string& key) const
        {
            auto it = m_States.find(key);
            if (it != m_States.end())
                return it->second;
            return std::nullopt;
        }

        void Set(const std::string& key, bool value)
        {
            m_States[key] = value;
        }

        void Remove(const std::string& key)
        {
            m_States.erase(key);
        }

        const std::unordered_map<std::string, bool>& GetStates() const { return m_States; }

    private:
        std::unordered_map<std::string, bool> m_States;
	};
}

