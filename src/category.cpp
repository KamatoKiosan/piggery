#include "../include/category.hpp"
#include "../include/piggybank.hpp"
#include <iostream>
#include "../include/sqlite_modern_cpp.h"

Category::Category(std::string name): name{name}, perMille{1000}, subcategories{}, piggybanks{} {}

void Category::setRowid(const int newRowid) {
    rowid = newRowid;
}

const int Category::getRowid() const {
    return rowid;
}

const std::string Category::getName() const {
    return name;
}

void Category::setPerMille(const unsigned int myPerMille) {
    perMille = myPerMille;
}

const unsigned int Category::getPerMille() const {
    return perMille;
}

void Category::addSubcategory(const Category& category) {
    subcategories.push_back(category);
}

std::vector<Category>& Category::getSubcategories() {
    return subcategories;
}

void Category::addPiggybank(const Piggybank& piggybank) {
    piggybanks.push_back(piggybank);
}

std::vector<Piggybank>& Category::getPiggybanks() {
    return piggybanks;
}
