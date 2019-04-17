#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "piggery.hpp"
#include <iostream>

int main() 
{
    piggery::Piggery piggery;
    std::cout << piggery.toString() << std::endl;
    piggery.testJson();
    return 0;
}
