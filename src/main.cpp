#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "piggery.hpp"
#include "category.hpp"
#include <iostream>

int main() 
{
    piggery::Piggery piggery;
    std::cout << piggery.toString() << std::endl;
    piggery.testJson();

    const Category treeRoot = piggery.getTreeRootNode();

    return 0;
}
