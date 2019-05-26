#pragma once
#include <vector>
#include <string>

class Piggybank
{
    public:
        Piggybank(const std::string name);
        Piggybank();

        const std::string getName() const;
        void setPerMille(const unsigned int perMille);
        const unsigned int getPerMille() const;
        const int getBalanceInCents() const;
        const int getGoalInCents() const;
        const std::string getRemark() const;

    private:
        std::string name;
        unsigned int perMille;
        int balanceInCents;
        int goalInCents;
        std::string remark;
};

