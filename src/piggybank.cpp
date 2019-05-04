#include "../include/piggybank.hpp"

Piggybank::Piggybank(): name{}, balanceInCents{0}, goalInCents{0}, remark{} {}

const std::string Piggybank::getName() const {
    return name;
}

const int Piggybank::getBalanceInCents() const {
    return balanceInCents;
}

const int Piggybank::getGoalInCents() const {
    return goalInCents;
}

const std::string Piggybank::getRemark() const {
    return remark;
}

