#pragma once
#include <vector>
#include <string>

class Piggybank
{
    public:
        Piggybank(const std::string name);
        Piggybank();

        const std::string getName() const;
        void setPercentage(const float percent);
        const float getPercentage() const;
        const int getBalanceInCents() const;
        const int getGoalInCents() const;
        const std::string getRemark() const;

    private:
        std::string name;
        float percentage;
        int balanceInCents;
        int goalInCents;
        std::string remark;
};

