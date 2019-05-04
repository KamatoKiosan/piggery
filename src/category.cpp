#include "../include/category.hpp"

Category::Category(std::string name): name{name}, subcategories{}, percentage{0.0f} {}

const std::string Category::getName() const {
    return name;
}

const std::vector<Category> Category::getSubcategories() const {
    return subcategories;
}

const float Category::getPercentage() const {
    return percentage;
}

const Piggybank Category::getPiggybank() const {
    return piggybank;
}
