#include "../include/category.hpp"
#include "../include/piggybank.hpp"
#include <iostream>
#include "../include/sqlite_modern_cpp.h"

Category::Category(sqlite::database& db, std::string name): db{db} {
    db << "INSERT INTO category (name) VALUES (?);"
       << name;
    rowId = db.last_insert_rowid();
}

Category::Category(sqlite::database& db): db{db}, rowId{1} {}

Category::Category(sqlite::database& db, const int rowId): db{db}, rowId{rowId} {}

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
}

void Category::removeSubcategory(const Category& category) {
    db << "UPDATE category SET parentCategoryId = 0 WHERE rowid = ?;"
       << category.getRowId();
}

std::vector<Category> Category::getSubcategories() {
    std::vector<Category> categories; 
    db << "SELECT rowid FROM category WHERE parentCategoryId = ?;"
       << rowId
       >> [&](int rowId) {
           Category category{db, rowId};
           categories.push_back(category);
       };
    return categories;
}

void Category::addPiggybank(const Piggybank& piggybank) {
    db << "UPDATE piggybank SET categoryId = ? WHERE rowid = ?;"
       << rowId
       << piggybank.getRowId();
}

std::vector<Piggybank> Category::getPiggybanks() {
    std::vector<Piggybank> piggybanks; 
    db << "SELECT rowid FROM piggybank WHERE categoryId = ?;"
       << rowId
       >> [&](int rowId) {
           Piggybank piggybank{db, rowId};
           piggybanks.push_back(piggybank);
       };
    return piggybanks;
}

void Category::removePiggybank(const Piggybank& piggybank) {
    db << "UPDATE piggybank SET categoryId = 0 WHERE rowid = ?;"
       << piggybank.getRowId();
}

void Category::erase() {
    db << "UPDATE piggybank SET categoryId = 0 WHERE categoryId = ?;"
       << rowId;
    db << "UPDATE category SET parentCategoryId = 0 WHERE parentCategoryId = ?;"
       << rowId;
    db << "DELETE FROM category WHERE rowid = ?;"
       << rowId;
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

