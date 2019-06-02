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
        const std::string getName();
        void setPerMille(const unsigned int perMille);
        const unsigned int getPerMille();
        void addSubcategory(const Category&);
        void removeSubcategory(const Category&);
        std::vector<Category> getSubcategories();
        void addPiggybank(const Piggybank&);
        std::vector<Piggybank> getPiggybanks();
        void erase();
        //friend std::ostream &operator<<( std::ostream &output, const Category &category);

    private:
        sqlite::database db;
        int rowId;
};
