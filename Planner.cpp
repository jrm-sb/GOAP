#include "Planner.h"
#include "WorldState.h"
#include <queue>
#include <unordered_set>

namespace GOAP
{
    std::vector<std::shared_ptr<Action>> Planner::Plan(const WorldState& startState, const WorldState& goalState, const std::vector<std::shared_ptr<Action>>& actions)
    {
        std::priority_queue<Node, std::vector<Node>, CompareNodes> openSet;

        // Used to keep an history of the visited states to avoid cycles
        std::unordered_set<std::string> visitedStates;

        openSet.push({ startState.GetStates(), {}, 0.0f, Heuristic(startState, goalState)});

        while (!openSet.empty())
        {
            Node currentNode = openSet.top();
            openSet.pop();

            if (currentNode.state.MatchesGoal(goalState))
                return currentNode.plan;

            const std::string& currentHash = Utils::HashString(currentNode.state);
            visitedStates.insert(currentHash);

            for (const std::shared_ptr<Action>& action : actions)
            {
                WorldState tempState = currentNode.state;
                if (action->Execute(tempState))
                {
                    const std::string& hashStr = Utils::HashString(tempState);
                    if (visitedStates.find(hashStr) != visitedStates.end())
                        continue;

                    float newG = currentNode.gCost + action->GetCost();
                    float newH = Heuristic(tempState, goalState);

                    std::vector<std::shared_ptr<Action>> newPlan = currentNode.plan;
                    newPlan.push_back(action);

                    openSet.push({ tempState, newPlan, newG, newH });
                }
            }
        }

        return {};
    }
}
