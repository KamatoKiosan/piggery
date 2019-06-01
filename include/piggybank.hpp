#pragma once
#include <vector>
#include <string>
#include "sqlite_modern_cpp.h"

class Piggybank
{
    public:
        Piggybank(sqlite::database& db, const std::string name);
        Piggybank(sqlite::database& db, const int rowId);

        const int getRowId() const;
        void setName(const std::string name);
        const std::string getName();
        void setPerMille(const int perMille);
        const int getPerMille();
        void setBalanceInCents(const int balanceInCents);
        void addAmountInCents(const int amountInCents);
        void debitAmountInCents(const int amountInCents);
        const int getBalanceInCents();
        void setGoalInCents(const int goalInCents);
        const int getGoalInCents();
        void setRemark(const std::string remark);
        const std::string getRemark();

    private:
        sqlite::database db;
        int rowId;
};

