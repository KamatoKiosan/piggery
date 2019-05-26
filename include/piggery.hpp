#pragma once
#include <string>
#include <vector>
#include "category.hpp" 
#include <stdio.h>
#include "../include/sqlite_modern_cpp.h"

namespace piggery {

class Piggery {

public:
	Piggery(const std::string& sqlite3Filepath);
    ~Piggery();

	const std::string toString();
    void testJson(void);
    Category& getTreeRootNode();
    void distributeMoney(Category& category, const unsigned int cents, const unsigned int superPerMille = 1000);
    unsigned int calculatePerMilleSum(Category& category, const unsigned int superPerMille = 1000);
    Category createCategory(const std::string name);

private:
    Category treeRootNode;
    sqlite::database db;
};
}
