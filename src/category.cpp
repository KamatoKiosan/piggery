#include "../include/category.hpp"
#include "../include/piggybank.hpp"
#include <iostream>
#include "../include/sqlite_modern_cpp.h"

Category::Category(sqlite::database& db, std::string name): db{db}, subcategories{}, piggybanks{} {
    db << "INSERT INTO category (name) VALUES (?);"
       << name;
    rowId = db.last_insert_rowid();
}

Category::Category(sqlite::database& db): db{db}, rowId{1} {}

Category::Category(sqlite::database& db, const int rowId): db{db}, rowId{rowId} {
    init();
}

void Category::init() {
    db <<
        "SELECT rowid FROM category WHERE parentCategoryId = ?;"
        << rowId
        >> [&](int rowid) {
            Category category{db, rowid};
            subcategories.push_back(category);
        };
    db <<
        "SELECT rowid FROM piggybank WHERE categoryId = ?;"
        << rowId
        >> [&](int rowid) {
            Piggybank piggybank{db, rowid};
            piggybanks.push_back(piggybank);
        };
}

const int Category::getRowId() const {
    return rowId;
}

void Category::setName(const std::string name) {
    db << "UPDATE category SET name = ? WHERE rowid = ?;"
       << name
       << rowId;
}

const std::string Category::getName() {
    std::string name;
    db << "SELECT name FROM category WHERE rowid = ?;"
       << rowId
       >> name;
    return name;
}

void Category::setPerMille(const unsigned int perMille) {
    db << "UPDATE category SET perMille = ? WHERE rowid = ?;"
       << perMille
       << rowId;
}

const unsigned int Category::getPerMille() {
    int perMille; 
    db << "SELECT perMille FROM category WHERE rowid = ?;"
       << rowId
       >> perMille;
    return perMille;
}

void Category::addSubcategory(const Category& category) {
    db << "UPDATE category SET parentCategoryId = ? WHERE rowid = ?;"
       << rowId
       << category.getRowId();
    subcategories.push_back(category);
}

void Category::removeSubcategory(const Category& category) {
    db << "UPDATE category SET parentCategoryId = 0 WHERE rowid = ?;"
       << category.getRowId();
    int index = 0;
    for(auto const& subcategory: subcategories) {
        if (subcategory.getRowId() == category.getRowId()) {
            break;
        }
        ++index; 
    }
    subcategories.erase(subcategories.begin() + index);
}

std::vector<Category>& Category::getSubcategories() {
    return subcategories;
}

void Category::addPiggybank(const Piggybank& piggybank) {
    db << "UPDATE piggybank SET categoryId = ? WHERE rowid = ?;"
       << rowId
       << piggybank.getRowId();
    piggybanks.push_back(piggybank);
}

std::vector<Piggybank>& Category::getPiggybanks() {
    return piggybanks;
}

/*
std::ostream& operator<<(std::ostream& os, const Category& category) {
    os << "category";
    os << '(';
    os << "rowId<" << category.rowId << '>';
    os << ' ';
    os << "name<" << category.getName() << '>';
    os << ' ';
    os << "perMille<" << category.perMille << '>';
    os << ' ';
    os << "subcategories<";
    bool first = true;
    for(auto const& subcategory: category.subcategories) {
        if (!first) os << ", ";
        os << subcategory.getRowId();
        first = false;
    }
    os << '>';
    os << ' ';
    os << "piggybanks<";
    first = true;
    for(auto const& piggybank: category.piggybanks) {
        if (!first) os << ", ";
        os << piggybank.getRowId();
        first = false;
    }
    os << '>';
    os << ')';
    return os;
}
*/

