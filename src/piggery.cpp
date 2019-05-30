#include "../include/doctest.h"
#include <fstream>
#include <iostream>
#include "../include/nlohmann/json.hpp"
#include <vector>
#include "../include/piggery.hpp"
#include "../include/category.hpp"
#include "../include/piggybank.hpp"

namespace piggery {

using namespace std;
using json = nlohmann::json;

Piggery::Piggery(sqlite::database& db): db{db}, treeRootNode{Category{db}} {
    db <<
        "CREATE TABLE IF NOT EXISTS category ("
        "rowid INTEGER PRIMARY KEY, "
        "name TEXT NOT NULL, "
        "perMille INTEGER DEFAULT 0, "
        "parentCategoryId INTEGER DEFAULT 0"
        ");";
    db <<
        "CREATE TABLE IF NOT EXISTS piggybank ("
        "rowid INTEGER PRIMARY KEY, "
        "name TEXT NOT NULL, "
        "perMille INTEGER DEFAULT 0, "
        "balanceInCents INTEGER DEFAULT 0, "
        "goalInCents INTEGER DEFAULT 0, "
        "remark TEXT DEFAULT '', "
        "categoryId INTEGER DEFAULT 0"
        ");";
    db <<
        "CREATE INDEX IF NOT EXISTS idx_piggybank_categoryId"
        " ON piggybank (categoryId);";
    int count = 0;
    db <<
        "SELECT COUNT(*) FROM category WHERE rowid = 1;" >> count;
    if (count == 0) {
        db <<
            "INSERT INTO category (name, perMille, parentCategoryId) "
            "VALUES (?, ?, ?);"
            << "Root"
            << 1000
            << NULL;
    }
    db <<
        "SELECT name, perMille FROM category WHERE rowid = 1;"
        >> [&](std::string name, int perMille) {
            treeRootNode.setName(name);
            treeRootNode.setPerMille(perMille);
            std::cout << treeRootNode << std::endl;
        };
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

void Piggery::createPictureOfTree(Category& category) {
    const string outfileName{"graph.dot"};
    ofstream outfile;
    outfile.open(outfileName);
    createPictureOfTreeHeader(outfile);
    createPictureOfTreeBody(outfile, category);
    createPictureOfTreeFooter(outfile);
    outfile.close();
    // TODO: DRY
    system("dot -Tpdf graph.dot -o out.pdf");
}

void Piggery::createPictureOfTreeHeader(ofstream& outfile) {
    outfile << "digraph g {" << endl;
    outfile << "graph [" << endl;
    outfile << "rankdir = \"LR\"" << endl;
    outfile << "];" << endl;
    outfile << "node [" << endl;
    outfile << "shape = \"record\"" << endl;
    outfile << "];" << endl;
    outfile << "nodeCategory1[label = \"<f0> Category 1 | Input | 100%\"];" << endl;
}

void Piggery::createPictureOfTreeBody(ofstream& outfile, Category& category, const unsigned int superPerMille) {
    for (Category& subcategory : category.getSubcategories()) {
        outfile << "nodeCategory" << subcategory.getRowId();
        outfile << "[label = \"";
        outfile << "<f0> Category ID " << subcategory.getRowId();
        outfile << " | ";
        outfile << "Name: " << subcategory.getName();
        outfile << " | ";
        outfile << "Share: " << subcategory.getPerMille() / 10.0 << '%';
        outfile << " | ";
        outfile << "Accumulated share: " << superPerMille * subcategory.getPerMille() / 10000.0 << '%';
        outfile << "\"];";
        outfile << endl;
        outfile << "\"nodeCategory" << category.getRowId();
        outfile << "\":f0 -> \"nodeCategory" << subcategory.getRowId() << "\":f0" << endl;

        for (Piggybank& piggybank : subcategory.getPiggybanks()) {
            outfile << "nodePiggybank" << piggybank.getRowId();
            outfile << "[label = \"";
            outfile << "<f0> Piggybank ID " << piggybank.getRowId();
            outfile << " | ";
            outfile << "Name: " << piggybank.getName();
            outfile << " | ";
            outfile << "Share: " << piggybank.getPerMille() / 10.0 << '%';
            outfile << " | ";
            outfile << "Accumulated share: " << superPerMille * subcategory.getPerMille() / 1000.0 * piggybank.getPerMille() / 10000.0 << '%';
            outfile << " | ";
            outfile << "Balance: " << piggybank.getBalanceInCents() / 10.0 << "€";
            outfile << " | ";
            outfile << "Goal: " << piggybank.getGoalInCents() / 10.0 << "€";
            outfile << " | ";
            outfile << "Remark: " << piggybank.getRemark();
            outfile << "\"];";
            outfile << endl;
            outfile << "\"nodeCategory" << subcategory.getRowId();
            outfile << "\":f0 -> \"nodePiggybank" << piggybank.getRowId() << "\":f0" << endl;
        }
        createPictureOfTreeBody(outfile, subcategory, superPerMille * subcategory.getPerMille() / 1000);
    }
}

void Piggery::createPictureOfTreeFooter(ofstream& outfile) {
    outfile << "}" << endl;
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

