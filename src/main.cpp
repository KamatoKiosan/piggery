#define DOCTEST_CONFIG_IMPLEMENT
#include "../include/doctest.h"
#include "../include/piggery.hpp"
#include "../include/category.hpp"
#include <iostream>

using namespace std;

void traverseSubcategories(Category& category) {
    for (Category& subcategory : category.getSubcategories()) {
        cout << endl;
        cout << "Category name: " << subcategory.getName() << endl;
        cout << "piggybanks.size(): " << category.getPiggybanks().size() << endl;
        for (Piggybank& piggybank : category.getPiggybanks()) {
            cout << "Hello!" << endl;
            cout << "Piggybank name: " << piggybank.getName() << endl;
        }
        traverseSubcategories(subcategory);
    }
}

int main() 
{
    piggery::Piggery piggery;
    std::cout << piggery.toString() << std::endl;
    //piggery.testJson();

    Category treeRootNode = piggery.getTreeRootNode();
    Category category1{"Category1"};
    Category category11{"Category11"};
    Piggybank piggybank11{"Piggybank11"};
    category11.addPiggybank(piggybank11);
    category1.addSubcategory(category11);
    Category category12{"Category12"};
    category1.addSubcategory(category12);
    treeRootNode.addSubcategory(category1);

    Category category2{"Category2"};
    Category category21{"Category21"};
    category2.addSubcategory(category21);
    Category category22{"Category22"};
    category2.addSubcategory(category22);
    treeRootNode.addSubcategory(category2);

    traverseSubcategories(treeRootNode);

    return 0;
}
