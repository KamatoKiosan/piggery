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
//    CHECK(piggery.toString() == "Test1");
}

// DOCTEST_SYMBOL_EXPORT void from_dll();   // to silence "-Wmissing-declarations" with GCC
// DOCTEST_SYMBOL_EXPORT void from_dll() {} // force the creation of a .lib file with MSVC
