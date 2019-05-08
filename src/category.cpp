#include "../include/category.hpp"
#include "../include/piggybank.hpp"
#include <iostream>

Category::Category(std::string name): name{name}, percentage{0.0f}, subcategories{}, piggybanks{} {}

const std::string Category::getName() const {
    return name;
}

const float Category::getPercentage() const {
    return percentage;
}

void Category::addSubcategory(const Category& category) {
    subcategories.push_back(category);
}

std::vector<Category>& Category::getSubcategories() {
    return subcategories;
}

void Category::addPiggybank(const Piggybank& piggybank) {
    std::cout << "addPiggybank(" << piggybank.getName() << ")" << std::endl;
    piggybanks.push_back(piggybank);
}

std::vector<Piggybank>& Category::getPiggybanks() {
    return piggybanks;
}
