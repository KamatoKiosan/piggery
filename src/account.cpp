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

const int Account::getBalanceInCents() {
    int sumBalanceInCents = 0;
    db << "SELECT SUM(balanceInCents) FROM piggybank WHERE accountId = ?;"
       << rowId
       >> sumBalanceInCents;
    return sumBalanceInCents;
}

