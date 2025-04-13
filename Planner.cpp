#include "Planner.h"
#include "WorldState.h"
#include <queue>
#include <unordered_set>

namespace GOAP
{
    std::vector<std::shared_ptr<Action>> Planner::Plan(const WorldState& startState, const WorldState& goalState, const std::vector<std::shared_ptr<Action>>& actions)
    {
        std::queue<Node> nodesToVisit; // Used to store all possible actions that could lead to the goal
        std::unordered_set<std::string> visitedStates;

        nodesToVisit.push({ startState.GetStates(), {}, 0.0f});
        visitedStates.insert(Utils::HashString(startState.GetStates()));

        while (!nodesToVisit.empty())
        {
            Node currentNode = nodesToVisit.front();
            nodesToVisit.pop();

            if (currentNode.state.MatchesGoal(goalState))
                return currentNode.plan;

            for (const std::shared_ptr<Action>& action : actions)
            {
                WorldState tempState = currentNode.state;
                if (action->Execute(tempState))
                {
                    const std::string& hashStr = Utils::HashString(tempState);
                    if (visitedStates.find(hashStr) != visitedStates.end())
                        continue;

                    visitedStates.insert(hashStr);

                    std::vector<std::shared_ptr<Action>> newPlan = currentNode.plan;
                    newPlan.push_back(action);
                    nodesToVisit.push({ tempState, newPlan, currentNode.cost + action->GetCost() });
                }
            }
        }

        return {};
    }
}
