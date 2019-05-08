#pragma once
#include <string>
#include <vector>
#include "category.hpp" 

namespace piggery {

class Piggery {

public:
	Piggery();

	const std::string toString();
    void testJson(void);
    Category& getTreeRootNode();

private:
    Category treeRootNode;
};
}
