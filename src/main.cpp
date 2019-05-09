#define DOCTEST_CONFIG_IMPLEMENT
#include "../include/doctest.h"
#include "../include/piggery.hpp"
#include "../include/category.hpp"
#include <iostream>

using namespace std;

void traverseSubcategories(Category& category, float superpercentage) {
    for (Category& subcategory : category.getSubcategories()) {
        cout << endl;
        cout << "Category name: " << subcategory.getName() << endl;
        cout << "Category percentage: " << subcategory.getPercentage() << endl;
        cout << "Category percentage accumulated: " << superpercentage * subcategory.getPercentage() << endl;

        for (Piggybank& piggybank : subcategory.getPiggybanks()) {
            cout << "Piggybank name: " << piggybank.getName() << endl;
            cout << "Piggybank percentage: " << piggybank.getPercentage() << endl;
            cout << "Piggybank percentage accumulated: " << superpercentage * subcategory.getPercentage() * piggybank.getPercentage() << endl;
        }
        traverseSubcategories(subcategory, superpercentage * subcategory.getPercentage());
    }
}

int main() 
{
    piggery::Piggery piggery;
    std::cout << piggery.toString() << std::endl;
    //piggery.testJson();

    Category treeRootNode = piggery.getTreeRootNode();
    Category category1{"Category1"};
    category1.setPercentage(0.5f);
    Category category11{"Category11"};
    category11.setPercentage(0.5f);
    Piggybank piggybank11{"Piggybank11"};
    piggybank11.setPercentage(1.0f);
    category11.addPiggybank(piggybank11);
    category1.addSubcategory(category11);
    Category category12{"Category12"};
    category12.setPercentage(0.5f);
    category1.addSubcategory(category12);
    treeRootNode.addSubcategory(category1);

    Category category2{"Category2"};
    category2.setPercentage(0.5f);
    Category category21{"Category21"};
    category21.setPercentage(0.5f);
    category2.addSubcategory(category21);
    Category category22{"Category22"};
    category22.setPercentage(0.5f);
    category2.addSubcategory(category22);
    treeRootNode.addSubcategory(category2);

    traverseSubcategories(treeRootNode, 1.0f);

    return 0;
}
