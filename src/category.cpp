#include "../include/category.hpp"
#include "../include/piggybank.hpp"
#include <iostream>
#include "../include/sqlite_modern_cpp.h"

Category::Category(sqlite::database& db, std::string name): db{db}, name{name}, perMille{1000}, subcategories{}, piggybanks{} {
    db << "INSERT INTO category (name, perMille) VALUES (?,?);"
       << name
       << perMille;
    rowId = db.last_insert_rowid();
}

Category::Category(sqlite::database& db): db{db}, rowId{1} {}

const int Category::getRowId() const {
    return rowId;
}

void Category::setName(const std::string newName) {
    db << "UPDATE category SET name = ? WHERE rowid = ?;"
       << newName
       << rowId;
    name = newName;
}

const std::string Category::getName() const {
    return name;
}

void Category::setPerMille(const unsigned int newPerMille) {
db << "UPDATE category SET perMille = ? WHERE rowid = ?;"
   << newPerMille
   << rowId;
    perMille = newPerMille;
}

const unsigned int Category::getPerMille() const {
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

std::ostream& operator<<(std::ostream& os, const Category &category) {
    os << "category";
    os << '(';
    os << "rowId<" << category.rowId << '>';
    os << ' ';
    os << "name<" << category.name << '>';
    os << ' ';
    os << "perMille<" << category.perMille << '>';
    os << ' ';
    os << "subcategories<";
    for(auto const& subcategory: category.subcategories) {
        os << subcategory.getRowId();
        os << ' ';
    }
    os << ' ';
    os << "piggybanks<";
    for(auto const& piggybank: category.piggybanks) {
        os << piggybank.getRowId();
        os << ' ';
    }
    os << '>';
    os << ')';
    return os;
}
