#define DOCTEST_CONFIG_IMPLEMENT
#include "../include/doctest.h"
#include "../include/piggery.hpp"
#include "../include/category.hpp"
#include <iostream>
#include "../include/sqlite_modern_cpp.h"

using namespace std;

int main() 
{
    sqlite::database db{"database.db"};
    piggery::Piggery piggery{db};
    std::cout << piggery.toString() << std::endl;
    //piggery.testJson();

    Category treeRootNode = piggery.getTreeRootNode();

    //unsigned int perMilleSum = piggery.calculatePerMilleSum(treeRootNode);
    //cout << "perMilleSum: " << perMilleSum << endl << endl;

    //piggery.distributeMoney(treeRootNode, 100*100);

    piggery.createPictureOfTree(treeRootNode);

    return 0;
}
