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

const std::string Piggybank::getName() const {
    return name;
}

void Piggybank::setPerMille(const unsigned int newPerMille) {
    perMille = newPerMille;
    db << "UPDATE piggybank SET perMille = ? WHERE rowid = ?;"
       << newPerMille
       << rowId;
}

const unsigned int Piggybank::getPerMille() const {
    return perMille;
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

