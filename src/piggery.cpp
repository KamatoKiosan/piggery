#include "doctest.h"
#include "piggery.hpp"

namespace piggery {

using namespace std;

Piggery::Piggery()
{

}

const string Piggery::toString()
{
	return "Test";
}

}

TEST_CASE("test") {
    piggery::Piggery piggery;
    CHECK(piggery.toString() == "Test");
    CHECK(piggery.toString() == "Test1");
}
  
