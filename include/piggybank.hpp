#pragma once
#include <vector>
#include <string>
#include "sqlite_modern_cpp.h"

class Piggybank
{
    public:
        Piggybank(sqlite::database& db, const std::string name);
        //Piggybank();

        const std::string getName() const;
        void setPerMille(const unsigned int perMille);
        const unsigned int getPerMille() const;
        const int getBalanceInCents() const;
        const int getGoalInCents() const;
        const std::string getRemark() const;

    private:
        sqlite::database& db;
        std::string name;
        unsigned int perMille;
        int balanceInCents;
        int goalInCents;
        std::string remark;
};

