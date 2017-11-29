//
//  test.cpp
//  algorithms. Binary Min Heap. Implementation
//
//  Created by alifar on 11/27/17.
//  Copyright © 2017 alifar. All rights reserved.
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "min_heap.hpp"

TEST_CASE("Binary Min Heap"){
  MinHeap heap;
  std::vector<int> array{4, 2, 5, 1, 6, 8, 24, 55, 13, 29, 30, 3};
  for(auto it: array){
    heap.Insert(it);
  }
  REQUIRE(heap.GetMin() == 1);
  heap.PopMin();
  REQUIRE(heap.GetMin() == 2);
  heap.PopMin();
  REQUIRE(heap.GetMin() == 3);
  heap.PopMin();
  REQUIRE(heap.GetMin() == 4);
  heap.PopMin();
  REQUIRE(heap.GetMin() == 5);
  heap.PopMin();
  REQUIRE(heap.GetMin() == 6);
  heap.PopMin();
  REQUIRE(heap.GetMin() == 8);
  heap.PopMin();
  REQUIRE(heap.GetMin() == 13);
  heap.PopMin();
  REQUIRE(heap.GetMin() == 24);
  heap.PopMin();
  REQUIRE(heap.GetMin() == 29);
  heap.PopMin();
  REQUIRE(heap.GetMin() == 30);
  heap.PopMin();
  REQUIRE(heap.GetMin() == 55);
}
