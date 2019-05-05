#include "../include/category.hpp"

Category::Category(std::string name): name{name}, subcategories{}, percentage{0.0f} {}

const std::string Category::getName() const {
    return name;
}

std::vector<Category>& Category::getSubcategories() {
    return subcategories;
}

const float Category::getPercentage() const {
    return percentage;
}

const Piggybank Category::getPiggybank() const {
    return piggybank;
}


void Category::addSubcategory(const Category category) {
    subcategories.push_back(category);
}
