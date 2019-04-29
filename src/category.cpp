#include "../include/category.hpp"

Category::Category(std::string name): name{name}, subcategories{}, percentage{0.0f}, cents{0} {}


const std::string Category::getName() const {
    return name;
}

const std::vector<Category> Category::getSubcategories() const {
    return subcategories;
}

const float Category::getPercentage() const {
    return percentage;
}

const int Category::getCents() const {
    return cents;
}
