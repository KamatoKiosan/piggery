#pragma once
#include <vector>
#include <string>

class Piggybank
{
    public:
        Piggybank();

        const std::string getName() const;
        const int getBalanceInCents() const;
        const int getGoalInCents() const;
        const std::string getRemark() const;

    private:
        std::string name;
        int balanceInCents;
        int goalInCents;
        std::string remark;
};

