#include "pairs.hpp"
#include <iostream>
#include <vector>

int main(int argc, const char * argv[]) {
	// TEST: Pairs of the same diff: pairs.hpp
	std::cout << "==== Pairs of the Same Difference ====" << std::endl;
   int diff = 2;
   std::vector<int> arr = {1,5,3,4,2};
   std::cout << pairs(arr, diff) << std::endl;
}