#include "../include/piggybank.hpp"

Piggybank::Piggybank(const std::string name): name{name}, perMill{1000}, balanceInCents{0}, goalInCents{0}, remark{} {}
Piggybank::Piggybank(): Piggybank("") {}

const std::string Piggybank::getName() const {
    return name;
}

void Piggybank::setPerMill(const unsigned int myPerMill) {
    perMill = myPerMill;
}

const unsigned int Piggybank::getPerMill() const {
    return perMill;
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

