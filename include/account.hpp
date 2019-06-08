#pragma once
#include <vector>
#include <string>

class Account
{
    public:
        Account(std::string name);

        const std::string getName() const;
        const int getBalanceInCents() const;

    private:
        std::string name;
        int balanceInCents;
};

