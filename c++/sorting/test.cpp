//
//  test.cpp
//  algorithms. sorting. implementations
//
//  Created by alifar on 23/07/17.
//  Copyright © 2017 alifar. All rights reserved.
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "sorting.hpp"
#include <iostream>

TEST_CASE("Empty vector sort"){
  const std::vector<int> items{};
  std::vector<int> result;

  result = selection_sort(items);
  REQUIRE(result == items);

  result = insertion_sort(items);
  REQUIRE(result == items);
}

TEST_CASE("Ascending Ordered vector sort"){
  const std::vector<int> items{1, 3, 5, 6, 9, 18};
  std::vector<int> result;

  result = selection_sort(items);
  REQUIRE(result == items);

  result = insertion_sort(items);
  REQUIRE(result == items);
}

TEST_CASE("Descending Ordered vector sort ascendingly"){
  const std::vector<int> items{18, 9, 6, 5, 3, 1};
  std::vector<int> sorted_items(items);
  std::sort(sorted_items.begin(), sorted_items.end());
  std::vector<int> result;

  result = selection_sort(items);
  REQUIRE(result == sorted_items);

  result = insertion_sort(items);
  REQUIRE(result == sorted_items);
}

TEST_CASE("Random vector sort ascendingly"){
  const std::vector<int> items{24, 33, 1, 55, 67, 9, 12, 2, 45};
  std::vector<int> sorted_items(items);
  std::sort(sorted_items.begin(), sorted_items.end());
  std::vector<int> result;

  result = selection_sort(items);
  REQUIRE(result == sorted_items);

  result = insertion_sort(items);
  REQUIRE(result == sorted_items);
}
