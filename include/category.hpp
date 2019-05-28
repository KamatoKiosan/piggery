#pragma once
#include <vector>
#include <string>
#include "piggybank.hpp"
#include "sqlite_modern_cpp.h"

class Category
{
    public:
        Category(sqlite::database& db, std::string name);

        const std::string getName() const;
        void setRowid(const int newRowid);
        const int getRowid() const;
        void setPerMille(const unsigned int perMille);
        const unsigned int getPerMille() const;
        void addSubcategory(const Category&);
        std::vector<Category>& getSubcategories();
        void addPiggybank(const Piggybank&);
        std::vector<Piggybank>& getPiggybanks();

    private:
        sqlite::database& db;
        int rowid;
        std::string name;
        int perMille;
        std::vector<Category> subcategories;
        std::vector<Piggybank> piggybanks;
};
