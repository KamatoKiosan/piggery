#include "../include/account.hpp"

Account::Account(sqlite::database& db, const std::string name): db{db} {
    db << "INSERT INTO account (name) VALUES (?);"
       << name;
    rowId = db.last_insert_rowid();
}
  
Account::Account(sqlite::database& db, const int rowId): db{db}, rowId{rowId} {}

const int Account::getRowId() const {
    return rowId;
}

void Account::setName(const std::string name) {
    db << "UPDATE account SET name = ? WHERE rowid = ?;"
       << name
       << rowId;
}

const std::string Account::getName() {
    std::string name;
    db << "SELECT name FROM account WHERE rowid = ?;"
       << rowId
       >> name;
    return name;
}

void Account::addPiggybank(const Piggybank& piggybank) {
    db << "UPDATE piggybank SET accountId = ? WHERE rowid = ?;"
       << rowId
       << piggybank.getRowId();
}

std::vector<Piggybank> Account::getPiggybanks() {
    std::vector<Piggybank> piggybanks; 
    db << "SELECT rowid FROM piggybank WHERE accountId = ?;"
       << rowId
       >> [&](int rowId) {
           Piggybank piggybank{db, rowId};
           piggybanks.push_back(piggybank);
       };
    return piggybanks;
}

void Account::removePiggybank(const Piggybank& piggybank) {
    db << "UPDATE piggybank SET accountId = 0 WHERE rowid = ?;"
       << piggybank.getRowId();
}

const int Account::getBalanceInCents() {
    int sumBalanceInCents = 0;
    db << "SELECT SUM(balanceInCents) FROM piggybank WHERE accountId = ?;"
       << rowId
       >> sumBalanceInCents;
    return sumBalanceInCents;
}

void Account::erase() {
    db << "UPDATE piggybank SET accountId = 0 WHERE accountId = ?;"
       << rowId;
    db << "DELETE FROM account WHERE rowid = ?;"
       << rowId;
}
