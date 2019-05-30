#pragma once
#include <vector>
#include <string>
#include "piggybank.hpp"
#include "sqlite_modern_cpp.h"

class Category
{
    public:
        Category(sqlite::database& db, std::string name);
        Category(sqlite::database& db);
        Category(sqlite::database& db, const int rowId);

        void init();
        const int getRowId() const;
        void setName(const std::string name);
        const std::string getName() const;
        void setPerMille(const unsigned int perMille);
        const unsigned int getPerMille() const;
        void addSubcategory(const Category&);
        void removeSubcategory(const Category&);
        std::vector<Category>& getSubcategories();
        void addPiggybank(const Piggybank&);
        std::vector<Piggybank>& getPiggybanks();
        friend std::ostream &operator<<( std::ostream &output, const Category &category);
        //Category& operator= (const Category &) = default;

    private:
        sqlite::database db;
        int rowId;
        std::string name;
        int perMille;
        std::vector<Category> subcategories;
        std::vector<Piggybank> piggybanks;
};
