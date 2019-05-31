#include "../include/piggybank.hpp"

Piggybank::Piggybank(sqlite::database& db, const std::string name): db{db}, name{name}, perMille{1000}, balanceInCents{0}, goalInCents{0}, remark{} {
    db << "INSERT INTO piggybank (name, perMille) VALUES (?,?);"
       << name
       << perMille;
    rowId = db.last_insert_rowid();
}
  
Piggybank::Piggybank(sqlite::database& db, const int rowId): db{db}, rowId{rowId} {
    // std::cout << "Trying to get piggybank with rowid <" << rowId << ">" << std::endl;
    db <<
        "SELECT name, perMille, balanceInCents, goalInCents, remark  FROM piggybank WHERE rowid = ?;"
        << rowId
        >> [&](std::string newName, int newPerMille, int newBalanceInCents, int newGoalInCents, std::string newRemark) {
            name = newName;
            perMille = newPerMille;
            balanceInCents = newBalanceInCents;
            goalInCents = newGoalInCents;
            remark = newRemark;
        };
}

const int Piggybank::getRowId() const {
    return rowId;
}

void Piggybank::setName(const std::string newName) {
    name = newName;
    db << "UPDATE piggybank SET name = ? WHERE rowid = ?;"
       << name
       << rowId;
}

const std::string Piggybank::getName() const {
    return name;
}

void Piggybank::setPerMille(const int newPerMille) {
    perMille = newPerMille;
    db << "UPDATE piggybank SET perMille = ? WHERE rowid = ?;"
       << perMille
       << rowId;
}

const int Piggybank::getPerMille() const {
    return perMille;
}

void Piggybank::setBalanceInCents(const int newBalanceInCents) {
    balanceInCents = newBalanceInCents;
    db << "UPDATE piggybank SET balanceInCents = ? WHERE rowid = ?;"
       << balanceInCents
       << rowId;
}

void Piggybank::addBalanceInCents(const int newBalanceInCents) {
    balanceInCents += newBalanceInCents;
    db << "UPDATE piggybank SET balanceInCents = ? WHERE rowid = ?;"
       << balanceInCents
       << rowId;
}

void Piggybank::debitAmountInCents(const int amountInCents) {
    balanceInCents -= amountInCents;
    db << "UPDATE piggybank SET balanceInCents = ? WHERE rowid = ?;"
       << balanceInCents
       << rowId;
}

const int Piggybank::getBalanceInCents() const {
    return balanceInCents;
}

void Piggybank::setGoalInCents(const int newGoalInCents) {
    goalInCents = newGoalInCents;
    db << "UPDATE piggybank SET goalInCents = ? WHERE rowid = ?;"
       << goalInCents
       << rowId;
}

const int Piggybank::getGoalInCents() const {
    return goalInCents;
}

void Piggybank::setRemark(const std::string newRemark) {
    remark = newRemark;
    db << "UPDATE piggybank SET remark = ? WHERE rowid = ?;"
       << remark
       << rowId;
}

const std::string Piggybank::getRemark() const {
    return remark;
}

