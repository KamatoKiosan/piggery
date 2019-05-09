#include "../include/piggybank.hpp"

Piggybank::Piggybank(const std::string name): name{name}, percentage{0.0f}, balanceInCents{0}, goalInCents{0}, remark{} {}
Piggybank::Piggybank(): Piggybank("") {}

const std::string Piggybank::getName() const {
    return name;
}

void Piggybank::setPercentage(const float percent) {
    percentage = percent;
}

const float Piggybank::getPercentage() const {
    return percentage;
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

