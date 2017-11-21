//
//  test.cpp
//  algorithms. stack and queue implementations. stack with get_min()
//
//  Created by alifar on 11/20/17.
//  Copyright © 2017 alifar. All rights reserved.
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "special_stack.hpp"
#include <iostream>

TEST_CASE("Special Stack Push and Min"){
  StackWithMin stack;
  stack.Push(5);
  REQUIRE(stack.get_min() == 5);
  stack.Push(10);
  REQUIRE(stack.get_min() == 5);
  stack.Push(3);
  REQUIRE(stack.get_min() == 3);
}

TEST_CASE("Special Stack Pop and Min"){
  StackWithMin stack;
  stack.Push(5);
  stack.Push(10);
  stack.Push(3);
  REQUIRE(stack.get_min() == 3);
  stack.Pop();
  REQUIRE(stack.get_min() == 5);
  stack.Pop();
  REQUIRE(stack.get_min() == 5);
}
