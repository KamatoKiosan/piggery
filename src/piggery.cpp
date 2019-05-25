#include "../include/doctest.h"
#include <iostream>
#include "../include/nlohmann/json.hpp"
#include <vector>
#include "../include/piggery.hpp"
#include "../include/category.hpp"

namespace piggery {

using namespace std;
using json = nlohmann::json;

Piggery::Piggery(const std::string& sqlite3Filepath): treeRootNode{Category{"Root"}}, db{sqlite3Filepath} {
    db <<
        "CREATE TABLE IF NOT EXISTS category ("
        "rowid INTEGER PRIMARY KEY, "
        "name TEXT NOT NULL, "
        "perMille INTEGER NOT NULL, "
        "parentCategoryId INTEGER NOT NULL"
        ");";
    db <<
        "CREATE TABLE IF NOT EXISTS piggybank ("
        "rowid INTEGER PRIMARY KEY, "
        "name TEXT NOT NULL, "
        "perMille INTEGER NOT NULL, "
        "balanceInCents INTEGER NOT NULL, "
        "goalInCents INTEGER, "
        "remark TEXT NOT NULL, "
        "categoryId INTEGER"
        ");";
    db <<
        "CREATE INDEX IF NOT EXISTS idx_piggybank_categoryId"
        " ON piggybank (categoryId);";
};

Piggery::~Piggery() {
}

const string Piggery::toString()
{
	return "Test";
}

void Piggery::testJson()
{
    json j;
    j["pi"] = 3.141;
    j["happy"] = true;
    j["name"] = "Niels";
    j["nothing"] = nullptr;
    j["answer"]["everything"] = 42;
    j["list"] = {1, 0, 2};
    j["object"] = { {"currency", "USD"}, {"value", 42.99} };
    cout << j.dump(4) << endl;
}

Category& Piggery::getTreeRootNode() {
    return treeRootNode;
}


void Piggery::distributeMoney(Category& category, const unsigned int cents, const unsigned int superPerMill) {
    for (Category& subcategory : category.getSubcategories()) {
        cout << endl;
        cout << "Category name: " << subcategory.getName() << endl;
        cout << "Category perMill: " << subcategory.getPerMill() << endl;
        cout << "Category perMill accumulated: " << superPerMill * subcategory.getPerMill() / 1000 << endl;

        for (Piggybank& piggybank : subcategory.getPiggybanks()) {
            cout << "Piggybank name: " << piggybank.getName() << endl;
            cout << "Piggybank perMill: " << piggybank.getPerMill() << endl;
            cout << "Piggybank perMill accumulated: " << superPerMill * subcategory.getPerMill() / 1000 * piggybank.getPerMill() / 1000 << endl;
            // cout << "cents: " << cents << " superPerMill: " << superPerMill << " subcategory.getPerMill: " << subcategory.getPerMill() << " piggybank.getPerMill: " << piggybank.getPerMill() << endl;
            cout << "This piggybank gets " << cents * superPerMill / 1000 * subcategory.getPerMill() / 1000 * piggybank.getPerMill() / 1000 << " cents" << endl;
        }
        distributeMoney(subcategory, cents, superPerMill * subcategory.getPerMill() / 1000);
    }
}

unsigned int Piggery::calculatePerMillSum(Category& category, const unsigned int superPerMill) {
    unsigned int piggybanksPerMillSum = 0;
    unsigned int subPerMill = 0;
    for (Category& subcategory : category.getSubcategories()) {
        cout << endl;
        cout << "Category name: " << subcategory.getName() << endl;
        cout << "Category perMill: " << subcategory.getPerMill() << endl;
        cout << "Category perMill accumulated: " << superPerMill * subcategory.getPerMill() / 1000 << endl;

        for (Piggybank& piggybank : subcategory.getPiggybanks()) {
            cout << "Piggybank name: " << piggybank.getName() << endl;
            cout << "Piggybank perMill: " << piggybank.getPerMill() << endl;
            cout << "Piggybank perMill accumulated: " << superPerMill * subcategory.getPerMill() / 1000 * piggybank.getPerMill() / 1000 << endl;
            piggybanksPerMillSum += superPerMill * subcategory.getPerMill() / 1000 * piggybank.getPerMill() / 1000; 
        }
        subPerMill += calculatePerMillSum(subcategory, superPerMill * subcategory.getPerMill() / 1000);
    }
    unsigned int perMill = piggybanksPerMillSum + subPerMill;
    return perMill;
}

}

TEST_CASE("test") {
    piggery::Piggery piggery{":MEMORY:"};
    CHECK(piggery.toString() == "Test");
//    CHECK(piggery.toString() == "Test1");
}

TEST_CASE("instantiate") {
    piggery::Piggery piggery{":MEMORY:"};

    SUBCASE("no categories") {
        CHECK(piggery.getTreeRootNode().getName() == "Root");
        CHECK(piggery.getTreeRootNode().getSubcategories().size() == 0);
    }
}

