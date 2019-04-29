#pragma once
#include <vector>
#include <string>

class Category
{
    public:
        Category(std::string name);

        const std::string getName() const;
        const std::vector<Category> getSubcategories() const;
        const float getPercentage() const;
        const int getCents() const;

    private:
        std::string name;
        std::vector<Category> subcategories;
        float percentage;
        int cents;
};
