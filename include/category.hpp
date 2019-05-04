#pragma once
#include <vector>
#include <string>
#include "piggybank.hpp"

class Category
{
    public:
        Category(std::string name);

        const std::string getName() const;
        const std::vector<Category> getSubcategories() const;
        const float getPercentage() const;
        const Piggybank getPiggybank() const;

    private:
        std::string name;
        std::vector<Category> subcategories;
        float percentage;
        Piggybank piggybank;
};
