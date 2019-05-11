#define DOCTEST_CONFIG_IMPLEMENT
#include "../include/doctest.h"
#include "../include/piggery.hpp"
#include "../include/category.hpp"
#include <iostream>

using namespace std;

int main() 
{
    piggery::Piggery piggery{"test.db"};
    std::cout << piggery.toString() << std::endl;
    //piggery.testJson();

    Category treeRootNode = piggery.getTreeRootNode();

    Category category1{"Category1"};
    category1.setPercentage(0.5f);
    Category category11{"Category11"};
    category11.setPercentage(0.5f);
    Piggybank piggybank111{"Piggybank111"};
    piggybank111.setPercentage(0.5f);
    category11.addPiggybank(piggybank111);
    Piggybank piggybank112{"Piggybank112"};
    piggybank112.setPercentage(0.5f);
    category11.addPiggybank(piggybank112);
    category1.addSubcategory(category11);
    Category category12{"Category12"};
    category12.setPercentage(0.5f);
    Piggybank piggybank121{"Piggybank121"};
    piggybank121.setPercentage(0.5f);
    category12.addPiggybank(piggybank121);
    Piggybank piggybank122{"Piggybank122"};
    piggybank122.setPercentage(0.5f);
    category12.addPiggybank(piggybank122);
    category1.addSubcategory(category12);
    treeRootNode.addSubcategory(category1);

    Category category2{"Category2"};
    category2.setPercentage(0.5f);
    Category category21{"Category21"};
    category21.setPercentage(0.5f);
    Piggybank piggybank211{"Piggybank211"};
    piggybank211.setPercentage(0.5f);
    category21.addPiggybank(piggybank211);
    Piggybank piggybank212{"Piggybank212"};
    piggybank212.setPercentage(0.5f);
    category21.addPiggybank(piggybank212);
    category2.addSubcategory(category21);
    Category category22{"Category22"};
    category22.setPercentage(0.5f);
    Piggybank piggybank221{"Piggybank221"};
    piggybank221.setPercentage(0.5f);
    category22.addPiggybank(piggybank221);
    Piggybank piggybank222{"Piggybank222"};
    piggybank222.setPercentage(0.5f);
    category22.addPiggybank(piggybank222);
    category2.addSubcategory(category22);
    treeRootNode.addSubcategory(category2);


    float percentageSum = piggery.calculatePercentageSum(treeRootNode);
    cout << "percentageSum: " << percentageSum << endl << endl;
    piggery.distributeMoney(treeRootNode, 100*100);

    return 0;
}
