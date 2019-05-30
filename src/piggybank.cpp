#include "../include/piggybank.hpp"

Piggybank::Piggybank(sqlite::database& db, const std::string name): db{db}, name{name}, perMille{1000}, balanceInCents{0}, goalInCents{0}, remark{} {
    db << "INSERT INTO piggybank (name, perMille) VALUES (?,?);"
       << name
       << perMille;
    rowId = db.last_insert_rowid();
}
  
const int Piggybank::getRowId() const {
    return rowId;
}

void Piggybank::setName(const std::string newName) {
    db << "UPDATE piggybank SET name = ? WHERE rowid = ?;"
       << newName
       << rowId;
    name = newName;
}

const std::string Piggybank::getName() const {
    return name;
}

void Piggybank::setPerMille(const int newPerMille) {
    db << "UPDATE piggybank SET perMille = ? WHERE rowid = ?;"
       << newPerMille
       << rowId;
    perMille = newPerMille;
}

const int Piggybank::getPerMille() const {
    return perMille;
}

void Piggybank::setBalanceInCents(const int newBalanceInCents) {
    db << "UPDATE piggybank SET balanceInCents = ? WHERE rowid = ?;"
       << newBalanceInCents
       << rowId;
    balanceInCents = newBalanceInCents;
}

const int Piggybank::getBalanceInCents() const {
    return balanceInCents;
}

void Piggybank::setGoalInCents(const int newGoalInCents) {
    db << "UPDATE piggybank SET goalInCents = ? WHERE rowid = ?;"
       << newGoalInCents
       << rowId;
    goalInCents = newGoalInCents;
}

const int Piggybank::getGoalInCents() const {
    return goalInCents;
}

void Piggybank::setRemark(const std::string newRemark) {
    db << "UPDATE piggybank SET remark = ? WHERE rowid = ?;"
       << newRemark
       << rowId;
    remark = newRemark;
}

const std::string Piggybank::getRemark() const {
    return remark;
}

