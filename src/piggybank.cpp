#include "../include/piggybank.hpp"

Piggybank::Piggybank(sqlite::database& db, const std::string name): db{db} {
    db << "INSERT INTO piggybank (name, perMille) VALUES (?,?);"
       << name;
    rowId = db.last_insert_rowid();
}
  
Piggybank::Piggybank(sqlite::database& db, const int rowId): db{db}, rowId{rowId} {}

const int Piggybank::getRowId() const {
    return rowId;
}

void Piggybank::setName(const std::string name) {
    db << "UPDATE piggybank SET name = ? WHERE rowid = ?;"
       << name
       << rowId;
}

const std::string Piggybank::getName() {
    std::string name;
    db << "SELECT name FROM piggybank WHERE rowid = ?;"
       << rowId
       >> name;
    return name;
}

void Piggybank::setPerMille(const int perMille) {
    db << "UPDATE piggybank SET perMille = ? WHERE rowid = ?;"
       << perMille
       << rowId;
}

const int Piggybank::getPerMille() {
    int perMille;
    db << "SELECT perMille FROM piggybank WHERE rowid = ?;"
       << rowId
       >> perMille;
    return perMille;
}

void Piggybank::setBalanceInCents(const int balanceInCents) {
    std::string name;
    db << "UPDATE piggybank SET balanceInCents = ? WHERE rowid = ?;"
       << balanceInCents
       << rowId;
    db << "SELECT name FROM piggybank WHERE rowid = ?;"
       << rowId
       >> name;
    db << "INSERT INTO log (action, piggybankId, piggybankName, amountInCents) VALUES (?, ?, ?, ?);"
       << "set"
       << rowId
       << name
       << balanceInCents;
}

void Piggybank::addAmountInCents(const int amountInCents) {
    std::string name;
    int balanceInCents;
    db << "SELECT name, balanceInCents FROM piggybank WHERE rowid = ?;"
       << rowId
       >> tie(name, balanceInCents);
    balanceInCents += amountInCents;
    db << "UPDATE piggybank SET balanceInCents = ? WHERE rowid = ?;"
       << balanceInCents
       << rowId;
    db << "INSERT INTO log (action, piggybankId, piggybankName, amountInCents) VALUES (?, ?, ?, ?);"
       << "add"
       << rowId
       << name
       << amountInCents;
}

void Piggybank::debitAmountInCents(const int amountInCents) {
    std::string name;
    int balanceInCents;
    db << "SELECT name, balanceInCents FROM piggybank WHERE rowid = ?;"
       << rowId
       >> tie(name, balanceInCents);
    balanceInCents -= amountInCents;
    db << "UPDATE piggybank SET balanceInCents = ? WHERE rowid = ?;"
       << balanceInCents
       << rowId;
    db << "INSERT INTO log (action, piggybankId, piggybankName, amountInCents) VALUES (?, ?, ?, ?);"
       << "debit"
       << rowId
       << name
       << amountInCents;
}

const int Piggybank::getBalanceInCents() {
    int balanceInCents;
    db << "SELECT balanceInCents FROM piggybank WHERE rowid = ?;"
       << rowId
       >> balanceInCents;
    return balanceInCents;
}

void Piggybank::setGoalInCents(const int goalInCents) {
    db << "UPDATE piggybank SET goalInCents = ? WHERE rowid = ?;"
       << goalInCents
       << rowId;
}

const int Piggybank::getGoalInCents() {
    int goalInCents;
    db << "SELECT goalInCents FROM piggybank WHERE rowid = ?;"
       << rowId
       >> goalInCents;
    return goalInCents;
}

void Piggybank::setRemark(const std::string remark) {
    db << "UPDATE piggybank SET remark = ? WHERE rowid = ?;"
       << remark
       << rowId;
}

const std::string Piggybank::getRemark() {
    std::string remark;
    db << "SELECT remark FROM piggybank WHERE rowid = ?;"
       << rowId
       >> remark;
    return remark;
}

void Piggybank::erase() {
    std::string name;
    int balanceInCents;
    db << "SELECT name, balanceInCents FROM piggybank WHERE rowid = ?;"
       << rowId
       >> tie(name, balanceInCents);
    db << "INSERT INTO log (action, piggybankId, piggybankName, amountInCents) VALUES (?, ?, ?, ?);"
       << "erase"
       << rowId
       << name
       << balanceInCents;
    db << "DELETE FROM piggybank WHERE rowid = ?;"
       << rowId;
}

