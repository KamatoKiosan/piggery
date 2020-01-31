#pragma once
#include <vector>
#include <string>
#include "sqlite_modern_cpp.h"

class Piggybank
{
    public:
        Piggybank(sqlite::database& db, const std::string name);
        Piggybank(sqlite::database& db, const int rowId);

        int getRowId() const;
        void setName(const std::string name);
        const std::string getName();
        void setPerMille(const int perMille);
        int getPerMille();
        void setBalanceInCents(const int balanceInCents);
        void addAmountInCents(const int amountInCents);
        void debitAmountInCents(const int amountInCents);
        int getBalanceInCents();
        void setGoalInCents(const int goalInCents);
        int getGoalInCents();
        void setRemark(const std::string remark);
        const std::string getRemark();
        void erase();

    private:
        sqlite::database db;
        int rowId;
};

