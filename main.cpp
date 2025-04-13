#include <iostream>
#include <memory>
#include <vector>

#include "Action/Action.h"
#include "Action/BuildHouseAction.h"
#include "Action/BuyHouseAction.h"
#include "Action/ChopWoodAction.h"
#include "Action/CollectWoodAction.h"
#include "Action/PickupAxeAction.h"
#include "Planner.h"
#include "TestRunner.h"
#include "WorldState.h"

TEST(BuildHouse)
{
    std::unordered_map<std::string, bool> startState =
    {
        { "HasAxe", false }
    };

    std::unordered_map<std::string, bool> goalState =
    {
        { "HasHouse", true }
    };

    std::vector<std::shared_ptr<GOAP::Action>> actions =
    {
        std::make_shared<GOAP::PickupAxeAction>(),
        std::make_shared<GOAP::BuildHouseAction>(),
        std::make_shared<GOAP::ChopWoodAction>(),
        std::make_shared<GOAP::CollectWoodAction>()
    };

    const std::vector<std::shared_ptr<GOAP::Action>> plan = GOAP::Planner::Plan(startState, goalState, actions);

    EXPECT(plan.size() == 4);
    EXPECT(plan[0]->GetName() == "PickupAxe");
    EXPECT(plan[1]->GetName() == "ChopWood");
    EXPECT(plan[2]->GetName() == "CollectWood");
    EXPECT(plan[3]->GetName() == "BuildHouse");
}

TEST(NoAvailablePlan)
{
    std::unordered_map<std::string, bool> startState =
    {
        { "HasAxe", false }
    };

    std::unordered_map<std::string, bool> goalState =
    {
        { "HasHouse", true }
    };

    std::vector<std::shared_ptr<GOAP::Action>> actions =
    {
        std::make_shared<GOAP::CollectWoodAction>(),
        std::make_shared<GOAP::BuildHouseAction>()
    };

    const std::vector<std::shared_ptr<GOAP::Action>> plan = GOAP::Planner::Plan(startState, goalState, actions);

    EXPECT(plan.size() == 0);
}

TEST(BuyHouse)
{
    std::unordered_map<std::string, bool> startState =
    {
        { "HasMoney", true }
    };

    std::unordered_map<std::string, bool> goalState =
    {
        { "HasHouse", true }
    };

    std::vector<std::shared_ptr<GOAP::Action>> actions =
    {
        std::make_shared<GOAP::BuyHouseAction>()
    };

    const std::vector<std::shared_ptr<GOAP::Action>> plan = GOAP::Planner::Plan(startState, goalState, actions);

    EXPECT(plan.size() == 1);
}

TEST(BuildOrBuyHouse)
{
    std::unordered_map<std::string, bool> startState =
    {
        { "HasWood", true },
        { "HasMoney", true },
    };

    std::unordered_map<std::string, bool> goalState =
    {
        { "HasHouse", true }
    };

    std::vector<std::shared_ptr<GOAP::Action>> actions =
    {
        std::make_shared<GOAP::BuildHouseAction>(),
        std::make_shared<GOAP::BuyHouseAction>()
    };

    const std::vector<std::shared_ptr<GOAP::Action>> plan = GOAP::Planner::Plan(startState, goalState, actions);

    EXPECT(plan.size() == 1);
    EXPECT(plan[0]->GetName() == "BuildHouse");
}

int main()
{
    Test::RunAllTests();
}
