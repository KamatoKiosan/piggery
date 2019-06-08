#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <stdio.h>
#include "category.hpp" 
#include "account.hpp" 
#include "../include/sqlite_modern_cpp.h"

namespace piggery {

class Piggery {

public:
	Piggery(sqlite::database& db);
    ~Piggery();

    void testJson(void);
    Category& getTreeRootNode();
    void distributeAmountInCents(Category& category, const int amountInCents, const unsigned int superPerMille = 1000);
    void createPictureOfTree(Category& category);
    void createPictureOfAccounts();
    void calculatePerMilleSum(Category& category, const int level = 0) const;
    std::vector<Account> getAccounts();

private:
    sqlite::database db;
    Category treeRootNode;
    void createPictureOfTreeHeader(std::ofstream& outfile);
    void createPictureOfTreeBody(std::ofstream& outfile, Category& category, const unsigned int superPerMille = 1000);
    void createPictureOfTreeFooter(std::ofstream& outfile);
};
}
