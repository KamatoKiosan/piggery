#pragma once
#include <vector>
#include <string>
#include "piggybank.hpp"

class Category
{
    public:
        Category(std::string name);

        const std::string getName() const;
        std::vector<Category>& getSubcategories();
        const float getPercentage() const;
        const Piggybank getPiggybank() const;
        void addSubcategory(const Category);

    private:
        std::string name;
        std::vector<Category> subcategories;
        float percentage;
        Piggybank piggybank;
};
