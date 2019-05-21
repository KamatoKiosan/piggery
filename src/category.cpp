#include "../include/category.hpp"
#include "../include/piggybank.hpp"
#include <iostream>

Category::Category(std::string name): name{name}, perMill{1000}, subcategories{}, piggybanks{} {}

const std::string Category::getName() const {
    return name;
}

void Category::setPerMill(const unsigned int myPerMill) {
    perMill = myPerMill;
}

const unsigned int Category::getPerMill() const {
    return perMill;
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
