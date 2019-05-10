#include "../include/doctest.h"
#include <iostream>
#include "../include/nlohmann/json.hpp"
#include <vector>
#include "../include/piggery.hpp"
#include "../include/category.hpp"

namespace piggery {

using namespace std;
using json = nlohmann::json;

Piggery::Piggery(): treeRootNode{Category{"Root"}} {}

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


void Piggery::distributeMoney(Category& category, const int cents, const float superpercentage) {
    for (Category& subcategory : category.getSubcategories()) {
        cout << endl;
        cout << "Category name: " << subcategory.getName() << endl;
        cout << "Category percentage: " << subcategory.getPercentage() << endl;
        cout << "Category percentage accumulated: " << superpercentage * subcategory.getPercentage() << endl;

        for (Piggybank& piggybank : subcategory.getPiggybanks()) {
            cout << "Piggybank name: " << piggybank.getName() << endl;
            cout << "Piggybank percentage: " << piggybank.getPercentage() << endl;
            cout << "Piggybank percentage accumulated: " << superpercentage * subcategory.getPercentage() * piggybank.getPercentage() << endl;
            cout << "This piggybank gets " << cents * superpercentage * subcategory.getPercentage() * piggybank.getPercentage() / 100  << " credits" << endl;
        }
        distributeMoney(subcategory, cents, superpercentage * subcategory.getPercentage());
    }
}

float Piggery::calculatePercentageSum(Category& category, const float superpercentage) {
    float piggybanksPercentageSum = 0.0f;
    float subPercentage = 0.0f;
    for (Category& subcategory : category.getSubcategories()) {
        cout << endl;
        cout << "Category name: " << subcategory.getName() << endl;
        cout << "Category percentage: " << subcategory.getPercentage() << endl;
        cout << "Category percentage accumulated: " << superpercentage * subcategory.getPercentage() << endl;

        for (Piggybank& piggybank : subcategory.getPiggybanks()) {
            cout << "Piggybank name: " << piggybank.getName() << endl;
            cout << "Piggybank percentage: " << piggybank.getPercentage() << endl;
            cout << "Piggybank percentage accumulated: " << superpercentage * subcategory.getPercentage() * piggybank.getPercentage() << endl;
            piggybanksPercentageSum += superpercentage * subcategory.getPercentage() * piggybank.getPercentage();
        }
        subPercentage += calculatePercentageSum(subcategory, superpercentage * subcategory.getPercentage());
    }
    float percentage = piggybanksPercentageSum + subPercentage;
    return percentage;
}

}

TEST_CASE("test") {
    piggery::Piggery piggery;
    CHECK(piggery.toString() == "Test");
//    CHECK(piggery.toString() == "Test1");
}

TEST_CASE("instantiate") {
    piggery::Piggery piggery;

    SUBCASE("no categories") {
        CHECK(piggery.getTreeRootNode().getName() == "Root");
        CHECK(piggery.getTreeRootNode().getSubcategories().size() == 0);
    }
}

