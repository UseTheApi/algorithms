//
//  main.cpp
//  algorithms
//
//  Created by alifar on 7/25/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "binary_search.hpp"
#include <iostream>
#include <vector>

int main(int argc, const char *argv[]){
   std::cout << "==== Binary Search =====" << std::endl;
   std::vector<int> arr = {1, 3, 6, 8, 10, 15, 20, 21, 23, 45, 47};
   std::cout << BinarySearch(arr, 15) << std::endl;
   std::cout << BinarySearch(arr, 1) << std::endl;
   std::cout << BinarySearch(arr, 55) << std::endl;

   std::vector<int> nums = {4, 6, 8, 10};

   std::cout << nums[FloorIndex(nums, 9)] << std::endl;
}