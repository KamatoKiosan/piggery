#define DOCTEST_CONFIG_IMPLEMENT
#include "../include/doctest.h"
#include "../include/piggery.hpp"
#include "../include/category.hpp"
#include <iostream>
#include "../include/sqlite_modern_cpp.h"

using namespace std;

void createTestData(sqlite::database& db, Category& treeRootNode) {
    Category category1{db, "Category1"};
    category1.setPerMille(500);
    Category category11{db, "Category11"};
    category11.setPerMille(500);
    Piggybank piggybank111{db, "Piggybank111"};
    piggybank111.setPerMille(500);
    category11.addPiggybank(piggybank111);
    Piggybank piggybank112{db, "Piggybank112"};
    piggybank112.setPerMille(500);
    category11.addPiggybank(piggybank112);
    category1.addSubcategory(category11);
    Category category12{db, "Category12"};
    category12.setPerMille(500);
    Piggybank piggybank121{db, "Piggybank121"};
    piggybank121.setPerMille(500);
    category12.addPiggybank(piggybank121);
    Piggybank piggybank122{db, "Piggybank122"};
    piggybank122.setPerMille(500);
    category12.addPiggybank(piggybank122);
    category1.addSubcategory(category12);
    treeRootNode.addSubcategory(category1);

    Category category2{db, "Category2"};
    category2.setPerMille(500);
    Category category21{db, "Category21"};
    category21.setPerMille(500);
    Piggybank piggybank211{db, "Piggybank211"};
    piggybank211.setPerMille(500);
    category21.addPiggybank(piggybank211);
    Piggybank piggybank212{db, "Piggybank212"};
    piggybank212.setPerMille(500);
    category21.addPiggybank(piggybank212);
    category2.addSubcategory(category21);
    Category category22{db, "Category22"};
    category22.setPerMille(500);
    Piggybank piggybank221{db, "Piggybank221"};
    piggybank221.setPerMille(500);
    category22.addPiggybank(piggybank221);
    Piggybank piggybank222{db, "Piggybank222"};
    piggybank222.setPerMille(500);
    category22.addPiggybank(piggybank222);
    category2.addSubcategory(category22);
    treeRootNode.addSubcategory(category2);
}

int main() 
{
    sqlite::database db{"piggery.db"};
    piggery::Piggery piggery{db};

    /*
    piggery.testJson();
    */

    Category treeRootNode = piggery.getTreeRootNode();

    /*
    createTestData(db, treeRootNode);
    */

    unsigned int perMilleSum = piggery.calculatePerMilleSum(treeRootNode);
    cout << "perMilleSum: " << perMilleSum << endl << endl;

    // Distribute some money
    /*
    piggery.distributeAmountInCents(treeRootNode, 10000);
    */

    // Setting the remark of an piggybank.
    /*
    Piggybank piggybank{db, 1};
    piggybank.setRemark("Remark of piggybank1");
    */

    // Retrieve money from a piggybank.
    /*
    Piggybank piggybank{db, 1};
    piggybank.debitAmountInCents(100);
    */

    piggery.createPictureOfTree(treeRootNode);

    return 0;
}
