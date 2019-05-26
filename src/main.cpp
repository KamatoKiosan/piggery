#define DOCTEST_CONFIG_IMPLEMENT
#include "../include/doctest.h"
#include "../include/piggery.hpp"
#include "../include/category.hpp"
#include <iostream>

using namespace std;

int main() 
{
    piggery::Piggery piggery{"database.db"};
    std::cout << piggery.toString() << std::endl;
    //piggery.testJson();

    Category treeRootNode = piggery.getTreeRootNode();

    Category category1 = piggery.createCategory("Category1");
    category1.setPerMille(500);
    Category category11 = piggery.createCategory("Category11");
    category11.setPerMille(500);
    Piggybank piggybank111{"Piggybank111"};
    piggybank111.setPerMille(500);
    category11.addPiggybank(piggybank111);
    Piggybank piggybank112{"Piggybank112"};
    piggybank112.setPerMille(500);
    category11.addPiggybank(piggybank112);
    category1.addSubcategory(category11);
    Category category12{"Category12"};
    category12.setPerMille(500);
    Piggybank piggybank121{"Piggybank121"};
    piggybank121.setPerMille(500);
    category12.addPiggybank(piggybank121);
    Piggybank piggybank122{"Piggybank122"};
    piggybank122.setPerMille(500);
    category12.addPiggybank(piggybank122);
    category1.addSubcategory(category12);
    treeRootNode.addSubcategory(category1);

    Category category2{"Category2"};
    category2.setPerMille(500);
    Category category21{"Category21"};
    category21.setPerMille(500);
    Piggybank piggybank211{"Piggybank211"};
    piggybank211.setPerMille(500);
    category21.addPiggybank(piggybank211);
    Piggybank piggybank212{"Piggybank212"};
    piggybank212.setPerMille(500);
    category21.addPiggybank(piggybank212);
    category2.addSubcategory(category21);
    Category category22{"Category22"};
    category22.setPerMille(500);
    Piggybank piggybank221{"Piggybank221"};
    piggybank221.setPerMille(500);
    category22.addPiggybank(piggybank221);
    Piggybank piggybank222{"Piggybank222"};
    piggybank222.setPerMille(500);
    category22.addPiggybank(piggybank222);
    category2.addSubcategory(category22);
    treeRootNode.addSubcategory(category2);


    unsigned int perMilleSum = piggery.calculatePerMilleSum(treeRootNode);
    cout << "perMilleSum: " << perMilleSum << endl << endl;
    piggery.distributeMoney(treeRootNode, 100*100);

    return 0;
}
