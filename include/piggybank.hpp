#pragma once
#include <vector>
#include <string>

class Piggybank
{
    public:
        Piggybank(const std::string name);
        Piggybank();

        const std::string getName() const;
        void setPerMill(const unsigned int perMill);
        const unsigned int getPerMill() const;
        const int getBalanceInCents() const;
        const int getGoalInCents() const;
        const std::string getRemark() const;

    private:
        std::string name;
        unsigned int perMill;
        int balanceInCents;
        int goalInCents;
        std::string remark;
};

