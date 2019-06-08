#include "../include/account.hpp"

Account::Account(std::string name): name{name}, balanceInCents{0} {}


const std::string Account::getName() const {
    return name;
}

const int Account::getBalanceInCents() const {
    return balanceInCents;
}

