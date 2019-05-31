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
        const std::string getName() const;
        void setPerMille(const int perMille);
        const int getPerMille() const;
        void setBalanceInCents(const int balanceInCents);
        void addBalanceInCents(const int balanceInCents);
        const int getBalanceInCents() const;
        void setGoalInCents(const int goalInCents);
        const int getGoalInCents() const;
        void setRemark(const std::string remark);
        const std::string getRemark() const;

    private:
        sqlite::database db;
        int rowId;
        std::string name;
        int perMille;
        int balanceInCents;
        int goalInCents;
        std::string remark;
};

