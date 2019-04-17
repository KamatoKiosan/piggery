#include <iostream>
#include <nlohmann/json.hpp>
#include "doctest.h"
#include "piggery.hpp"

namespace piggery {

using namespace std;
using json = nlohmann::json;

Piggery::Piggery()
{

}

const string Piggery::toString()
{
	return "Test";
}

void Piggery::testJson()
{
    json j;
    j["pi"] = 3.141;
    j["happy"] = true;
    j["name"] = "Niels";
    j["nothing"] = nullptr;
    j["answer"]["everything"] = 42;
    j["list"] = {1, 0, 2};
    j["object"] = { {"currency", "USD"}, {"value", 42.99} };
    cout << j.dump(4) << endl;
}

}

TEST_CASE("test") {
    piggery::Piggery piggery;
    CHECK(piggery.toString() == "Test");
//    CHECK(piggery.toString() == "Test1");
}

// DOCTEST_SYMBOL_EXPORT void from_dll();   // to silence "-Wmissing-declarations" with GCC
// DOCTEST_SYMBOL_EXPORT void from_dll() {} // force the creation of a .lib file with MSVC
