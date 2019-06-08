#pragma once
#include <vector>
#include <string>
#include "sqlite_modern_cpp.h"

class Account
{
    public:
        Account(sqlite::database& db, const std::string name);
        Account(sqlite::database& db, const int rowId);

        const int getRowId() const;
        void setName(const std::string name);
        const std::string getName();
        const int getBalanceInCents();
        void erase();

    private:
        sqlite::database db;
        int rowId;
};

