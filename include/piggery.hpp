#pragma once
#include <string>
#include <vector>
#include "category.hpp" 
#include <stdio.h>
#include <sqlite3.h>

namespace piggery {

class Piggery {

public:
	Piggery(const char* sqlite3Filepath);

	const std::string toString();
    void testJson(void);
    Category& getTreeRootNode();
    void distributeMoney(Category& category, const int cents, const float superpercentage = 1.0f);
    float calculatePercentageSum(Category& category, const float superpercentage = 1.0f);

private:
    Category treeRootNode;
    sqlite3 *database;
};
}
