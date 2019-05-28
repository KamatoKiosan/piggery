#include "../include/doctest.h"
#include <iostream>
#include "../include/nlohmann/json.hpp"
#include <vector>
#include "../include/piggery.hpp"
#include "../include/category.hpp"
#include "../include/piggybank.hpp"

namespace piggery {

using namespace std;
using json = nlohmann::json;

Piggery::Piggery(sqlite::database& db): db{db}, treeRootNode{Category{db, "Root"}} {
    db <<
        "CREATE TABLE IF NOT EXISTS category ("
        "rowid INTEGER PRIMARY KEY, "
        "name TEXT NOT NULL, "
        "perMille INTEGER NOT NULL, "
        "parentCategoryId INTEGER"
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


void Piggery::distributeMoney(Category& category, const unsigned int cents, const unsigned int superPerMille) {
    for (Category& subcategory : category.getSubcategories()) {
        cout << endl;
        cout << "Category name: " << subcategory.getName() << endl;
        cout << "Category perMille: " << subcategory.getPerMille() << endl;
        cout << "Category perMille accumulated: " << superPerMille * subcategory.getPerMille() / 1000 << endl;

        for (Piggybank& piggybank : subcategory.getPiggybanks()) {
            cout << "Piggybank name: " << piggybank.getName() << endl;
            cout << "Piggybank perMille: " << piggybank.getPerMille() << endl;
            cout << "Piggybank perMille accumulated: " << superPerMille * subcategory.getPerMille() / 1000 * piggybank.getPerMille() / 1000 << endl;
            // cout << "cents: " << cents << " superPerMille: " << superPerMille << " subcategory.getPerMille: " << subcategory.getPerMille() << " piggybank.getPerMille: " << piggybank.getPerMille() << endl;
            cout << "This piggybank gets " << cents * superPerMille / 1000 * subcategory.getPerMille() / 1000 * piggybank.getPerMille() / 1000 << " cents" << endl;
        }
        distributeMoney(subcategory, cents, superPerMille * subcategory.getPerMille() / 1000);
    }
}

unsigned int Piggery::calculatePerMilleSum(Category& category, const unsigned int superPerMille) {
    unsigned int piggybanksPerMilleSum = 0;
    unsigned int subPerMille = 0;
    for (Category& subcategory : category.getSubcategories()) {
        cout << endl;
        cout << "Category name: " << subcategory.getName() << endl;
        cout << "Category perMille: " << subcategory.getPerMille() << endl;
        cout << "Category perMille accumulated: " << superPerMille * subcategory.getPerMille() / 1000 << endl;

        for (Piggybank& piggybank : subcategory.getPiggybanks()) {
            cout << "Piggybank name: " << piggybank.getName() << endl;
            cout << "Piggybank perMille: " << piggybank.getPerMille() << endl;
            cout << "Piggybank perMille accumulated: " << superPerMille * subcategory.getPerMille() / 1000 * piggybank.getPerMille() / 1000 << endl;
            piggybanksPerMilleSum += superPerMille * subcategory.getPerMille() / 1000 * piggybank.getPerMille() / 1000; 
        }
        subPerMille += calculatePerMilleSum(subcategory, superPerMille * subcategory.getPerMille() / 1000);
    }
    unsigned int perMille = piggybanksPerMilleSum + subPerMille;
    return perMille;
}

}

TEST_CASE("test") {
    sqlite::database db{":MEMORY:"};
    piggery::Piggery piggery{db};
    CHECK(piggery.toString() == "Test");
//    CHECK(piggery.toString() == "Test1");
}

TEST_CASE("instantiate") {
    sqlite::database db{":MEMORY:"};
    piggery::Piggery piggery{db};

    SUBCASE("no categories") {
        CHECK(piggery.getTreeRootNode().getName() == "Root");
        CHECK(piggery.getTreeRootNode().getSubcategories().size() == 0);
    }
}

