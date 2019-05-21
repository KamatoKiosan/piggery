#pragma once
#include <vector>
#include <string>
#include "piggybank.hpp"

class Category
{
    public:
        Category(std::string name);

        const std::string getName() const;
        void setPerMill(const unsigned int perMill);
        const unsigned int getPerMill() const;
        void addSubcategory(const Category&);
        std::vector<Category>& getSubcategories();
        void addPiggybank(const Piggybank&);
        std::vector<Piggybank>& getPiggybanks();

    private:
        std::string name;
        unsigned int perMill;
        std::vector<Category> subcategories;
        std::vector<Piggybank> piggybanks;
};
